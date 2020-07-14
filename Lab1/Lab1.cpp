#include <iostream>
#include <cmath>
#include <cstdlib>
 
using namespace std;



// Function prototypes for forward-referenced functions
void getUserInput (double &radius, double &pegDist, double &spacing);
void outputResults (const double angles[], const double distances[], const int numLights);


int main (){

    double radius, pegDist, maxSpacing, spacing, arclength, theta, alphainc, alpha = 0, beta;
    int numLights;

    getUserInput (radius, pegDist, spacing);

    theta = 2*asin((pegDist/2)/radius);

    arclength = theta * radius;

    numLights = ceil(arclength / maxSpacing) + 1;

    spacing = arclength / (numLights - 1);

    alphainc = spacing / radius;



    double distances[numLights];
    double angles[numLights];

    cerr << "OK" << endl;
    cerr.flush();

    for (int i=0; i < numLights; i++) {

        distances[i] = 2 * (radius * sin (alpha/2));

        beta = asin(radius * sin(alpha)/distances[i]);

        angles[i] = beta - (M_PI - (theta /2) + (M_PI / 2));

        alpha = alpha + alphainc;

    }

    outputResults (angles, distances, numLights);

    return 0;

}

/*
 * Prints the result to standard output - command-line interface
 *
 * @param angles Array of angles, referenced to the baseline chord (radians)
 * @param distances Array of distances to the streetlights
 * @param numLights Number of streetlights
 *
 */
void outputResults (const double angles[], const double distances[], const int numLights) {
    cout << numLights << " streetlights are required." << endl;
    
    for (int i=0; i < numLights; i++) {
        cout << "Light " << (i+1) << ": Distance=" << distances[i];
        if (distances[i] > 1.0e-6) {
            cout << " Angle=" << angles[i] * 180.0/M_PI << " degrees";
        }
        cout << endl;
    }
}

/**
 * Gets input values from the user via a command-line prompt:
 * radius of curvature, distance between pegs, and maximum streetlight spacing
 *
 * @param radius Reference to the radius of curvature
 * @param pegDist Reference to the distance between arc endpoints
 * @param spacing Reference to maximum streetlight spacing
 * 
 */
void getUserInput (double &radius, double &pegDist, double &spacing) {
    cout << "Enter the radius of curvature: ";
    cin >> radius;
    cout << "Enter the distance between the survey pegs at the endpoints: ";
    cin >> pegDist;
    if (pegDist > 2.0 * radius) {
        cerr << "The distance between pegs cannot be more than twice the radius!";
        exit (EXIT_FAILURE);
    }
    cout << "Enter the maximum streetlight spacing along the arc: ";
    cin >> spacing;
}

