/**
\mainpage Password Generator
\author Kireev 18PI1
*/

#include "PasGen.h"

int main()
{
	setlocale(LC_ALL, ".1251");
	srand(time(NULL));
	int length, num;
	std::string filename, input;
	try {
		cout << "������� ����� ������ ��� ���������: ";
		cin >> input;
		length = stoi(input);
		if (length < 1 || length > 124)
			throw 1;
		cout << "������� ���������� ������� ��� ���������: ";
		cin >> input;
		num = stoi(input);
		if (num < 1)
			throw 2;
		cout << "����� ������������� �������: " << num << "." << endl;
		cout << "������� ��� ����� ��� ������: ";
		cin >> filename;
		PassGen pass(length, num, filename);
		int er = 1;
		er = pass.makePasswordList();
		if (er == 0)
			cout << "������ ������� ������������� � �������� � ���� " << filename << "" << endl;
		return 0;
	}
	catch (int error) {
		if (error == 1) {
			cout << "������ ����� ������" << endl;
			return 1;
		}
		if (error == 2) {
			cout << "������ ���������� �������" << endl;
			return 2;
		}
	}
}