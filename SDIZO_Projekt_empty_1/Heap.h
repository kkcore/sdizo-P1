#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <typeinfo>
//Kopiec binarny typu MAX (w korzeniu jest najwiêksza wartoœæ)
class Heap
{
private:
	Heap(std::string data = "C:\\Users\\oszus\\source\\repos\\SDIZO_Projekt1\\data.txt");
	static Heap* instance;
	static int tableSize;
	static int* table;
	static int heapSize;
	//Funkcja do sumowania potêg dwójki (liczba elementów
	//drzewa na kolejnych poziomach to kolejne potêgi dwójk
	//potrzebna do ustalenia maksymalnego rozmiaru kopca
	//dla danej iloœci elementów
	static int FindTableSize(int valueCount);
	static int GetLeftSon(int parent_index);
	static int GetRightSon(int parent_index);
	static int GetParent(int son_index);
	static int GetLeftSonValue(int parent_index);
	static int GetRightSonValue(int parent_index);
	static int GetParentValue(int son_index);
	static void Switch(int index_one, int index_two);
	//Funkcja przywracaj¹ca w³asnoœci kopca dla danego
	//wêz³a
	static void MaxHeapify(int index);
	//Funkcja buduj¹ca kopiec
	static void BuildMaxHeap();
	//Funkcja do znalezienia indeksu danej wartoœci
	static int GetIndex(int value);
public:
	static Heap* GetInstance();
	static Heap* RefreshInstance();
	static void Show(std::string sp = "", std::string sn = "", int v = 0);
	static void Delete(int value);
	static void Add(int value);
	//Drugi argument w funkcji, jest dlatego ¿e funkcja
	//jest wykorzystywana w paru miejscach i nie zawsze
	//powinna wypisywaæ powiadomienie o tym, ¿e element
	//zosta³ znaleziony
	static bool Find(int value, int index = 0);

};

