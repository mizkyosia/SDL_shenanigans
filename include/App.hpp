#pragma once
#include <SDL3/SDL.h>
#include <thread>

#include "scenes/TestScene.hpp"

class App
{
private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;

    std::thread updateThread;

    TestScene _scene;

    void loop();

public:
    App(const char *title, int width, int height, Uint32 initFlags);
    ~App();

    void run();

    SDL_Renderer *const renderer() const
    {
        return _renderer;
    }

    SDL_Window *const window() const
    {
        return _window;
    }
};
