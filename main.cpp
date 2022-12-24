#include<iostream>
#include<fstream>
#include "vec.h"
#include "ray.h"

void ppm(int nx , int ny)
{
    /*
    hello world example of graphics/rendering.
    */
    std::ofstream ppm_file("./img/img3.ppm");
    ppm_file << "P3\n" << nx << " " << ny << "\n255\n";  
    for(int i = ny-1 ; i>=0; i--)
    {
        for (int j=0 ; j<nx;j++ )
        {
            float r = float (j) / nx;
            float g = float (i) / ny;
            float b = 0.2;
            int ir = int(255.99*r);
            int ig = int(255.99*g);
            int ib = int(255.99*b);
            ppm_file << ir << " " << ig << " " << ib << "\n";
        }
    }
    ppm_file.close();
}
/*
t*t*dot( B, ​B) ​ + 2*t*dot( B,A - ​C ​) + dot( A-C,A ​- ​C ​ ) - R*R = 0
*/
bool hit_sphere(const rendering::vec3& center,float radius,const rendering::ray& r){
    rendering::vec3 oc = r.origin() - center;
    float a = rendering::dot(r.direction(),r.direction());
    float b = 2.0 * rendering::dot(r.direction(),oc);
    float c = rendering::dot(oc,oc)-radius*radius;
    float discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}
/*
blended_value = (1-t)*start_value + t*end_value
*/
rendering::vec3 ray_color(const rendering::ray& r){
    if (hit_sphere(rendering::vec3(0.0,0.0,1.0) , 0.5 ,r)){
        return rendering::vec3(1.0,0.0,0.0);
    }
    rendering::vec3 unit_direction = rendering::unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * rendering::vec3(1.0,1.0,1.0) + t*rendering::vec3(0.5,0.7,1.0);
}

int main(){
    int nx =200;
    int ny =100;
    //Uncomment to say graphical hello world
    //ppm(nx,ny);
    //vec3 vec(1.0,1.0,1.0);
    /*
    Chapter 3: Rays, Camera.
    */
    std::ofstream ppm_file("img/img_sphere.ppm");
    ppm_file << "P3\n" << nx << " " << ny << "\n255\n";  
    rendering::vec3 lower_l_corner(-2.0,-1.0,-1.0);
    rendering::vec3 origin(0.0,0.0,0.0);
    rendering::vec3 horizontal(4.0,0.0,0.0);
    rendering::vec3 vertical(0.0,2.0,0.0);
    for(int i = ny-1 ; i>=0; i--)
    {
        for (int j=0 ; j<nx;j++ )
        {
            float u = float(j)/float(nx);
            float v = float(i)/float(ny);
            rendering::ray r(origin,lower_l_corner + horizontal*u + vertical*v);
            rendering::vec3 c = ray_color(r);
            int ir = int(255.99*c[0]);
            int ig = int(255.99*c[1]);
            int ib = int(255.99*c[2]);
            ppm_file << ir << " " << ig << " " << ib << "\n";
        }
    }
    ppm_file.close();
}