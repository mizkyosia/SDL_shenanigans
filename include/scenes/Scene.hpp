#pragma once
#include <SDL3/SDL.h>
#include <vector>

/**
 * Template class to create a loadable scene in the
 */
class Scene
{
protected:
    bool _loaded = false, _active = false;

public:
    Scene() {};
    ~Scene() {};

    /// @brief Loads the scene into memory ()
    /// @param renderer
    virtual void load(SDL_Renderer *renderer) = 0;
    /// @brief Unload the scene (and its assets if necessary)
    virtual void unload(SDL_Renderer *renderer) = 0;

    virtual void onEvent(const SDL_Event &ev) = 0;
    virtual void update(const float deltaTime) = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;

    /**
     * Has the scene finished loading ?
     */
    bool loaded() const { return _loaded; };
    /**
     * Is the scene currently active ?
     */
    bool active() const { return _active; };
};
