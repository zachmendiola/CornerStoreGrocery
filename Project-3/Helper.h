#pragma once
#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>

using namespace std;
class Helper
{
	public:
		void PrintIntro();
		void PrintMenu();
		void ClearScreen();
		void TakeUserInput();
		void TakeUserSelection();
		string GetUserSelection();
		int GetCurrentOperation();
		void CallProcedure(string pName);
		int CallIntFunc(string proc, string param);
		void CallIntFunc(string proc, int param);
		Helper();
	private:
		string m_userSelection;
		int m_currentOperation;
};

