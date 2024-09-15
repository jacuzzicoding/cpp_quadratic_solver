//Brock Jenkinson
//Class: CSCI-C212
//Assignment: Lab Assignment 1 - Prime Number Checker
//Date: 9/11/2024


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototypes
bool isPrime(int n);
void printDivisors(int n);

// main program loop
int main() {
    int n;
    char choice;

//the intro message will be outside of the do loop so it only prints once. 
 cout << "This program will tell you if a number is prime or not, and provide a list of all the divisors of that number.\n";
   //implementing a do loop here so it can be used multiple times without restart
    do {
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
bool isPrime(int n)
    {
        if (n <= 1) {
            return false;
        }
//if the number is 2 or greater, we will check if it has any divisors. If it does, it is not prime and it will return false
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
//if it has no divisors, it is prime and will return true
        return true;
    }
//now we will define the printDivisors function to print all the divisors of the number! 
void printDivisors(int n) {
    cout << "Thank you!\nThe divisors of " << n << " are: ";
    //loop through all the numbers from 1 to n and check if they are divisors of n. If they are, it will print them
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}