//The purpose of this assignment is to develop a C++ program that:
//calculates the roots of a quadratic equation using the quadratic formula. 
//This will help students practice working with functions, conditional statements, input/output operations, and mathematical computations.

#include <iostream>
#include <cmath>
using namespace std;

//example quadratic equation: ax^2 + bx + c = 0
//the quadratic formula is: x = (-b ± √(b^2 - 4ac)) / 2a
//so our variables are a, b, and c. 
//the functions i will need: 
//this is a function to calculate the roots of the quadratic equation
    void quadraticRoots(int, int, int);
//this is a function to calculate the discriminant
    int discriminant(int, int, int);
//function to calculate the roots
    void calculateRoots(int, int, int, int);
//function to display the roots of the quadratic equation
    

//main program loop begins here
int main() {
    int a, b, c;
    cout << "Enter the coefficients of the quadratic equation (a, b, and c): ";
    cin >> a >> b >> c;
    quadraticRoots(a, b, c);
    if (a == 0) {
        cout << "The value of 'a' cannot be zero. Please enter a valid value for 'a'." << endl;
        return 0;
    }
    else if (discriminant(a, b, c) < 0) {
        cout << "The roots are imaginary." << endl;
        return 0;
    }
    else {
        calculateRoots(a, b, c, discriminant(a, b, c));
    }
    return 0;
}