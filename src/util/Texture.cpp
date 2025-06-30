#include "util/Texture.hpp"

Texture::Texture(const char *textureName, SDL_Renderer *renderer) : Texture(IMG_Load((Texture::TEXTURE_PATH + textureName).c_str()), renderer)
{
}

Texture::Texture(SDL_Surface *surface, SDL_Renderer *renderer)
{
    _texture = SDL_CreateTextureFromSurface(renderer, surface);
}

Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}