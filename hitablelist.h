#pragma once

#include "hitable.h"

namespace rendering{
    class Hitablelist: public rendering::Hitable{
    public:
        Hitablelist(){}
        Hitablelist(rendering::Hitable **l , int n){
            this->list = l;
            this->list_size = n;
        }
        virtual bool hit(const ray& r , float t_min , float t_max , hit_record& rec) const;
        rendering::Hitable **list;
        int list_size;
    };


bool Hitablelist::hit(const ray& r, float t_min , float t_max , hit_record& rec) const{
    rendering::hit_record temp_rec;
    bool hit_anything = false;
    double closet_so_far = t_max;
    for (int i = 0; i < list_size; i++){
        if (this->list[i]->hit(r,t_min,closet_so_far,temp_rec)){
            hit_anything = true;
            closet_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}   
}