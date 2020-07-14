#ifndef SPHERICAL_H
#define SPHERICAL_H
#include <cmath>

/*
* Structure that defines the spherical coordinates of a vector
*/
typedef struct {
    double radius;
    double azimuth;
    double inclination;
} SphericalCoords;

/*
* Function returns the magnitude of the resultant of 3 cartesian coordinates
*
* @param x The coordinate along the x axis
* @param y The coordinate along the y axis
* @param z The coordinate along the z axis (only required for 3D)
*
* @return resultant magnitude of the components along the 3 axis
*/
inline double getRadius (double x, double y, double z=0.0){
    return sqrt(x*x + y*y + z*z);
}

/*
* Function to convert from spherical coordinates to the cartesian coordinate system
*
* @param r radius of the vector in spherical coordinates
* @param azimuth angle between azimuth refernce and projection of vector
* @param inclination angle between zenith and projection of vector (only required for 3D)
*
* @return a pointer to an array containing [x,y,z] coordinates
*/
double *sphericalToRectangular (double r, double azimuth, double inclination=M_PI/2);

/*
* Function to convert from cartesian coordinates to the spherical coordinate system
*
* @param x The coordinate along the x axis
* @param y The coordinate along the y axis
* @param z The coordinate along the z axis (only required for 3D)
*
* @return struct of type SphericalCoords which contains the spherical coordinate 
*         values corresponding to the starting vector
*/
SphericalCoords rectangularToSpherical (double x, double y, double z=0.0);

#endif  // SPHERICAL_H