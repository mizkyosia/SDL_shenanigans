#include "scenes/TestScene.hpp"
#include <SDL3_image/SDL_image.h>

TestScene::TestScene() : Scene(), image(nullptr), _blinkTimer(.5f), _blink(false)
{
}

TestScene::~TestScene()
{
}

void TestScene::draw(SDL_Renderer *renderer)
{
    if (!_loaded || !_active || _blink)
        return;

    SDL_RenderTexture(renderer, image, nullptr, nullptr);
}

void TestScene::onEvent(const SDL_Event &event)
{
}

void TestScene::update(const float deltaTime)
{
    if (_blinkTimer.update(deltaTime))
        _blink = !_blink;
}

void TestScene::load(SDL_Renderer *renderer)
{
    SDL_Surface *test = IMG_Load("assets/textures/test.webp");

    image = SDL_CreateTextureFromSurface(renderer, test);
    _loaded = true;
    _active = true;
}
void TestScene::unload(SDL_Renderer *renderer)
{
}