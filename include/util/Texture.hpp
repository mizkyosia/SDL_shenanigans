#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <tuple>
#include <glm/glm.hpp>

#include <Rect.hpp>

class Texture
{
private:
    /// Base path for finding textures
    inline const static std::string TEXTURE_PATH = "assets/textures/";

    SDL_Texture *_texture;

public:
    Texture(const char *texture, SDL_Renderer *renderer);
    Texture(SDL_Surface *surface, SDL_Renderer *renderer);
    ~Texture();

    /* ===================== GETTERS =====================*/

    int height() const { return _texture->h; }
    int width() const { return _texture->w; }
    /**
     * Direct access to the underlying SDL_Texture* handle
     */
    SDL_Texture* texture() const { return _texture; }

    /**
     * Blend mode currently used by the texture
     */
    SDL_BlendMode blendMode() const
    {
        SDL_BlendMode m;
        SDL_GetTextureBlendMode(_texture, &m);
        return m;
    }
    /**
     * Scale mode currently used by the texture
     */
    SDL_ScaleMode scaleMode() const
    {
        SDL_ScaleMode m;
        SDL_GetTextureScaleMode(_texture, &m);
        return m;
    }

    /**
     * Fetches the color modifiers for this texture
     */
    glm::vec4 colorMods() const
    {
        glm::vec4 m;
        SDL_GetTextureAlphaModFloat(_texture, &m.a);
        SDL_GetTextureColorModFloat(_texture, &m.r, &m.g, &m.b);
        return m;
    }

    /* ===================== SETTERS =====================*/

    /**
     * Sets the texture scale mode. Default is `SDL_SCALEMODE_LINEAR`
     */
    void setScaleMode(SDL_ScaleMode mode) { SDL_SetTextureScaleMode(_texture, mode); };
    /**
     * Sets the texture's color blend mode. Default is `SDL_BLENDMODE_NONE`
     */
    void setBlendMode(SDL_BlendMode mode) { SDL_SetTextureBlendMode(_texture, mode); };
    /**
     * Sets the color modifiers for the given texture. These modifiers are represented by a vec4(r, g, b, a)
     * Final colors are calculated like so : outColor = inColor * colorMod
     */
    void setColorMods(glm::vec4 mods)
    {
        SDL_SetTextureColorModFloat(_texture, mods.r, mods.g, mods.b);
        SDL_SetTextureAlphaModFloat(_texture, mods.a);
    };
};
