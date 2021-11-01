#include "encoder.h"

encoder::encoder()
{
	readfile = "", 
	decode = "", 
	encode = "", 
	choice = 0;
}
// �����������
string encoder::TextToBinaryString(string words)
{
	encode = "";
	try
	{
		for (char& _char : words)
			// �������� ������, ����������� ��� � �������� ������
			// � ������������ � string
			encode += bitset<8>(_char).to_string();
	}
	catch (...)
	{

	}
	return encode;
}
// �������������
string encoder::BinaryToTextString(string data)
{
	std::stringstream sstream(data);
	decode = "";
	try
	{
		// �������� ������ �� ������/�����
		while (sstream.good())
		{
			std::bitset<8> bits; // ������� ��������� �� 8 �����
			sstream >> bits; // ��������� ���������
			// �������� ��� ������� � ������������� � ������
			decode += char(bits.to_ulong());
		}
	}
	catch (...)
	{

	}
	return decode;
}

void encoder::EncodeAndWriteToFile(string data)
{
	try
	{
		ofstream out;
		out.open("file.binary");
		if (out.is_open())
			out << TextToBinaryString(data);
		out.close();
	}
	catch (...)
	{

	}
}

string encoder::ReadAndDecodeFile(string name)
{
	string result = "";
	std::string line;
	try
	{
		std::ifstream in(name);
		if (in.is_open())
			while (getline(in, line))
				result += line;
		in.close();
	}
	catch (...)
	{

	}
	return BinaryToTextString(result);
}

void encoder::WriteToFile(string filename, string data)
{
	try
	{
		ofstream out;
		out.open(filename);
		if (out.is_open())
			out << data;
		out.close();
	}
	catch (...)
	{

	}
}

string encoder::ReadFile(string name)
{
	readfile = "";
	std::string line;
	try
	{
		std::ifstream in(name);
		if (in.is_open())
			while (getline(in, line))
				readfile += line;
		in.close();
	}
	catch (...)
	{

	}
	return readfile;
}

void encoder::menu(int& choice)
{
	cout << "1. ��������� ���� � ������������" << endl;
	cout << "2. ��������� ���� � ������������" << endl;
	cout << "3. ��������� ������" << endl;
	cout << "�����: "; cin >> this->choice;
	choice = this->choice;
}

string encoder::getReadFile()
{
	return readfile;
}

string encoder::getDecode()
{
	return decode;
}

string encoder::getEncode()
{
	return encode;
}

int encoder::getChoice()
{
	return choice;
}
