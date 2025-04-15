#pragma once

#include "3D/mesh3D.hpp"

using namespace mesh3D;

class Pyramid3D : public Mesh3D
{
public:
    Pyramid3D(GLuint shaderID, float r = 1.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f)
        : Mesh3D({
            Vertex3D{+1.0f, -1.0f, +1.0f, r, g, b, a},
            Vertex3D{+1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, +1.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, +1.0f, r, g, b, a},
            Vertex3D{+1.0f, -1.0f, +1.0f, r, g, b, a},
            Vertex3D{ 0.0f, +1.0f,  0.0f, r, g, b, a},
            Vertex3D{+1.0f, -1.0f, +1.0f, r, g, b, a},
            Vertex3D{+1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{ 0.0f, +1.0f,  0.0f, r, g, b, a},
            Vertex3D{+1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{ 0.0f, +1.0f,  0.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, +1.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{ 0.0f, +1.0f,  0.0f, r, g, b, a}
        },
        {
            0, 1, 3,
            1, 2, 3,
            4, 5, 6,
            7, 8, 9,
            10, 11, 12,
            13, 14, 15
        },
        shaderID
    ) {}
};
