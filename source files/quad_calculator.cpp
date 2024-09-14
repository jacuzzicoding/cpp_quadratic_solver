//Brock Jenkinson
//Class: CSCI-C212
//Assignment: Lab Assignment 1 - Quadratic Formula Calculator 
//Date: 9/09/2024


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototypes because I put the function definitions after the main program loop 
void quadraticRoots(double a, double b, double c);
double discriminant(double a, double b, double c);
void calculateRoots(double a, double b, double c, double disc);

// main program loop begins here
int main() {
    double a, b, c;
    char choice;

//intro message before do while loop
    cout << "This program calculates the roots of a quadratic equation in the form of ax^2 + bx + c.\n";
//here we will use a do while loop to allow the user to solve multiple equations without restarting the program :)
    do {
        cout << "Enter the coefficients of the quadratic equation (a, b, and c): ";
        cin >> a >> b >> c;
//error checking to make sure the equation is quadratic
        if (a == 0) {
            cout << "This is not a quadratic equation. 'a' must be non-zero. Remember, 'x' of a variable is really '1x'\n" << endl;
        } else {
            quadraticRoots(a, b, c);
        }

        cout << "Do you want to solve another equation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

// implementing the function prototypes. discriminant function is the b^2 - 4ac part of the quadratic formula
double discriminant(double a, double b, double c) {
    return (b*b) - (4 * a * c);
}
// calculateRoots function will calculate the roots, or the "x's" of the quadratic equation
void calculateRoots(double a, double b, double c, double disc) {
    cout << fixed << setprecision(2);
    if (disc >= 0) {
        double root1 = (-b + sqrt(disc)) / (2 * a);
        double root2 = (-b - sqrt(disc)) / (2 * a);
        cout << "The roots of the quadratic equation are: " << root1 << " and " << root2 << endl;
    } else {
        double realPart = -b / (2 * a);
        double imagPart = sqrt(-disc) / (2 * a);
        cout << "The roots of the equation are: " 
             << realPart << " + " << imagPart << "i and "
             << realPart << " - " << imagPart << "i" << endl;
    }
}

// the quadraticRoots function
void quadraticRoots(double a, double b, double c) {
    double disc = discriminant(a, b, c);

    if (disc > 0) {
        cout << "The quadratic equation has two distinct real roots." << endl;
        calculateRoots(a, b, c, disc);
    } else if (disc == 0) {
        cout << "The quadratic equation has one real root (repeated)." << endl;
        calculateRoots(a, b, c, disc);
    } else {
        cout << "The quadratic equation has two complex roots." << endl;
        calculateRoots(a, b, c, disc);
    }
}