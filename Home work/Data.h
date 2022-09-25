#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

/*
	Данные:
	1.Шифр продукции
	2.Наименование продукции
	3.План выпуска по кварталам
	4.Фактический выпуск по кварталлам
*/

struct Code
{
	int CodeProduct;
};

struct Name
{
	string NameProduct;
};

struct ReleasePlan
{
	int Q1, Q2, Q3, Q4;
};

struct FactRelease
{
	int QF1, QF2, QF3, QF4;
};

//прототип класса
class Data
{
	//privat часть класса(поля)
private:
	Code codeProduct;
	Name nameProduct;
	ReleasePlan RPlan;
	FactRelease FRealese;

	//public часть класса
public:
	Data();  //создаёт пустой объект
	Data(Code codeProduct_, Name nameProduct_, ReleasePlan RPlan_, FactRelease FRealese_);  //создаёт объект с параметрами
	~Data(); //Удаляет объект

	void Print();
	void DataEntry(Code codeProduct_, Name nameProduct_, ReleasePlan RPlan_, FactRelease FRealese_); //вывод данных

	Code GetcodeProduct() { return codeProduct; };
	Name GetnameProduct() { return nameProduct; };
	ReleasePlan GetRPlan() { return RPlan; };
	FactRelease GetFRealese() { return FRealese; };

	Data& operator = (Data d_o); //перегрузка оператора =
};

