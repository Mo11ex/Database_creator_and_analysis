#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

/*
	������:
	1.���� ���������
	2.������������ ���������
	3.���� ������� �� ���������
	4.����������� ������ �� ����������
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

//�������� ������
class Data
{
	//privat ����� ������(����)
private:
	Code codeProduct;
	Name nameProduct;
	ReleasePlan RPlan;
	FactRelease FRealese;

	//public ����� ������
public:
	Data();  //������ ������ ������
	Data(Code codeProduct_, Name nameProduct_, ReleasePlan RPlan_, FactRelease FRealese_);  //������ ������ � �����������
	~Data(); //������� ������

	void Print();
	void DataEntry(Code codeProduct_, Name nameProduct_, ReleasePlan RPlan_, FactRelease FRealese_); //����� ������

	Code GetcodeProduct() { return codeProduct; };
	Name GetnameProduct() { return nameProduct; };
	ReleasePlan GetRPlan() { return RPlan; };
	FactRelease GetFRealese() { return FRealese; };

	Data& operator = (Data d_o); //���������� ��������� =
};

