#pragma once
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <bitset>
#include <fstream>
#include <limits>
using namespace std;

class encoder
{
public:
	encoder();
	string TextToBinaryString(string words); // Кодирование
	string BinaryToTextString(string data); // Декодирование
	void EncodeAndWriteToFile(string data); // Закодировать и записать в файл
	string ReadAndDecodeFile(string name); // Прочитать и декодировать файл
	void WriteToFile(string filename, string data); // Записать в файл
	string ReadFile(string name); // Прочитать файл
	void menu(int& choice);
	string getReadFile();
	string getDecode();
	string getEncode();
	int getChoice();
private:
	string readfile, decode, encode;
	int choice;
};

