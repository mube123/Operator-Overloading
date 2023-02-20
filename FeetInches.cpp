#include<iostream>
#include <cstdlib> // Needed for abs()
#include "FeetInches.h"
using namespace std;

//**************************************************************
// Definition of member function simplify. This function *
// checks for values in the inches member greater than *
// twelve or less than zero. If such a value is found, *
// the numbers in feet and inches are adjusted to conform *
// to a standard feet & inches expression. For example, *
// 3 feet 14 inches would be adjusted to 4 feet 2 inches and *
// 5 feet -2 inches would be adjusted to 4 feet 10 inches. *
//**************************************************************

void FeetInches::simplify()
{
 if (inches >= 12)
 {
 feet += (inches / 12);
 inches = inches % 12;
 }
 else if (inches < 0)
 {
 feet -= ((abs(inches) / 12) + 1);
 inches = 12 - (abs(inches) % 12);
 }
 }

//**********************************************
// Overloaded binary + operator. *
//**********************************************

FeetInches FeetInches::operator + (const FeetInches &right)
{
 FeetInches temp;

 temp.inches = inches + right.inches;
 temp.feet = feet + right.feet;
 temp.simplify();
 return temp;
 }

//**********************************************
// Overloaded binary - operator. *
//**********************************************

FeetInches FeetInches::operator - (const FeetInches &right)
{
 FeetInches temp;

 temp.inches = inches - right.inches;
 temp.feet = feet - right.feet;
 temp.simplify();
 return temp;
 }
 

 
 int main()
{
int feet, inches; // To hold input for feet and inches

// Create three FeetInches objects. The default arguments
// for the constructor will be used.
 FeetInches first, second, third;

// Get a distance from the user.
 cout << "Enter a distance in feet and inches: ";
 cin >> feet >> inches;

// Store the distance in the first object.
 first.setFeet(feet);
 first.setInches(inches);

// Get another distance from the user.
 cout << "Enter another distance in feet and inches: ";
 cin >> feet >> inches;
 
 // Store the distance in second.
second.setFeet(feet);
second.setInches(inches);

// Assign first + second to third.
third = first + second;

// Display the result.
cout << "first + second = ";
cout << third.getFeet() << " feet, ";
cout << third.getInches() << " inches.\n";

// Assign first - second to third.
third = first - second;

// Display the result.
cout << "first - second = ";
cout << third.getFeet() << " feet, ";
cout << third.getInches() << " inches.\n";

return 0;
}
