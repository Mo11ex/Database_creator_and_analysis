#include "Data.h"

Data::Data()
{
	codeProduct.CodeProduct = 0;

	nameProduct.NameProduct = "";

	RPlan.Q1 = 0;
	RPlan.Q2 = 0;
	RPlan.Q3 = 0;
	RPlan.Q4 = 0;

	FRealese.QF1 = 0;
	FRealese.QF2 = 0;
	FRealese.QF3 = 0;
	FRealese.QF4 = 0;
}

Data::Data(Code codeProduct_, Name nameProduct_, ReleasePlan RPlan_, FactRelease FRealese_)
{
	codeProduct.CodeProduct = codeProduct_.CodeProduct;

	nameProduct.NameProduct = nameProduct_.NameProduct;

	RPlan.Q1 = RPlan_.Q1;
	RPlan.Q2 = RPlan_.Q2;
	RPlan.Q3 = RPlan_.Q3;
	RPlan.Q4 = RPlan_.Q4;

	FRealese.QF1 = FRealese_.QF1;
	FRealese.QF2 = FRealese_.QF2;
	FRealese.QF3 = FRealese_.QF3;
	FRealese.QF4 = FRealese_.QF4;
}

Data::~Data()
{
}

void Data::Print()
{
	cout << "Шифр продукции: " << codeProduct.CodeProduct << endl;
	cout << "Наименование продукции: " << nameProduct.NameProduct << endl;
	cout << "План выпска: " << "\n1 кв: " << RPlan.Q1 <<
		"\n2 кв: " << RPlan.Q2 <<
		"\n3 кв: " << RPlan.Q3 <<
		"\n4 кв: " << RPlan.Q4 << endl;
	cout << "Фактический выпуск: " << "\n1 кв: " << FRealese.QF1 <<
		"\n2 кв: " << FRealese.QF2 <<
		"\n3 кв: " << FRealese.QF3 <<
		"\n4 кв: " << FRealese.QF4 << endl;
}

void Data::DataEntry(Code codeProduct_, Name nameProduct_, ReleasePlan RPlan_, FactRelease FRealese_)
{
	codeProduct.CodeProduct = codeProduct_.CodeProduct;

	nameProduct.NameProduct = nameProduct_.NameProduct;

	RPlan.Q1 = RPlan_.Q1;
	RPlan.Q2 = RPlan_.Q2;
	RPlan.Q3 = RPlan_.Q3;
	RPlan.Q4 = RPlan_.Q4;

	FRealese.QF1 = FRealese_.QF1;
	FRealese.QF2 = FRealese_.QF2;
	FRealese.QF3 = FRealese_.QF3;
	FRealese.QF4 = FRealese_.QF4;
}

Data& Data::operator=(Data d_o)
{
	this->codeProduct.CodeProduct = d_o.codeProduct.CodeProduct;

	this->nameProduct.NameProduct = d_o.nameProduct.NameProduct;

	this->RPlan.Q1 = d_o.RPlan.Q1;
	this->RPlan.Q2 = d_o.RPlan.Q2;
	this->RPlan.Q3 = d_o.RPlan.Q3;
	this->RPlan.Q4 = d_o.RPlan.Q4;

	this->FRealese.QF1 = d_o.FRealese.QF1;
	this->FRealese.QF2 = d_o.FRealese.QF2;
	this->FRealese.QF3 = d_o.FRealese.QF3;
	this->FRealese.QF4 = d_o.FRealese.QF4;

	return *this;
}
