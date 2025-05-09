#pragma once

#include "3D/mesh3D.hpp"

using namespace mesh3D;

class Cube3D : public Mesh3D
{
public:
    Cube3D(GLuint shaderID, float r = 1.0f, float g = 0.0f, float b = 0.0f, float a = 1.0f)
    : Mesh3D(
        {
            Vertex3D{+1.0f, +1.0f, +1.0f, r, g, b, a},
            Vertex3D{+1.0f, -1.0f, +1.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, +1.0f, r, g, b, a},
            Vertex3D{-1.0f, +1.0f, +1.0f, r, g, b, a},
            Vertex3D{+1.0f, +1.0f, -1.0f, r, g, b, a},
            Vertex3D{+1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{-1.0f, +1.0f, -1.0f, r, g, b, a},
            Vertex3D{-1.0f, +1.0f, +1.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, +1.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{-1.0f, +1.0f, -1.0f, r, g, b, a},
            Vertex3D{+1.0f, -1.0f, +1.0f, r, g, b, a},
            Vertex3D{+1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{+1.0f, +1.0f, -1.0f, r, g, b, a},
            Vertex3D{+1.0f, +1.0f, +1.0f, r, g, b, a},
            Vertex3D{+1.0f, +1.0f, +1.0f, r, g, b, a},
            Vertex3D{+1.0f, +1.0f, -1.0f, r, g, b, a},
            Vertex3D{-1.0f, +1.0f, -1.0f, r, g, b, a},
            Vertex3D{-1.0f, +1.0f, +1.0f, r, g, b, a},
            Vertex3D{+1.0f, -1.0f, +1.0f, r, g, b, a},
            Vertex3D{+1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, -1.0f, r, g, b, a},
            Vertex3D{-1.0f, -1.0f, +1.0f, r, g, b, a}
        },
        {
            0, 1, 3,
            1, 2, 3,
            4, 5, 7,
            5, 6, 7,
            8, 9, 11,
            9, 10, 11,
            12, 13, 15,
            13, 14, 15,
            16, 17, 19,
            17, 18, 19,
            20, 21, 23,
            21, 22, 23
        },
        shaderID
    ) {}
};
