//Brock Jenkinson
//Class: CSCI-C212
//Assignment: Lab Assignment 1 - Quadratic Formula Calculator 
//Date: 9/09/2024

//including the necessary libraries
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototypes because I put the function definitions after the main program loop 
void quadraticRoots(int a, int b, int c);
int discriminant(int a, int b, int c);
void calculateRoots(int a, int b, int c, int disc);

// main program loop begins here
int main() {
    int a, b, c;
    char choice;

//intro message before do while loop
    cout << "This program calculates the roots of a quadratic equation in the form of ax^2 + bx + c.\n";
//here we will use a do while loop to allow the user to solve multiple equations without restarting the program. 
//Unfortunately, I cannot get the program to loop back to the beginning after the user has solved an equation. I'm not sure why, because it works on the prime_finder.cpp, but I will keep working on it.
    do {
        cout << "Enter the coefficients of the quadratic equation (a, b, and c): ";
        cin >> a >> b >> c;
//error checking to make sure the equation is quadratic. if a is 0, it is not a quadratic equation.
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
int discriminant(int a, int b, int c) {
    return (b*b) - (4 * a * c);
}
// calculateRoots function will calculate the roots, or the "x's" of the quadratic equation
void calculateRoots(int a, int b, int c, int disc) {
    cout << fixed << setprecision(2);
    if (disc >= 0) {
//using the quadratic formula to calculate the roots.
        int root1 = (-b + sqrt(disc)) / (2 * a);
        int root2 = (-b - sqrt(disc)) / (2 * a);
        cout << "The roots of the quadratic equation are: " << root1 << " and " << root2 << endl;
    } else {
//if the disc is negative, we have complex roots. so we will calculate the real part and the imaginary part
        int realPart = -b / (2 * a);
        int imagPart = sqrt(-disc) / (2 * a);
        cout << "The roots of the equation are: " 
             << realPart << " + " << imagPart << "i and "
             << realPart << " - " << imagPart << "i" << endl;
    }
}

// the quadraticRoots function
void quadraticRoots(int a, int b, int c) {
    int disc = discriminant(a, b, c);
//check if the disc is positive, if it is, we know we have two real roots and will tell the user
    if (disc > 0) {
        cout << "The quadratic equation has two distinct real roots." << endl;
        calculateRoots(a, b, c, disc);
//if the disc is 0, we have one real root that is repeated
    } else if (disc == 0) {
        cout << "The quadratic equation has one real root (repeated)." << endl;
        calculateRoots(a, b, c, disc);
//if the disc is negative, we have two complex roots
    } else {
        cout << "The quadratic equation has two complex roots." << endl;
        calculateRoots(a, b, c, disc);
    }
}