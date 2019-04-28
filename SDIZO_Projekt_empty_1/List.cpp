#include "List.h"

struct ListElement listelement;
List* List::instance;
ListElement* List::head;

List::List(std::string data)
{
	std::ifstream listtxt(data);
	int i = 0;
	head = NULL;
	for (std::string line; getline(listtxt, line);) {
		if (i >= 1)
			Push(stoi(line));
		i++;
	}
}

List * List::GetInstance()
{
	if (instance == NULL)
		instance = new List();
	return instance;
}

List * List::RefreshInstance()
{
	instance = new List();
	return instance;
}

void List::Push(int value)
{
	ListElement *element;
	element = new ListElement;
	element->value = value;
	element->next = head;
	head = element;
}

void List::Show()
{
	ListElement* headpointer = head;
	for (int i = 0; headpointer; headpointer = headpointer->next)
		std::cout << headpointer->value << std::endl;
}

ListElement* List::GetElement(int index) {
	ListElement* headpointer = head;
	try {
		for (int i = 0; i < index; i++) {
			headpointer = headpointer->next;
		}
	}
	catch (...) {
		return nullptr;
	}
	return headpointer;
}

ListElement* List::Find(int value)
{
	ListElement* headpointer = head;
	for (int i = 0; headpointer; headpointer = headpointer->next) {
			if (headpointer->value == value)
				return headpointer;
	}
	return nullptr;
}

ListElement* List::FindOneBefore(int value) 
{
	ListElement* headpointer = head;
	//Pierwsza iteracja po headzie, w przypadku tej funkcji nie znajduje siê w pêtli, wiêc napisa³em warunek osobno
	if (head->value == value)
		return head;
	//Pêtla przeszukuj¹ca czy nastêpny element z listy ma zadan¹ wartoœæ (nastêpny, poniewa¿ zwracamy element, który jest przed nim, aby
	//móc manipulowaæ jego w³aœciwoœci¹ next w funkcji usuwaj¹cej
	for (int i = 0; headpointer; headpointer = headpointer->next) {
		if (headpointer->next != nullptr && headpointer->next->value == value)
			return headpointer;
	}
	return nullptr;
}
void List::Add(int valueToFind, int valueToPut)
{
	ListElement* element = Find(valueToFind);
	if (element != nullptr) {
		ListElement* elementToPut;
		elementToPut = new ListElement;
		elementToPut->value = valueToPut;
		elementToPut->next = element->next;
		element->next = elementToPut;
	}
	else
		Push(valueToPut);

	std::cout << "Element zosta³ dodany" << std::endl;
}

void List::Delete(int value)
{
	ListElement* oneElementBefore = FindOneBefore(value);
	//Przypadek gdyby funkcja oneElementBefore
	//zwróci³a heada, wtedy nie jest to jeden element przed kolejnym elementem i trzeba po prostu zmieniaæ heada
	//na kolejny element listy
	if (oneElementBefore == head) {
		ListElement* headToDelete = head;
		head = head->next;
		delete headToDelete;
		std::cout << "Element zosta³ usuniêty" << std::endl;
	}
	//Standardowy przypadek, w else zwrócenie komunikatu, ¿e nie ma w liœcie wartoœci, któr¹ podaliœmy w argumencie funkcji (wpisaliœmy w konsolê)
	else if (oneElementBefore) {
		ListElement* elementToDelete = oneElementBefore->next;
		oneElementBefore->next = elementToDelete->next;
		delete elementToDelete;
		std::cout << "Element zosta³ usuniêty" << std::endl;
	}
	else
		std::cout << "Nie ma takiej wartoœci w liœcie" << std::endl;
}
