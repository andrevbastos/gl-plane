#pragma once

#include "2D/mesh2D.hpp"

using namespace mesh2D;

class Square2D : public Mesh2D
{
public:
    Square2D(GLuint shaderID, float r = 1.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f)
        : Mesh2D({
            Vertex2D{ 1.0f,  1.0f, r, g, b, a},
            Vertex2D{ 1.0f, -1.0f, r, g, b, a},
            Vertex2D{-1.0f, -1.0f, r, g, b, a},
            Vertex2D{-1.0f,  1.0f, r, g, b, a},
        },
        {
            0, 1, 3,
            1, 2, 3
        },
        shaderID
    ) {}
};
