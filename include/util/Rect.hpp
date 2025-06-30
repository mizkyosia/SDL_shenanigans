#pragma once
#include <glm/glm.hpp>
#include <SDL3/SDL.h>
#include <algorithm>

/**
 * A simple rect defined by its origin (upper-left corner) & bounds
 */
struct Rect
{
    float x, y, w, h;
    Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {};
    Rect(SDL_FRect rect) : x(rect.x), y(rect.y), w(rect.w), h(rect.h) {};
    Rect(SDL_Rect rect) : x(rect.x), y(rect.y), w(rect.w), h(rect.h) {};
    Rect(glm::vec2 pointA, glm::vec2 pointB) : x(std::min(pointA.x, pointB.x)), y(std::min(pointA.y, pointB.y)), w(std::abs(pointA.x - pointB.x)), h(std::abs(pointA.y - pointB.y)) {};

    /**
     * vec2 indicating the center point of the rect
     */
    glm::vec2 center()
    {
        return {x + w / 2.f, y + h / 2.f};
    }

    /**
     * Returns this rect as an SDL Float Rect
     */
    SDL_FRect toSDLFRect()
    {
        return SDL_FRect{.h = h, .w = w, .x = x, .y = y};
    }
};
