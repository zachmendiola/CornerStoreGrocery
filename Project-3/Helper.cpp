#include "Helper.h"
#include <Python.h>
#include <Windows.h>
#include <iostream>
#include <cmath>
using namespace std;



//Class: Helper - Abstracts printing functions and most user input to keep code as readable as possible.

// Prints a stylized introduction
void Helper::PrintIntro()
{
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------ Corner Grocery ------------------------------------" << endl;
	cout << "--------------------------------- Inventory Application --------------------------------" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;

}

// Prints the main menu
void Helper::PrintMenu()
{
	cout << " " << endl;
	cout << "________________________________________________________________________________________" << endl;
	cout << "                                        Main Menu                                       " << endl;
	cout << "________________________________________________________________________________________" << endl;


	cout << " " << endl;
	cout << "Please select from one of the following options:" << endl;
	cout << "1: List all types of items purchased and quantity" << endl;
	cout << "2: Check number of times an item was purchased" << endl;
	cout << "3: Graph of items sold" << endl;
	cout << "4: Exit application" << endl;
}

// Clears the screen to be presentable
void Helper::ClearScreen()
{
	for (int i = 0; i < 40; i++)
	{
		cout << " " << endl;
	}
}

// Loops to take user input for the operation to be done
void Helper::TakeUserInput()
{
	int result = 0;
	while (result != 1 && result != 2 && result != 3 && result != 4)
	{
		try
		{
			cin >> result;
			if (result == 1 || result == 2 || result == 3 || result == 4)
			{
				this->m_currentOperation = result;
			}
		}
		catch (exception e)
		{
			cout << "Please enter a valid selection." << endl;
		}
	}
}

// Loops to take user input for the number for the operation
void Helper::TakeUserSelection()
{
	string result = "";
	try
	{
		cin >> result;
		this->m_userSelection = result;
	}
	catch (exception e)
	{
		cout << "Error, please enter valid input." << endl;
	}
}

// Gets m_userNum
string Helper::GetUserSelection()
{
	return this->m_userSelection;
}

// Gets m_currentOperation
int Helper::GetCurrentOperation()
{
	return this->m_currentOperation;
}

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void Helper::CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int Helper::CallIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
void Helper::CallIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return;
}

// Default constructor
Helper::Helper()
{
	this->m_currentOperation = 0;
	this->m_userSelection = "";
}