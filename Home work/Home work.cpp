#include "Functions.h"

int _stateMenu;
void Menu()
{
    cout << "Выберите действие: " << endl
        << "(0) Выход из программы" << endl
        << "(1) Ввод даных" << endl
        << "(2) Вывод данных" << endl
        << "(3) Изменение данных" << endl
        << "(4) Добавление данных" << endl
        << "(5) Удаление данных" << endl
        << "(6) Сортировка данных" << endl
        << "(7) Сохраение данных" << endl
        << "(8) Анализ данных" << endl
        << "Ваш выбор: ";
    cin >> _stateMenu;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Menu();
    int _actions;
    string fileName;

    int _size = 0;
    Data* d = new Data[_size];

    while (_stateMenu != 0)
    {
        switch (_stateMenu)
        {
        case 1:
            system("cls");

            cout << "Ввести данные вручную (1) или считать из файла (2)?: ";
            cin >> _actions;

            system("cls");

            if (_actions == 1) {
                DataEntry(d, _size);
            }
            else {
                cout << "Введите название файла: ";
                cin >> fileName;

                DataReading(d, _size, fileName);
            }
            system("pause");
            system("cls");
            Menu();
            break;
        /////////////////////////////////////////////////////////
        case 2:
            system("cls");

            if (_size != 0)
                Print(d, _size);
            else
                cout << "Данные пусты!" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        //////////////////////////////////////////////////////////
        case 3:
            system("cls");

            if (_size != 0)
                DataChange(d, _size);
            else
                cout << "Данные пусты!" << endl;

            system("pause");
            system("cls");
            Menu();
            break;
        ////////////////////////////////////////////////////////////
        case 4:
            system("cls");

            if (_size != 0)
                AddData(d, _size);
            else
                cout << "Данные пусты!" << endl;

            system("pause");
            system("cls");
            Menu();
            break;
        //////////////////////////////////////////////////////////////
        case 5:
            system("cls");

            if (_size != 0)
                DeleteData(d, _size);
            else
                cout << "Данные пусты!" << endl;

            system("pause");
            system("cls");
            Menu();
            break;
        ///////////////////////////////////////////////////////////////
        case 6:
            system("cls");

            if (_size != 0)
                SortingData(d, _size);
            else
                cout << "Данные пусты!" << endl;

            system("pause");
            system("cls");
            Menu();
            break;
         ///////////////////////////////////////////////////////////////
        case 7:
            system("cls");

            if (_size != 0) {
                cout << "Введите название файла: " << endl;
                cin >> fileName;

                SaveData(d, _size, fileName);
            }
            else
                cout << "Данные пусты!" << endl;

            system("pause");
            system("cls");
            Menu();
            break;
         ///////////////////////////////////////////////////////////////
        case 8:
            system("cls");

            cout << "Введите название файла: ";
            cin >> fileName;

            Analys(d, _size, fileName);

            system("pause");
            system("cls");
            Menu();
            break;
            ////////////////////////////////////////////////////////////
        default:
            cout << "Пункт меню введён не верно!" << endl;
            system("pause");
            system("cls");
            Menu();
            break;
        }
    }

    system("cls");
    cout << "Работа завершена!" << endl;
    system("pause");
}

