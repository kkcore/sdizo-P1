#pragma once
#include <iostream>
#include <fstream>
#include <string>
struct ListElement {
	int value;
	ListElement *next;
};
class List
{
private:
	List(std::string data = "C:\\Users\\oszus\\source\\repos\\SDIZO_Projekt1\\data.txt");
	static List* instance;
	//Wska�nik na g�ow�(pierwszy element) listy
	static ListElement *head;
	//Metoda znajduj�ca element przed elementem o warto�ci wskazanej jako argument funkcji, u�ywana podczas usuwania element�w z listy
	static ListElement* FindOneBefore(int value);
public:
	static List* GetInstance();
	static List* RefreshInstance();
	static void Push(int value);
	static void Show();
	static ListElement* Find(int value);
	static ListElement* GetElement(int index);
	static void Add(int valueToFind, int valueToPut);
	static void Delete(int value);

};

