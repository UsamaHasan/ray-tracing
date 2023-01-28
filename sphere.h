#pragma once

#include"hitable.h"
/**
 * @brief 
 * t*t*dot( B, ​B) ​ + 2*t*dot( B,A - ​C ​) + dot( A-C,A ​- ​C ​ ) - R*R = 0
 */
namespace rendering{
class Sphere: public Hitable{
    public:
        Sphere(){}
        Sphere(rendering::vec3 center,float radius):center(center),radius(radius){};
        virtual bool hit(const ray& r, float t_min,float t_max ,hit_record& rec) const;       
        rendering::vec3 center;
        float radius;
};
bool Sphere::hit(const ray& r, float t_min , float t_max, rendering::hit_record& rec) const{
    rendering::vec3 oc = r.origin() - this->center;
    float a = rendering::dot(r.direction(),r.direction());
    float b = 2 * rendering::dot(r.direction(),oc);
    float c = rendering::dot(oc,oc) - this->radius*this->radius;
    float determinat = b*b - a*c;
    if (determinat>0) {
        float temp = (-b - std::sqrt(b*b-a*c))/a;
        if(temp > t_min && temp < t_max){
            rec.t = temp;
            rec.position = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center)/radius;
            return true;           
        }
        temp = (-b + std::sqrt(b*b-a*c))/a;
        if(temp > t_min && temp < t_max){
            rec.t = temp;
            rec.position = r.point_at_parameter(rec.t);
            rec.normal = (rec.p - center)/radius;
            return true;           
        }
    }
    return false;
    
}
}