/*
COMP139E
Lab 1 - A Surveying Problem
survey.cpp - A simple program to calculate the position of streetlights to be placed
on a curve of known radius with a straight line distance between the start 
and end point and a maximum acceptable spacing between the successive street lights

By: Remi Coussement
C0450402
*/

#include "helper.cp"
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double radius, peg_dist, max_spacing;
    double theta, gamma, arc_length, spacing, alpha;
    int num_lights;

    // Get values defining the radius of curvature, 
    // distance between starting and ending pegs, 
    // and the maximum spacing between successive street lights
    getUserInput(radius, peg_dist, max_spacing);

    // Calculates values which apply to all streetlights for the usecase
    theta = 2 * asin(peg_dist/(2*radius));
    gamma = M_PI/2 - theta/2;
    arc_length = radius * theta;
    num_lights = ceil(arc_length / max_spacing) + 1;
    spacing = arc_length / (num_lights - 1);
    alpha = spacing / radius;

    // Arrays to hold the list of distance and 
    // angle values defining the placement of the streetlights
    double distances[num_lights];
    double angles[num_lights];

    // Iterate through the streetlights calculating their individual placement
    for(int i = 0; i < num_lights; i++){
        distances[i] = 2 * radius * sin(alpha * i/ 2);
        angles[i] = M_PI/2 - (alpha * i / 2) - gamma;
    }

    // Outputs the results table to the console
    outputResults(angles, distances, num_lights);

    return 0;
}