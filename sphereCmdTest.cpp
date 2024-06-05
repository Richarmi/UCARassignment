// Program: 	sphereCmdTest.cpp
// Programmer:	Michael Richards
// Date:		6/3/2024

// Description: this program is to test how the user can derive a value 
// 				from the command prompt by running the executable for
//				sphere.cpp within here or any other script/program. 

// NOTICE: the logic for capturing the results from a command comes from
// the following websites: 
// https://www.jeremymorgan.com/tutorials/c-programming/how-to-capture-the-output-of-a-linux-command-in-c/
// and https://pubs.opengroup.org/onlinepubs/009696799/functions/popen.html. 

// Observation: The advantage C++ to offer is its speed in compiling and linking byte 
// code, but its drawback is that it lacks the robust functional features other languages 
// such as Java have to offer.


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	double promptValue = 0;
	string command = "./mySphere 5 script";
	
	string resultsOutput = "";
	char buffer[256];
	FILE* commandStream = popen(command.c_str(), "r");
	
	while(!feof(commandStream))
	{
		if(fgets(buffer, 256, commandStream) != NULL)
		{
			resultsOutput.append(buffer);
		}
	}
	
	pclose(commandStream);
	
	promptValue = stod(resultsOutput.c_str());
	
	
	cout << "the value of the sphere volume captured: " << promptValue << "\n\n";
}
