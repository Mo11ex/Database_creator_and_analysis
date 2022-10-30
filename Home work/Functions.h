#pragma once

#include "Data.h"

void DataEntry(Data* (&d), int& n);
void DataReading(Data* (&d), int& n, string fileName);
void Print(Data* d, int n);
void DataChange(Data* d, int n);
void Copy(Data* d_n, Data* d_o, int n);
void AddData(Data* (&d), int& n);
void DeleteData(Data* (&d), int& n);
void SortingData(Data* d, int n);
void SaveData(Data* d, int n, string fileName);
void SaveData2(Data* d, int n);
void Analys(Data* d, int n);
void Analys(Data* (&d), int& n, string fileName);