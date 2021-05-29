/*
Варіант 1.
В текстовому файлі записана звітна відомість результатів екзаменаційної сесії
студентської групи, яка для кожного студента містить прізвище, ініціали і оцінки з п’яти
предметів.
Скласти програму, за допомогою якої можна створювати, переглядати та
поповнювати список і отримувати:
 список всіх студентів;
 список студентів, що склали іспити тільки на «5»;
 список студентів, що мають трійки;
 список студентів, що мають хоч одну двійку;
 список студентів, що мають більш, ніж одну двійку;
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Rep // Звіт 
{
	char surname[100]; // прізвище
	char init[100]; // ініціали
	double fiz; // оцінки з 5 предметів
	double math;
	double prog;
	double web;
	double elect;
};

void Create(char* fname);
void Print(char* fname);
void StudMax(char* fname);
bool StudThree(char* fname);
void StudTwo(char* fname);

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	char ch;
	char fname[61];
	string store;
	do
	{
		cout << endl;
		cout << "Зробіть вибір:" << endl;
		cout << "[1] - запис даних" << endl;
		cout << "[2] - список всіх студентів;" << endl;
		cout << "[3] - список студентів, що склали іспити тільки на «5»;" << endl;
		cout << "[4] - список студентів, що мають трійки;" << endl;
		cout << "[5] - список студентів, що мають одну двійку;" << endl << endl;

		cout << "[0] - завершення роботи." << endl << endl;
		cout << "Ваш вибір: "; cin >> ch;
		switch (ch)
		{
		case '0':
			break;
		case '1':
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			Create(fname);
			break;
		case '2':
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			Print(fname);
			break;
		case '3':
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << "Студенти, що склали всі екзамени на макс. бал: " << endl;
			StudMax(fname);
			break;
		case '4':
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << "Студенти, що мають хоча б одну трійку: " << endl;
			StudThree(fname);
			break;
		case '5':
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << "Студенти, що мають одну двійку: " << endl;
			StudTwo(fname);
			break;
		default:
			cout << "Помилка вводу! ";
		}
	} while (ch != '0');
	return 0;
}

void Create(char* fname) // створення файлу з введених рядків
{
	ofstream fout(fname); // відкрили файл для запису
	char ch; // відповідь користувача – чи продовжувати введення
	string s; // введений користувачем рядок
	Rep student;
	int i = 0;
	do
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cout << "Прізвище студента: "; cin >> student.surname;
		cout << "Ініціали: "; cin >> student.init;
		cout << "Оцінка з Фізики: "; cin >> student.fiz;
		if (student.fiz > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			student.fiz = 5;
		}
		if (student.fiz < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			student.fiz = 0;
		}
		cout << "Оцінка з Математики: "; cin >> student.math;
		if (student.math > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			student.math = 5;
		}
		if (student.math < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			student.math = 0;
		}
		cout << "Оцінка з Програмування: "; cin >> student.prog;
		if (student.prog > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			student.prog = 5;
		}
		if (student.prog < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			student.prog = 0;
		}
		cout << "Оцінка з Веб - дизайну: "; cin >> student.web;
		if (student.web > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			student.web = 5;
		}
		if (student.web < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			student.web = 0;
		}
		cout << "Оцінка з Електромеханіки: "; cin >> student.elect;
		if (student.elect > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			student.elect = 5;
		}
		if (student.elect < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			student.elect = 0;
		}
		if (!fout.write((char*)&student, sizeof(Rep)))
		{
			cerr << "Помилка запису у файл." << endl;
		}
		cout << "Продовжити? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
	fout.close();
}

void Print(char* fname) // виведення файлу на екран
{
	ifstream fin(fname); // відкрили файл для зчитування
	if (fin.fail())
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Rep student;
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int i = 0;
	while (fin.read((char*)&student, sizeof(Rep)))
	{
		cout << "|" << setw(3) << i + 1 << setw(3) << "|";
		cout << setw(6) << student.surname << setw(7) << "|";
		cout << setw(6) << student.init << setw(7) << "|";
		cout << setw(5) << student.fiz << setw(6) << "|";
		cout << setw(7) << student.math << setw(8) << "|";
		cout << setw(9) << student.prog << setw(9) << "|";
		cout << setw(8) << student.web << setw(9) << "|";
		cout << setw(10) << student.elect << setw(10) << "|";
		cout << endl;
	}
	cout << "=================================================================================================================="
		<< endl;
	cout << endl;
	fin.close();
}



void StudMax(char* fname)
{
	ifstream fin(fname); // відкрили файл для зчитування
	if (fin.fail())
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Rep student;
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int k = 0;
	int i = 0;
	while (fin.read((char*)&student, sizeof(Rep)))
	{
		if (student.math == 5.0 &&
			student.fiz == 5.0 &&
			student.prog == 5.0 &&
			student.web == 5.0 &&
			student.elect == 5.0) { // первірка на студента, який здав все на макс. бал
			cout << "|" << setw(3) << i + 1 << setw(3) << "|";
			cout << setw(6) << student.surname << setw(7) << "|";
			cout << setw(6) << student.init << setw(7) << "|";
			cout << setw(5) << student.fiz << setw(6) << "|";
			cout << setw(7) << student.math << setw(8) << "|";
			cout << setw(9) << student.prog << setw(9) << "|";
			cout << setw(8) << student.web << setw(9) << "|";
			cout << setw(10) << student.elect << setw(10) << "|";
			cout << endl;
			k++;
		}
	}
	if (k == 0) {
		cout << endl;
		cout << "Схоже, що по заданому фільтру студентів не було знайдено." << endl << endl;
	}
	cout << "=================================================================================================================="
		<< endl;
	cout << endl;
	fin.close();
}

bool StudThree(char* fname) {
	ifstream fin(fname); // відкрили файл для зчитування
	if (fin.fail())
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return false;
	}
	cout << endl;
	Rep student;
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int k = 0;
	int i = 0;
	while (fin.read((char*)&student, sizeof(Rep)))
	{
		if (student.math == 3.0 ||
			student.fiz == 3.0 ||
			student.prog == 3.0 ||
			student.web == 3.0 ||
			student.elect == 3.0) { // первірка на студента, який має хоча б одну 3
			cout << "|" << setw(3) << i + 1 << setw(3) << "|";
			cout << setw(6) << student.surname << setw(7) << "|";
			cout << setw(6) << student.init << setw(7) << "|";
			cout << setw(5) << student.fiz << setw(6) << "|";
			cout << setw(7) << student.math << setw(8) << "|";
			cout << setw(9) << student.prog << setw(9) << "|";
			cout << setw(8) << student.web << setw(9) << "|";
			cout << setw(10) << student.elect << setw(10) << "|";
			cout << endl;
			k++;
		}
	}
	if (k == 0) {
		cout << endl;
		cout << "Схоже, що по заданому фільтру студентів не було знайдено." << endl << endl;
		fin.close();
		return false;
	}
	cout << "=================================================================================================================="
		<< endl;
	cout << endl;
	fin.close();
	return true;
}

void StudTwo(char* fname) {
	ifstream fin(fname); // відкрили файл для зчитування
	if (fin.fail())
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Rep student;
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int i = 0;
	int k = 0; // оголошення лічильника двійок
	while (fin.read((char*)&student, sizeof(Rep)))
	{
		if (student.elect == 2.0) {
			k++;
		}
		if (student.web == 2.0) {
			k++;
		}
		if (student.prog == 2.0) {
			k++;
		}
		if (student.fiz == 2.0) {
			k++;
		}
		if (student.math == 2.0) {
			k++;
		}
		if (k == 1) { // перевірка на кількість двійок
			cout << "|" << setw(3) << i + 1 << setw(3) << "|";
			cout << setw(6) << student.surname << setw(7) << "|";
			cout << setw(6) << student.init << setw(7) << "|";
			cout << setw(5) << student.fiz << setw(6) << "|";
			cout << setw(7) << student.math << setw(8) << "|";
			cout << setw(9) << student.prog << setw(9) << "|";
			cout << setw(8) << student.web << setw(9) << "|";
			cout << setw(10) << student.elect << setw(10) << "|";
			cout << endl;
		}
		k = 0;
	}
	cout << "=================================================================================================================="
		<< endl;
	cout << endl;
	fin.close();
}