#pragma once
#include <cmath>
#include <list>
#include <iostream>

namespace clg
{
    struct vec3
    {
        float x, y, z;
        vec3(): x(0.0), y(0.0), z(0.0){}
        vec3(float x_, float y_, float z_): x(x_), y(y_), z(z_){}

        vec3 operator +  (const vec3& v) const { return vec3(x + v.x, y + v.y, z + v.z); };
        vec3 operator -  (const vec3& v) const { return vec3(x - v.x, y - v.y, z - v.z); };
        vec3 operator *  (const vec3& v) const { return vec3(x * v.x, y * v.y, z * v.z); };
        vec3 operator /  (const vec3& v) const { return vec3(x / v.x, y / v.y, z / v.z); };

        bool operator == (const vec3& v) const { return (x == v.x && y == v.y && z == v.z);};
        bool operator != (const vec3& v) const { return (x != v.x || y != v.y || z != v.z);};
    };

    struct vec4
    {
        float x, y, z, w;
        vec4(): x(0.0), y(0.0), z(0.0), w(0.0){}
        vec4(float x_, float y_, float z_, float w_): x(x_), y(y_), z(z_), w(w_){}

        vec4 operator +  (const vec4& v) const { return vec4(x + v.x, y + v.y, z + v.z, w + v.w); };
        vec4 operator -  (const vec4& v) const { return vec4(x - v.x, y - v.y, z - v.z, w + v.w); };
        vec4 operator *  (const vec4& v) const { return vec4(x * v.x, y * v.y, z * v.z, w * v.w); };
        vec4 operator /  (const vec4& v) const { return vec4(x / v.x, y / v.y, z / v.z, w / v.w); };

        bool operator == (const vec4& v) const { return (x == v.x && y == v.y && z == v.z && w == v.w);};
        bool operator != (const vec4& v) const { return (x != v.x || y != v.y || z != v.z || w != v.w);};
    };

    struct vec2
    {
        float x, y;
        vec2(): x(0.0), y(0.0){}
        vec2(float x_, float y_): x(x_), y(y_){}

        vec2 operator +  (const vec2& v) const { return vec2(x + v.x, y + v.y); };
        vec2 operator -  (const vec2& v) const { return vec2(x - v.x, y - v.y); };

        vec2 operator *  (const vec2& v) const { return vec2(x * v.x, y * v.y); };
        vec2 operator /  (const vec2& v) const { return vec2(x / v.x, y / v.y); };

        bool operator == (const vec2& v) const { return (x == v.x && y == v.y);};
        bool operator != (const vec2& v) const { return (x != v.x || y != v.y);};
    };


}