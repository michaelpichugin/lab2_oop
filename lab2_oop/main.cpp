#include "encoder.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	encoder ed;
	int choice = 0;
	while (true)
	{
		ed.menu(choice);

		switch (ed.getChoice())
		{
		case 1: // Прочитать файл и закодировать
		{
			system("cls");
			string filename = "";
			cout << "Введите имя файла для чтения (например, file.txt): ";
			cin >> filename;
			if (filename != "")
			{
				system("cls");
				cout << "Считанный файл (" + filename + "):" << endl << endl << ed.ReadFile(filename);
				ed.EncodeAndWriteToFile(ed.ReadFile(filename));
				cout << endl << endl << "Закодировано (file.binary):" << endl;
				cout << endl << ed.ReadFile("file.binary") << endl << endl;
				system("pause");
				system("cls");
			}
			break;
		}
		case 2: // Прочитать файл и декодировать
		{
			system("cls");
			string filename = "";
			cout << "Введите имя файла для чтения (например, file.binary): ";
			cin >> filename;
			if (filename != "")
			{
				system("cls");
				cout << "Считанный файл (" + filename + "):" << endl << endl << ed.ReadFile(filename);
				cout << endl << endl << "Декодировано (" + filename + "):" << endl;
				cout << endl << ed.ReadAndDecodeFile(filename) << endl << endl;
				ed.WriteToFile("SaveDecode.txt", ed.ReadAndDecodeFile(filename));
				system("pause");
				system("cls");
			}
			break;
		}
		case 3: // Завершить работу
		{
			return 0;
		}
		default:
		{
			system("cls");
			cout << "Выбор неверный. Повторите ввод." << endl;
			system("pause");
			system("cls");
			choice = 0;
			if (char(cin.peek()) == '\n')
				cin.ignore();

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(32767, '\n');
			}
			break;
		}
		}
	}

	system("pause");
	return 0;
}