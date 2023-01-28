#pragma once
#include "ray.h"
/**
*/
namespace rendering{
struct hit_record{
    float t;
    rendering::vec3 normal;
    rendering::vec3 position;
};

class Hitable{
    public: 
        virtual bool hit(const  ray& r, float t_min ,float t_max, hit_record& rec) const = 0;
};
}