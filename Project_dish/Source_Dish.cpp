#include<iostream>
#include<Windows.h>
#include<fstream>

using namespace std;

#include "Dish.h" // файл з класом Dish

void testCinCout(); // функція для тестування вводу-виводу з консолі
void testFile(); // функція для тестування вводу-виводу з файлу

int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "===== FRENDLY METHODS =====\n";

	testCinCout(); // тестування вводу-виводу з консолі
	testFile(); // тестування вводу-виводу з файлу

	const char* fileName = "menu.txt"; // ім'я файлу для збереження даних
	ofstream outFile(fileName); // відкриття файлу для запису даних
	Dish asado("Asado", "Argentina", 89, 10.5); // створення об'єкту класу Dish
	Dish feijoada("Feijoada", "Brazil", 37, 9.8); // створення об'єкту класу Dish
	Dish moloheya("Moloheya", "Egypt", 55, 11.4); // створення об'єкту класу Dish
	Dish dumplings("Dumplings", "Ukraine", 100, 25); // створення об'єкту класу Dish
	outFile << asado << feijoada << moloheya << dumplings; // запис об'єктів класу Dish у файл
	outFile.close(); // закриття файлу після запису даних
	Dish temp; // створення об'єкту класу Dish для тимчасового збереження даних
	ifstream myReader(fileName); // відкриття файлу для читання даних
	myReader >> temp; // читання даних з файлу у об'єкт класу Dish
	cout << temp << "\n"; // виведення даних з об'єкту класу Dish на консоль
	myReader >> temp; // читання наступного об'єкту класу Dish з файлу
	cout << temp << "\n"; // виведення даних з об'єкту класу Dish на консоль

	while (!myReader.eof()) // цикл для читання всіх об'єктів класу Dish з файлу до кінця файлу
	{
		Dish item; // створення об'єкту класу Dish для тимчасового збереження даних
		myReader >> item; // читання даних з файлу у об'єкт класу Dish
		if (myReader.eof()) // перевірка на кінець файлу
			break; // вихід з циклу, якщо досягнуто кінець файлу
		cout << item << "\n"; // виведення даних з об'єкту класу Dish на консоль
	}

	return 0;
}
void testCinCout() // функція для тестування вводу-виводу з консолі
{
	Dish nasi_lemak;
	//nasi_lemak.print();
	cout << "by default\n";
	cout << nasi_lemak << "\n";

	Dish herring("herring", "Netherlands", 50, 36.5);
	cout << "constructor with parameters\n";
	cout << herring << "\n";

	Dish chicken(herring);
	cout << "copy constructor\n";
	cout << chicken << "\n";

	Dish pizza;
	cout << "Input pizza info: \n";
	cin >> pizza;

	cout << "info what you print: \n";
	cout << pizza << "\n";
}
void testFile()
{
	ofstream outFile("dish.txt"); // відкриття файлу для запису даних
	outFile << "the weather is good :)\n";
	outFile.close(); // закриття файлу після запису даних

	ifstream readFile("dish.txt"); // відкриття файлу для читання даних
	char ch[100]; // створення масиву символів для збереження рядка з файлу
	readFile.getline(ch, 100, '\n'); // читання рядка з файлу у масив символів до символу нового рядка або до досягнення 100 символів
	cout << "File DATA <-+-> " << ch << endl;
	readFile.close(); // закриття файлу після читання даних
}