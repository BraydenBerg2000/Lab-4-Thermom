/*
Brayden Berg
C++ Fall 2019
Due: 10/10/19
Lab 4 Temperature Output
	Design and write a C++ program that inputs a series of hourly temperature
from a file, and outputs a bar chart (using stars) of the temperatures for the day. The
temperature should be printed to the left of the corresponding bar, and there should be
a heading that gives the scale of the chart. The range of temperatures should be from
-30 to 120. Because it is hard to display 150 characters on the screen, you should have
each star represent a range of 3 degrees. That way, the bars will be at most 50
characters wide. Use meaningful variable names, proper indentation, and appropriate
comments. Thoroughly test the program using your own data sets. Make sure to vet the
values from the input file.
*/

//these are the libraries that were used through this program
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

//this label's function prototype
void label();

int main()
{
	//this sets my input file to an identifier
	string inputFile = "C:/Users/brayd/OneDrive/Desktop/C++ Projects/Lab 4 Temperature Output/Lab 4 Temperature Output/Input.dat";

	//this sets the identifier of the input number as a float
	float num;

	//this starts the inFile stream
	ifstream inFile;
	//this opens the file
	inFile.open(inputFile);

	//this is a call to the void label() function
	label();
	//this inputs the file to the variable of num
	inFile >> num;
	//this sets the identifier of the star amount as a float
	float star;

	//Precondition: file is properly executed and temperature is correct to this point
	//Postcondition: Properly outputs the rest of the bar chart and error statements when needed
	while (inFile)
	{
		//float star = num / float(3);
		//this states that the inputted number must be within -30 to 120 inorder to execute the collection of code
		if (num <= 120 && num >= -30)
		{
			//this states that the inputted number must be greater than or equal to zero in order to execute
			if (num >= 0)
			{
				//this determines what my star identifier will equal for the positive numbers
				star = round(num / 3);

				//this states that the inputted number must be eaqual to 0 or between 0 and 10 in order to execute this statement
				if (num >= 0 && num < 10)
				{
					//this outputs two spaces to make the inputted number in line with the others, makes all outputted numbers in the main function have a fixed
					//number of six decimal places, outputs the inputted number with a degree simbol, then outputs the correct ammount of stars in the correct locations 
					cout << "  " << fixed << num << char(167) << "|" << "           " << "|";
					cout << setw(star + 1) << setfill('*') << '\n';
				}
				//this states that the inputted number must be greater than or equal to 10 and less than 100 in order for the statement to be executed
				else if (num >= 10 && num < 100)
				{
					//this outputs one space to make the inputted number in line with the others, outputs the inputted number with a degree simbol, 
					//then outputs the correct ammount of stars in the correct locations
					cout << " " << num << char(167) << "|" << "           " << "|";
					cout << setw(star + 1) << setfill('*') << '\n';
				}
				//this allows any other numbers inputted between 100 and 120, including 100 and 120 to execute this statement
				else
				{
					//this outputs the inputted number with a degree simbol, then outputs the correct ammount of stars in the correct locations
					cout << num << char(167) << "|" << "           " << "|";
					cout << setw(star + 1) << setfill('*') << '\n';
				}
			}
			//this states that a number less than 0 must be inputted in order for this statement to execute
			else if (num < 0)
			{
				//this sets the identifier of the amount of spaces as an integer
				int space;

				//this determines what the star identifier will equal for the negative numbers
				star = round(num / -3);
				//this determines the value of the space identifier
				space = (11 - star);
				//this states that an inputted number must be between 0 and -10 in order to execute the statement
				if (num<0 && num>-10)
				{
					//this outputs one space to make the inputted number in line with the others, outputs the inputted number with a degree simbol
					cout << " " << num << char(167) << "|";
					//this count controlled loop outputs the amount of spaces as the space identifier is equal to
					while (space > 0)
					{
						cout << " ";
						space--;
					}
					//this fills the remaining space up to the '|' with stars
					cout << setw(star + 1) << setfill('*') << '|' << '\n';
				}
				//this allows any other numbers inputted between -10 and -30, including -10 and -30 to execute this statement
				else
				{
					// outputs the inputted number with a degree simbol
					cout << num << char(167) << "|";
					//this count controlled loop outputs the amount of spaces as the space identifier is equal to
					while (space > 0)
					{
						cout << " ";
						space--;
					}
					//this fills the remaining space up to the '|' with stars
					cout << setw(star + 1) << setfill('*') << '|' << '\n';

				}
			}
		}
		//this statement triggers if the number inputted is outside of the parameters thus being too high or too low of a number
		else if (num > 120 || num < -30)
		{
			//this displays a message 
			cout << "The inputed number does not fall within the parameters." << endl;
		}
		//this inputs the next data value from the file again to the identifier num and then restarts the loop unless it is invalid
		inFile >> num;
	}
	//this statement triggers if the inputted number is not a number
	if (!num)
	{
		//this will both display the message and exit the program
		cout << "You cannot input a character!\n";
		return 1;
	}
	return 0;
}

//this function outputs the introduction statement as well as the label for the program
void label()
{
	cout << "Please input a temperature value between -30" << char(167) << " and 120" << char(167) << endl;
	cout << setw(14) << "-30" << char(167) << setw(9) << "0" << char(167) << setw(9) << "30" << char(167);
	cout << setw(9) << "60" << char(167) << setw(9) << "90" << char(167) << setw(9) << "120" << char(167) << endl;
	cout << "_________________________________________________________________" << endl;
}