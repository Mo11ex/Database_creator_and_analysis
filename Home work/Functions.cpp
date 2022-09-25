#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	Code codeProduct;
	Name nameProduct;
	ReleasePlan RPlan;
	FactRelease FRel;

	cout << "Введите размер массива: ";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите код продукции: ";
		cin >> codeProduct.CodeProduct;

		cout << "Введите наименование продукции: ";
		cin >> nameProduct.NameProduct;

		cout << "Введите план выпуска по кварталам: ";
		cin >> RPlan.Q1 >> RPlan.Q2 >> RPlan.Q3 >> RPlan.Q4;

		cout << "Введите фактический выпуск по кварталам: ";
		cin >> FRel.QF1 >> FRel.QF2 >> FRel.QF3 >> FRel.QF4;

		d[i].DataEntry(codeProduct, nameProduct, RPlan, FRel);

		cout << "_________________________________________________\n";
	}
}

void DataReading(Data* (&d), int& n, string fileName)
{
	ifstream reading(fileName);

	if (reading) {
		Code codeProduct;
		Name nameProduct;
		ReleasePlan RPlan;
		FactRelease FRel;

		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> codeProduct.CodeProduct;
			reading >> nameProduct.NameProduct;
			reading >> RPlan.Q1 >> RPlan.Q2 >> RPlan.Q3 >> RPlan.Q4;
			reading >> FRel.QF1 >> FRel.QF2 >> FRel.QF3 >> FRel.QF4;

			d[i].DataEntry(codeProduct, nameProduct, RPlan, FRel);
		}
		cout << "Данные считаны!" << endl;
	}
	else
		cout << "Ошибка открытия данных!" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Данные №" << i + 1 << endl;

		d[i].Print();
		cout << "_________________________________________________\n";
	}
}

void DataChange(Data* d, int n)
{
	Code codeProduct;
	Name nameProduct;
	ReleasePlan RPlan;
	FactRelease FRel;
	int _n;

	cout << "Ввведите номер нужного элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n) {
		cout << "Введите новый код продукции: ";
		cin >> codeProduct.CodeProduct;

		cout << "Введите новое наименование продукции: ";
		cin >> nameProduct.NameProduct;

		cout << "Введите новый план выпуска по кварталам: ";
		cin >> RPlan.Q1 >> RPlan.Q2 >> RPlan.Q3 >> RPlan.Q4;

		cout << "Введите новый фактический выпуск по кварталам: ";
		cin >> FRel.QF1 >> FRel.QF2 >> FRel.QF3 >> FRel.QF4;

		d[_n].DataEntry(codeProduct, nameProduct, RPlan, FRel);
	}
	else
		cout << "Номер был введён не верно!" << endl;
}

void Copy(Data* d_n, Data* d_o, int n)
{
	for (int i = 0; i < n; i++)
		d_n[i] = d_o[i];
}

void AddData(Data* (&d), int& n)
{
	Code codeProduct;
	Name nameProduct;
	ReleasePlan RPlan;
	FactRelease FRel;
	Data* buf = new Data[n];
	int size = n, new_size = ++n;

	Copy(buf, d, size);

	d = new Data[new_size];

	Copy(d, buf, size);

	cout << "Введите новый код продукции: ";
	cin >> codeProduct.CodeProduct;

	cout << "Введите новое наименование продукции: ";
	cin >> nameProduct.NameProduct;

	cout << "Введите новый план выпуска по кварталам: ";
	cin >> RPlan.Q1 >> RPlan.Q2 >> RPlan.Q3 >> RPlan.Q4;

	cout << "Введите новый фактический выпуск по кварталам: ";
	cin >> FRel.QF1 >> FRel.QF2 >> FRel.QF3 >> FRel.QF4;

	d[size].DataEntry(codeProduct, nameProduct, RPlan, FRel);

	cout << "Данные добавлены!" << endl;

	delete[] buf;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	cout << "Ввведите номер нужного элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n) {
		Copy(buf, d, n);
		int q = 0;
		n--;

		d = new Data[n];

		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				q++;
			}
		}

		cout << "Данные удвлены!" << endl;
	}
	else
		cout << "Номер введён не верно!" << endl;

	delete[] buf;
}

void SortingData(Data* d, int n)
{
	Data buf;
	int numOfSorted = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i].GetcodeProduct().CodeProduct > d[j].GetcodeProduct().CodeProduct) {
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;

				numOfSorted++;
			}
		}
	}

	cout << "Данные отсортированны!\nКоличество сортировок: " << numOfSorted << endl;
}

void SaveData(Data* d, int n, string fileName)
{
	ofstream record(fileName);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i].GetcodeProduct().CodeProduct << "\n";
			record << d[i].GetnameProduct().NameProduct << "\n";
			record << d[i].GetRPlan().Q1 << " " << d[i].GetRPlan().Q2 << " " << d[i].GetRPlan().Q3 << " " << d[i].GetRPlan().Q4 << "\n";
			record << d[i].GetFRealese().QF1 << " " << d[i].GetFRealese().QF2 << " " << d[i].GetFRealese().QF3 << " " << d[i].GetFRealese().QF4 << " ";

			if (i < n - 1)
				record << endl;

		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	cout << "Данные сохранены!" << endl;

	record.close();
}

void Analys(Data* (&d), int& n, string fileName)
{
	ifstream reading(fileName);

	if (reading) {
		Code codeProduct;
		Name nameProduct;
		ReleasePlan RPlan;
		FactRelease FRel;

		reading >> n;

		d = new Data[n];

		for (int i = 0; i < n; i++) {
			reading >> codeProduct.CodeProduct;
			reading >> nameProduct.NameProduct;
			reading >> RPlan.Q1 >> RPlan.Q2 >> RPlan.Q3 >> RPlan.Q4;
			reading >> FRel.QF1 >> FRel.QF2 >> FRel.QF3 >> FRel.QF4;

			d[i].DataEntry(codeProduct, nameProduct, RPlan, FRel);

			if (d[i].GetRPlan().Q1 + d[i].GetRPlan().Q2 + d[i].GetRPlan().Q3 + d[i].GetRPlan().Q4 > 1.1 * (d[i].GetFRealese().QF1 + d[i].GetFRealese().QF2 + d[i].GetFRealese().QF3 + d[i].GetFRealese().QF4))
			{
				cout << "Для товара " << d[i].GetnameProduct().NameProduct << " годовой фактический выпуск меньше планового годового выпуска более чем на 10%" << endl;
			}
			else
				cout << "Для товара " << d[i].GetnameProduct().NameProduct << " всё норм)" << endl;

			if ((d[i].GetFRealese().QF1 > d[i].GetFRealese().QF2) && (d[i].GetFRealese().QF2 > d[i].GetFRealese().QF3) && (d[i].GetFRealese().QF3 > d[i].GetFRealese().QF4))
				cout << "Для товара " << d[i].GetnameProduct().NameProduct << " фактический выпуск по кварталам убывает." << endl;
		}
	}
	else
		cout << "Ошибка открытия данных!" << endl;

	reading.close();
}
