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
		cout << "Введите длину пароля для генерации: ";
		cin >> input;
		length = stoi(input);
		if (length < 1 || length > 124)
			throw 1;
		cout << "Введите количество паролей для генерации: ";
		cin >> input;
		num = stoi(input);
		if (num < 1)
			throw 2;
		cout << "Будет сгенерировано паролей: " << num << "." << endl;
		cout << "Введите имя файла для записи: ";
		cin >> filename;
		PassGen pass(length, num, filename);
		int er = 1;
		er = pass.makePasswordList();
		if (er == 0)
			cout << "Пароли успешно сгенерированы и записаны в файл " << filename << "" << endl;
		return 0;
	}
	catch (int error) {
		if (error == 1) {
			cout << "Ошибка длины пароля" << endl;
			return 1;
		}
		if (error == 2) {
			cout << "Ошибка количества паролей" << endl;
			return 2;
		}
	}
}