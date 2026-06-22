#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Dish             // клас страви
{
private:               // поля класу
	string name;       // назва страви
	string country;    // країна походження
	int price;         // ціна страви
	double weight;     // вага страви
public:                // конструктори класу
	Dish()             // конструктор за замовчуванням
	{
		this->name = "";
		this->country = "";
		this->price = 18;
		this->weight = 10.1;
	}
	Dish(const string name, const string country,
		const int price, const double weight) // конструктор з параметрами
	{
		this->name = name;
		this->country = country;
		this->price = price;
		this->weight = weight;
	}
	Dish(const Dish& d) // конструктор копіювання
	{
		this->name = d.name;
		this->country = d.country;
		this->price = d.price;
		this->weight = d.weight;
	}
	void print() // метод виводу інформації про об'єкт
	{
		cout << "___________________\n";
		cout << "Name = " << this->name << "\n";
		cout << "Phone  = " << this->country << "\n";
		cout << "price = " << this->price << "\n";
		cout << "weight = " << this->weight << "\n";
		cout << "___________________\n";
	}
	friend ostream& operator << (ostream& out, const Dish& d) // перевантаження оператора виводу
	{
		out << d.name << "\t" << d.country << endl << "price:  $"
			<< d.price << "\t" << d.weight;
		return out;
	}
	friend istream& operator >> (istream& in, Dish& d) // перевантаження оператора вводу
	{
		in.seekg(0);                    // повертаємося на початок потоку вводу
		char tmp[100];                  // тимчасовий масив для зчитування рядків

		cout << "input name: ";
		in.getline(tmp, 100, '\n'); // зчитуємо рядок до символу '\n' або до 100 символів
		string str = tmp;           // перетворюємо масив символів на рядок
		if (!str.empty())           // перевіряємо, чи рядок не порожній
			d.name = tmp;           // присвоюємо значення полю name

		cout << "input phone: ";
		in.getline(tmp, 100, '\n');
		str = tmp;
		if (!str.empty())
			d.country = tmp;

		cout << "input age: ";
		in >> d.price;

		cout << "input weight: ";
		in >> d.weight;

		return in;               // повертаємо посилання на потік вводу
	}
	friend ofstream& operator << (ofstream& fout, const Dish& d) // перевантаження оператора виводу для файлу
	{
		fout << d.name << "\n"
			<< d.country << "\n"
			<< d.price << "\n"
			<< d.weight << "\n";
		return fout;
	}
	friend ifstream& operator >> (ifstream& fin, Dish& d) // перевантаження оператора вводу для файлу
	{

		char tmp[100];                 // тимчасовий масив для зчитування рядків

		fin.getline(tmp, 100, '\n');   // зчитуємо рядок до символу '\n' або до 100 символів
		string str = tmp;              // перетворюємо масив символів на рядок
		if (!str.empty())              // перевіряємо, чи рядок не порожній
			d.name = tmp;              // присвоюємо значення полю name

		fin.getline(tmp, 100, '\n');
		str = tmp;
		if (!str.empty())
			d.country = tmp;

		fin >> d.price;
		fin.getline(tmp, 100, '\n');

		fin >> d.weight;
		fin.getline(tmp, 100, '\n');

		return fin;                 // повертаємо посилання на потік вводу
	}
};

