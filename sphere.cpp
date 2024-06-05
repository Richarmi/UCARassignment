// Program: 	sphere.cpp
// Programmer:	Michael Richards
// Date:		6/3/2024

// Description: This program performs as a simple script for calculating the volume of a sphere 
// for use in foo parameterization. It works in two forms: the first is as a simple prompt for the user,
// and the other is for it to be used as a simple script that can be run from a Linux prompt. The second
// means of its use is intended for use by other users in their programs, thus allowing it to be expanded 
// for use in any kind of calculations.

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using namespace std;

double calculateSphere(double& rad)
{
	return (M_PI * 4 / 3) * (pow(rad, 3));
}

void promptCalculateSphere()
{
	string radiusStr = "";
	double radiusVal = 0;
	double sphereVolVal = 0;
	
	// prompt the user to enter a value for the radius. 
	// The advantage of prompting for a radius as a string 
	// value is that the user won't try to break the program 
	// by entering characters instead of numbers.
	cout << "Enter a radius value: ";
	cin >> radiusStr;
	cout << "\n\n";

	radiusVal = stod(radiusStr);
	
	sphereVolVal = (M_PI * 4 / 3) * (pow(radiusVal, 3));
	
	cout << "Volume of sphere with radius " << radiusVal << ": " << sphereVolVal << "\n\n";
}


int main(int argc, char *argv[])
{
	double radius = stod(argv[1]);
	double sphereVolume = 0;
	string str1 = "prompt";
	string str2 = "script";
	
	if(argv[2] == str1)
	{
		promptCalculateSphere();
		return 0;
	}
	else if(argv[2] == str2)
	{
		// perform the calculation, and then 
		// convert the result into a string
		sphereVolume = calculateSphere(radius);
		string output = to_string(sphereVolume);
		
		// in order to have the program produce 
		// the result as a string value on the 
		// user's prompt, we have to "echo" the 
		// value. This will be done by concatenating 
		// the calculated result to a command string
		// containing the "echo" command, and then 
		// converting the resulting command into its 
		// C-string form.
		string thisCommand = "echo ";
		thisCommand += output;
		
		system(thisCommand.c_str());
		return 0;
	}
	else 
	{
		return 0; // Don't do anything
	}
}


