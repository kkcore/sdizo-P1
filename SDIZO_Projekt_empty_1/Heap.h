#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>
//Kopiec binarny typu MAX (w korzeniu jest najwi�ksza warto��)
class Heap
{
private:
	Heap(std::string data = "C:\\Users\\oszus\\source\\repos\\SDIZO_Projekt1\\data.txt");
	static Heap* instance;
	static int tableSize;
	static int* table;
	static int heapSize;
	//Funkcja do sumowania pot�g dw�jki (liczba element�w
	//drzewa na kolejnych poziomach to kolejne pot�gi dw�jk
	//potrzebna do ustalenia maksymalnego rozmiaru kopca
	//dla danej ilo�ci element�w
	static int FindTableSize(int valueCount);
	static int GetLeftSon(int parent_index);
	static int GetRightSon(int parent_index);
	static int GetParent(int son_index);
	static int GetLeftSonValue(int parent_index);
	static int GetRightSonValue(int parent_index);
	static int GetParentValue(int son_index);
	static void Switch(int index_one, int index_two);
	//Funkcja przywracaj�ca w�asno�ci kopca dla danego
	//w�z�a
	static void MaxHeapify(int index);
	//Funkcja buduj�ca kopiec
	static void BuildMaxHeap();
	//Funkcja do znalezienia indeksu danej warto�ci
	static int GetIndex(int value);
public:
	static Heap* GetInstance();
	static Heap* RefreshInstance();
	static void Show(std::string sp = "", std::string sn = "", int v = 0);
	static void Delete(int value);
	static void Add(int value);
	//Drugi argument w funkcji, jest dlatego �e funkcja
	//jest wykorzystywana w paru miejscach i nie zawsze
	//powinna wypisywa� powiadomienie o tym, �e element
	//zosta� znaleziony
	static bool Find(int value, int index = 0);

};

