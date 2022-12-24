#pragma once
#include"vec.h"
/*
ray(t) = A + t*B
where A is the ray origin, B is the direction and t is the timestamp.
*/
namespace rendering{
class ray{
    public:
        ray(){}
        ray(const vec3 &a,const vec3&b){
            this->A = a;
            this->B = b;
        }
        vec3 origin() const{
            return A;
            }
        vec3 direction() const{
            return B;
        }
        vec3 point_at_parameter(float t){
            return vec3(this->A + t*this->B);
        }
        vec3 A;
        vec3 B;
};
}