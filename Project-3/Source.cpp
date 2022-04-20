#include <iostream>
#include <Python.h>
#include <string>
#include <list>

#include "Helper.h"
#pragma warning(disable:4996)

using namespace std;

int main()
{
	// Variables for user number input.
	string selection;
	string answer;
	// Helper intialization
	Helper helper;

	// Print intro an menu text
	helper.PrintIntro();
	helper.PrintMenu();

	// While loop condition
	bool done = false;
	while (!done)
	{
		// User input for what operation is requested
		helper.TakeUserInput();
		int operation = helper.GetCurrentOperation();
		int num;

		// Run the user-requested operation
		switch (operation)
		{
			// Multiplication table request
		case 1:
			// Clears the screen, gets user input for the number, and displays its multiplication table.
			helper.ClearScreen();
			helper.CallProcedure("ItemTotal");
			break;

		case 2:
			// Clears the screen, gets user input for the number, and displays its double.
			helper.ClearScreen();
			cout << "Please enter an item to search." << endl;
			helper.TakeUserSelection();
			selection = helper.GetUserSelection();
			num = helper.CallIntFunc("QuantSearch", selection);
			helper.ClearScreen();
			if (num > 1)
			{
				cout << selection << " was purchased " << num << " times." << endl;
			}
			else if (num > 0)
			{
				cout << selection << " was purchased " << num << " time." << endl;
			}
			else
			{
				cout << selection << " was not purchased today." << endl;
			}
			break;
		case 3:
			helper.ClearScreen();
			helper.CallProcedure("DisplayGraph");
			break;
		case 4:
			exit(EXIT_SUCCESS);
		}

		// Looping condition for correct input for additional operations
		bool badInput = true;
		cout << "Would you like to run another operation? y/n" << endl;

		cin >> answer;

		while (badInput)
		{
			// Exits gracefully
			if (answer == "n" || answer == "N")
			{
				exit(EXIT_SUCCESS);
			}

			// Clears the screen and starts the next iteration
			else if (answer == "y" || answer == "Y")
			{
				helper.ClearScreen();
				helper.PrintMenu();
				break;
			}

			// Prints an error message for the user. 
			else
			{
				cout << "Error, bad input. Please enter 'y' or 'n'." << endl;
				cin >> answer;
			}
		}
	}

	return 0;
}