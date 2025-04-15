#pragma once

#include "2D/mesh2D.hpp"

using namespace mesh2D;

class Triangle2D : public Mesh2D
{
public:
    Triangle2D(GLuint shaderID, float r = 1.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f)
        : Mesh2D(
        {
            Vertex2D{ 1.0f, -0.866f, r, g, b, a},
            Vertex2D{-1.0f, -0.866f, r, g, b, a},
            Vertex2D{ 0.0f,  0.866f, r, g, b, a}
        },
        {
            0, 1, 2
        },
        shaderID
    ) {}
};
