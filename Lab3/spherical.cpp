#include "spherical.h"

double *sphericalToRectangular (double r, double azimuth, double inclination){
    // dynamically allocate memory for an array of three doubles
    double *coords = new double[3];

    // Calculate the cartesian coordinates based on starting data
    coords[0] = r * sin(inclination) * cos(azimuth);
    coords[1] = r * sin(inclination) * sin(azimuth);
    coords[2] = r * cos(inclination);

    return coords;
}

SphericalCoords rectangularToSpherical (double x, double y, double z){
    // Create a variable of type SphericalCoords to hold the spherical coordinates
    SphericalCoords coords;

    // Calculate the spherical coordinates based on starting data
    coords.radius = sqrt(x*x + y*y + z*z);
    coords.inclination = atan2(sqrt(x*x + y*y), z);
    coords.azimuth = atan2(y, x);
    
    return coords;
}