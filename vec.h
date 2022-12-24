/**/
#pragma once
#include <iostream>
#include <math.h>
#include <stdlib.h>

class vec3{
    public:
        vec3(){}
        vec3(float e0, float e1 , float e2){
            e[0] = e0;
            e[1] = e1;
            e[2] = e2;
        }
        inline float x() const{return e[0];}
        inline float y() const{return e[1];}
        inline float z() const{return e[2];}
        inline float r() const{return e[0];}
        inline float g() const{return e[1];}
        inline float b() const{return e[2];}
        inline const vec3& operator+() const{return *this;}
        inline vec3 operator-() const{return vec3(-e[0],-e[1],-e[2]);}
        inline float operator[](int i) const {return e[i];}
        inline float& operator[](int i){return e[i];}
        inline vec3& operator+=(const vec3 &v2);
        inline vec3& operator-=(const vec3 &v2);
        inline vec3& operator*=(const vec3 &v2);
        inline vec3& operator/=(const vec3 &v2);
        inline vec3& operator*=(const float t);
        inline vec3& operator/=(const float t);
        inline float length() const{
            return std::sqrt(e[0]*e[0]+e[1]*e[1]+e[2]*e[2]);
        }
        inline float squared_length() const{
            return (e[0]*e[0]+e[1]*e[1]+e[2]*e[2]); 
        }
        inline void make_unit_vector();

        float e[3];
};

inline std::istream& operator>>(std::istream &is , vec3&temp){
    is >> temp.e[0] >> temp.e[1] >> temp.e[2];
    return is;
}

inline std::ostream& operator<<(std::ostream &os , vec3&temp){
    os << temp.e[0] << temp.e[1] << temp.e[2];
    return os;
}
/**/
inline void vec3::make_unit_vector(){
    float norm = 1.0/std::sqrt(this->e[0]*this->e[0]+this->e[1]*this->e[1]+this->e[2]*this->e[2]);
    e[0] *= norm;
    e[1] *= norm;
    e[2] *= norm;
}
/**/
inline vec3 operator+(const vec3 &v1,const vec3 &v2){
    return vec3(v1.e[0] + v2.e[0],v1.e[1] + v2.e[1] , v1.e[2]+ v2.e[2]);
}
inline vec3 operator-(const vec3 &v1,const vec3 &v2){
    return vec3(v2.e[0]-v1.e[0],v2.e[1]-v1.e[1],v2.e[2]-v1.e[2]);
}
/**/
inline vec3 operator*(const vec3 &v1,const vec3 &v2){
    return vec3(v1.e[0]*v2.e[0],v1.e[1]*v2.e[1],v1.e[2]*v2.e[2]);
}
/**/
inline vec3 operator/(const vec3 &v1,const vec3 &v2){
    return vec3(v1.e[0]/v2.e[0],v1.e[1]/v2.e[1],v1.e[2]/v2.e[2]);
}
/**/
inline vec3 operator*(const vec3 &v,float temp){
    return vec3(v.e[0]*temp, v.e[1]*temp, v.e[2]*temp);
}
/**/
inline vec3 operator*(float temp,const vec3 &v){
    return vec3(v.e[0]*temp, v.e[1]*temp, v.e[2]*temp);
}
/**/
inline vec3 operator/(const vec3 &v,float temp){
    return vec3(v.e[0]/temp,v.e[1]/temp,v.e[2]/temp);
}
/**/
inline vec3 operator/(float temp,const vec3 &v){
    return vec3(v.e[0]/temp,v.e[1]/temp,v.e[2]/temp);
}
/**/
inline float dot(const vec3 &v1,const vec3 &v2){
    return v1.e[0]*v2.e[0] + v1.e[1]*v2.e[1] + v1.e[2]*v2.e[2];
}
/**/
inline vec3 cross_product(const vec3 &v1,const vec3&v2){
    return vec3((v1.e[1]*v2.e[2]) - (v1.e[2]*v1.e[1]),
                (v1.e[0]*v2.e[2]) - (v1.e[2]*v2.e[0]),
                (v1.e[0]*v2.e[1]) - (v1.e[1]*v2.e[0]));
}
inline vec3& vec3::operator+=(const vec3 &v2){
    this->e[0]+=v2.e[0];
    this->e[1]+=v2.e[1];
    this->e[2]+=v2.e[2];
    return *this;
}
inline vec3& vec3::operator-=(const vec3 &v2){
    this->e[0]-=v2.e[0];
    this->e[1]-=v2.e[1];
    this->e[2]-=v2.e[2];
    return *this;
}
inline vec3& vec3::operator*=(const vec3 &v2){
    this->e[0]*=v2.e[0];
    this->e[1]*=v2.e[1];
    this->e[2]*=v2.e[2];
    return *this;
}
inline vec3& vec3::operator/=(const vec3 &v2){
    this->e[0]/=v2.e[0];
    this->e[1]/=v2.e[1];
    this->e[2]/=v2.e[2];
    return *this;
}
inline vec3& vec3::operator*=(const float temp){
    this->e[0]*=temp;
    this->e[1]*=temp;
    this->e[2]*=temp;
    return *this;
}
inline vec3& vec3::operator/=(const float temp){
    this->e[0]/=temp;
    this->e[1]/=temp;
    this->e[2]/=temp;
    return *this;
}
inline vec3 unit_vector(vec3 v){
    return v / v.length();
}