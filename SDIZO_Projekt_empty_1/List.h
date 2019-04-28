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
	//WskaŸnik na g³owê(pierwszy element) listy
	static ListElement *head;
	//Metoda znajduj¹ca element przed elementem o wartoœci wskazanej jako argument funkcji, u¿ywana podczas usuwania elementów z listy
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

