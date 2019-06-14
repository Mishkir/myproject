#pragma once
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

/*!
\brief Password generation class:


This class is used to make password list and write it into file
*/
class PassGen
{
public:
	/*!
	\brief PassGen Consructor

	Constructor is used to write passLength, numOfPasswords, filename using a, b, c input parameters


	Parameters:
	parameter a - Input length of 1 password, 
	parameter b - Input nom of passwords,	
	parameter - c Input name of output file
	*/
	PassGen(int a, int b, std::string c) : passLength(a), numOfPasswords(b), filename(c){};

	/*!
	\brief Making password list function

	It's used to make password list and write it into output file

	\code
	int PassGen::makePasswordList() {
	std::ofstream outFile(filename);
	std::string passOut;
	for (int k = 0; k < numOfPasswords; k++) {
		numOfChars();
		passOut = passGenerator();
		if (check(passOut)) {
			k--;
			continue;
		}
		outFile << passOut << endl;
	}
	outFile.close();
	return 0;
	}
	\endcode
	*/
	int makePasswordList();
private:
	/*!
	\brief Number of small chars

	It contains number of randomized small chars
	*/
	int numOfSmallChars;
	/*!
	\brief Number of big chars

	It contains number of randomized big chars
	*/
	int numOfBigChars; 
	/*!
	\brief Number of dec chars

	It contains number of randomized dec chars
	*/
	int numOfNumbers;
	/*!
	\brief Password length

	It contains length of 1 password
	*/
	int passLength;
	/*!
	\brief Num of passwords

	It contains number of passwords, needed to generate
	*/
	int numOfPasswords;
	/*!
	\brief Name of file

	It contains way to output file
	*/
	std::string filename;
	/*!
	\brief Making password function

	It's used to make one password 

	\code
	std::string PassGen::passGenerator() {
	std::string password = "";
	char a;
	for (int i = 0; i < numOfNumbers; ++i) {
		a = char(rand() % 10 + 48);
		password += a;
	}
	for (int i = numOfNumbers; i < numOfNumbers + numOfBigChars; ++i) {
		a = char(rand() % 26 + 65);
		password += a;
	}
	for (int i = numOfNumbers + numOfBigChars; i < passLength; ++i) {
		a = char(rand() % 26 + 97);
		password += a;
	}
	std::random_shuffle(password.begin(), password.end());
	return password;
	}
	\endcode
	*/
	std::string passGenerator();
	/*!
	\brief Making num of chars

	It's used to randomize numOfSmallChars, numOfBigChars, numOfNumbers

	\code
	void PassGen::numOfChars() {
	numOfSmallChars = rand() % passLength;
	int charRandEnd = passLength - numOfSmallChars;
	numOfBigChars = rand() % charRandEnd;
	numOfNumbers = passLength - numOfSmallChars - numOfBigChars;
	}
	\endcode
	*/
	void numOfChars();
	/*!
	\brief Checking function

	It's used to check password's triviality

	\code
	bool PassGen::check(std::string pass) {
	int l = 0;
	std::sort(pass.begin(), pass.end());
	for (int i = 0; i < pass.size() - 1; i++) {
		if (l >= 2)
			return 1;
		if (pass[i] == pass[i + 1])
			l++;
		else
			l = 0;
	}
	return 0;
	}
	\endcode
	*/
	bool check(std::string pass);
};

bool PassGen::check(std::string pass) {
	int l = 0;
	std::sort(pass.begin(), pass.end());
	for (int i = 0; i < pass.size() - 1; i++) {
		if (l >= 2)
			return 1;
		if (pass[i] == pass[i + 1])
			l++;
		else
			l = 0;
	}
	return 0;
}

int PassGen::makePasswordList() {
	std::ofstream outFile(filename);
	std::string passOut;
	for (int k = 0; k < numOfPasswords; k++) {
		numOfChars();
		passOut = passGenerator();
		if (check(passOut)) {
			k--;
			continue;
		}
		outFile << passOut << endl;
	}
	outFile.close();
	return 0;
}

std::string PassGen::passGenerator() {
	std::string password = "";
	char a;
	for (int i = 0; i < numOfNumbers; ++i) {
		a = char(rand() % 10 + 48);
		password += a;
	}
	for (int i = numOfNumbers; i < numOfNumbers + numOfBigChars; ++i) {
		a = char(rand() % 26 + 65);
		password += a;
	}
	for (int i = numOfNumbers + numOfBigChars; i < passLength; ++i) {
		a = char(rand() % 26 + 97);
		password += a;
	}
	std::random_shuffle(password.begin(), password.end());
	return password;
}

void PassGen::numOfChars() {
	numOfSmallChars = rand() % passLength;
	int charRandEnd = passLength - numOfSmallChars;
	numOfBigChars = rand() % charRandEnd;
	numOfNumbers = passLength - numOfSmallChars - numOfBigChars;
}
