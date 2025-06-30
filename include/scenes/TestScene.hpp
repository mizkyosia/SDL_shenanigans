#pragma once
#include <scenes/Scene.hpp>
#include <util/Timer.hpp>

class TestScene : Scene
{
private:
    Timer _blinkTimer;
    SDL_Texture *image;

    bool _blink;

public:
    TestScene();
    ~TestScene();

    /// @brief Loads the scene into memory ()
    /// @param renderer
    void load(SDL_Renderer *renderer) override;
    /// @brief Unload the scene (and its assets if necessary)
    void unload(SDL_Renderer *renderer) override;

    void onEvent(const SDL_Event &ev) override;
    void update(const float deltaTime) override;
    void draw(SDL_Renderer *renderer) override;
};
