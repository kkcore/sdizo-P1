#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
class Table
{
private:
	static Table* instance;
	static int* table;
	static int size;
	Table(std::string data = "C:\\Users\\oszus\\source\\repos\\SDIZO_Projekt1\\table.txt");
public:

	static Table* GetInstance();
	static void Show();
	static void Delete(int index);
	static void Add(int index, int value);
	static bool Find(int value);
};

