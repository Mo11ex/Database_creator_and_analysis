#include "Functions.h"

void DataEntry(Data* (&d), int& n)
{
	Code codeProduct;
	Name nameProduct;
	ReleasePlan RPlan;
	FactRelease FRel;

	cout << "������� ������ �������: ";
	cin >> n;

	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "������� ��� ���������: ";
		cin >> codeProduct.CodeProduct;

		cout << "������� ������������ ���������: ";
		cin >> nameProduct.NameProduct;

		cout << "������� ���� ������� �� ���������: ";
		cin >> RPlan.Q1 >> RPlan.Q2 >> RPlan.Q3 >> RPlan.Q4;

		cout << "������� ����������� ������ �� ���������: ";
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
		cout << "������ �������!" << endl;
	}
	else
		cout << "������ �������� ������!" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "������ �" << i + 1 << endl;

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

	cout << "�������� ����� ������� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;

	if (_n >= 0 && _n < n) {
		cout << "������� ����� ��� ���������: ";
		cin >> codeProduct.CodeProduct;

		cout << "������� ����� ������������ ���������: ";
		cin >> nameProduct.NameProduct;

		cout << "������� ����� ���� ������� �� ���������: ";
		cin >> RPlan.Q1 >> RPlan.Q2 >> RPlan.Q3 >> RPlan.Q4;

		cout << "������� ����� ����������� ������ �� ���������: ";
		cin >> FRel.QF1 >> FRel.QF2 >> FRel.QF3 >> FRel.QF4;

		d[_n].DataEntry(codeProduct, nameProduct, RPlan, FRel);
	}
	else
		cout << "����� ��� ����� �� �����!" << endl;
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

	cout << "������� ����� ��� ���������: ";
	cin >> codeProduct.CodeProduct;

	cout << "������� ����� ������������ ���������: ";
	cin >> nameProduct.NameProduct;

	cout << "������� ����� ���� ������� �� ���������: ";
	cin >> RPlan.Q1 >> RPlan.Q2 >> RPlan.Q3 >> RPlan.Q4;

	cout << "������� ����� ����������� ������ �� ���������: ";
	cin >> FRel.QF1 >> FRel.QF2 >> FRel.QF3 >> FRel.QF4;

	d[size].DataEntry(codeProduct, nameProduct, RPlan, FRel);

	cout << "������ ���������!" << endl;

	delete[] buf;
}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	Data* buf = new Data[n];

	cout << "�������� ����� ������� �������� (�� 1 �� " << n << "): ";
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

		cout << "������ �������!" << endl;
	}
	else
		cout << "����� ����� �� �����!" << endl;

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

	cout << "������ ��������������!\n���������� ����������: " << numOfSorted << endl;
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
		cout << "������ �������� �����!" << endl;

	cout << "������ ���������!" << endl;

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
				cout << "��� ������ " << d[i].GetnameProduct().NameProduct << " ������� ����������� ������ ������ ��������� �������� ������� ����� ��� �� 10%" << endl;
			}
			else
				cout << "��� ������ " << d[i].GetnameProduct().NameProduct << " �� ����)" << endl;

			if ((d[i].GetFRealese().QF1 > d[i].GetFRealese().QF2) && (d[i].GetFRealese().QF2 > d[i].GetFRealese().QF3) && (d[i].GetFRealese().QF3 > d[i].GetFRealese().QF4))
				cout << "��� ������ " << d[i].GetnameProduct().NameProduct << " ����������� ������ �� ��������� �������." << endl;
		}
	}
	else
		cout << "������ �������� ������!" << endl;

	reading.close();
}
