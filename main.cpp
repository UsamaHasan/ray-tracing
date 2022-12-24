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
            //float r = float (j) / nx;
            //float g = float (i) / ny;
            float r = 0.5;
            float g = 0.5;
            float b = 0.2;
            int ir = int(255.99*r);
            int ig = int(255.99*g);
            int ib = int(255.99*b);
            ppm_file << ir << " " << ig << " " << ib << "\n";
        }
    }
    ppm_file.close();
}
int main()
{
    int nx =200;
    int ny =100;
    //Uncomment to say graphical hello world
    ppm(nx,ny);
    vec3 vec(1.0,1.0,1.0);
}