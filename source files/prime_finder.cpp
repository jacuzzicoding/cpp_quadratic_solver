//Brock J Prime Number Program
//It will tell you if a given number is prime or not, and provide a list of all the divisors of that number.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototypes
bool isPrime(int n);
void printDivisors(int n);

// main program loop
int main() {
    double n;
    char choice;

//doing a do loop here so it can be used multiple times without restart
    do {
        cout << "This program will tell you if a number is prime or not, and provide a list of all the divisors of that number.\n";
        cout << "Enter a number: ";
        cin >> n;
//error check to make sure the number is positive
        if (n <= 0) {
            cout << "Please enter a positive number!\n" << endl;
        }
//if its positive, we will check if its prime by calling the isPrime function 
        else {
            if (isPrime(n)) {
                cout << n << " is a prime number!\n";
            } else {
                cout << n << " is not a prime number.\n";
            }
        }
//print the divisors of the number
        printDivisors(n);
        //ask the user if they want to check another number to close the do while loop
        cout << "Do you want to check another number? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
        }

//now for the functions
//isPrime function will check if the number is prime
bool isPrime(int n);
    {
        if (n <= 1) {
            return false;
        }
        for (int )
    }
    ]