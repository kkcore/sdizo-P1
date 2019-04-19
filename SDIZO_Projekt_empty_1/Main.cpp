//Projekt ze wzgl�du na swoj� specyfik� zosta� stworzony we wzorcu projektowym (przez niekt�rych uznawany za antywzorzec...) Singleton
//To znaczy, �e wszystkie zmienne oraz metody powsta�ych obiekt�w s� statyczne, przez co w programie mo�e znajdowa� si� tylko jedna instancja
//Danego obiektu (np. listy) na raz, t� instancj� otrzymuje si� za pomoc� metody GetInstance, kt�ra jest zaimplementowana w ten sam spos�b
//w ka�dej klasie programu. Ka�da klasa posiada r�wnie� statyczne pole instance, w kt�rym przechowywana jest instancja obiektu uzyskana
//za pomoc� metody GetInstance
//Jakub Oszust kwiecie� 2019
#include <iostream>
#include "Table.h"
#include "List.h"
#include "Heap.h"
#include "TRBTree.h"
using namespace std;

void ShowMenu(int);
Table* table;
List* list;
Heap* heap;
TRBTree* trbtree;

int main()
{
	if (setlocale(LC_ALL, "") == NULL)
		cout << "Uwaga, Nie mo�na wy�wietli� polskich znak�w\n\n\n\n" << endl;
	int input = 0;
	cout << "Wybierz struktur� danych" << endl;
	cout << "1. Tablica" << endl;
	cout << "2. Lista" << endl;
	cout << "3. Kopiec binarny" << endl;
	cout << "4. Drzewo czerwono-czarne" << endl;
	cout << "5. Drzewo AVL" << endl;
	cout << "6. Zako�cz program" << endl;
	cin >> input;
	if (/*input > 6 ||*/ input < 1) {
		cout << "Wybra�e� z�� liczb�, wpisz j� ponownie" << endl;
		cin >> input;
	}
	else {
		switch (input) {
		case 1: ShowMenu(1);
			break;
		case 2: ShowMenu(2);
			break;
		case 3: ShowMenu(3);
			break;
		case 4: ShowMenu(4);
			break;
		case 5: ShowMenu(5);
			break;
		case 6: ShowMenu(6);
			break;
		}
	}
}

void ShowMenu(int input)
{
	switch (input) {
	case 1:
		cout << "Tablica" << endl;
		break;
	case 2:
		cout << "Lista" << endl;
		break;
	case 3:
		cout << "Kopiec binarny" << endl;
		break;
	case 4: cout << "Drzewo czerwono-czarne" << endl;
		break;
	case 5: cout << "Drzewo AVL" << endl;
		break;
	}
	cout << "1. Zbuduj z pliku" << endl;
	cout << "2. Wstaw element" << endl;
	cout << "3. Usu� element" << endl;
	cout << "4. Wyszukaj element" << endl;
	cout << "5. Wy�wietl" << endl;
	cout << "6. Wyjd� do g��wnego menu" << endl;
	int dataStructureInput = 0;
	int argumentone = 0;
	int argumenttwo = 0;
	while (true) {
		cin >> dataStructureInput;
		if (input == 1) {
			if (dataStructureInput == 1) {
				table = Table::GetInstance();
				cout << "Tablica zosta�a zbudowana" << endl;
				continue;
			}
			if (dataStructureInput == 2) {
				cout << "Podaj indeks elementu tablicy, kt�ry chcesz wstawi�" << endl;
				cin >> argumentone;
				cout << "Podaj warto�� elementu tablicy" << endl;
				cin >> argumenttwo;
				table->Add(argumentone, argumenttwo);
				continue;
			}
			if (dataStructureInput == 3) {
				cout << "Podaj indeks elementu tablicy, kt�ry chcesz usun��"<<endl;
				cin >> argumentone;
				table->Delete(argumentone);
				continue;
			}
			if (dataStructureInput == 4) {
				cout << "Podaj warto�� elementu do wyszukania" << endl;
				cin >> argumentone;
				if (table->Find(argumentone))
					cout << "Element jest w tablicy" << endl;
				else
					cout << "Elementu nie ma w tablicy" << endl;
				continue;
			}
			if (dataStructureInput == 5) {
				table->Show();
				continue;
			}
		}
		if (input == 2) {
			if (dataStructureInput == 1) {
				list = List::GetInstance();
				cout << "Lista zosta�a zbudowana" << endl;
				continue;
			}
			if (dataStructureInput == 2) {
				cout << "Podaj warto��, za kt�r� chcesz wstawi� element" << endl;
				cin >> argumentone;
				cout << "Podaj warto��, kt�r� chcesz wstawi�" << endl;
				cin >> argumenttwo;
				list->Add(argumentone, argumenttwo);
				continue;
			}
			if (dataStructureInput == 3) {
				cout << "Podaj warto�� elementu do usuni�cia" << endl;
				cin >> argumentone;
				list->Delete(argumentone);
				continue;
			}
			if (dataStructureInput == 4) {
				cout << "Podaj warto�� elementu do znalezienia" << endl;
				cin >> argumentone;
				if (list->Find(argumentone)) {
					cout << "Element znajduje si� w li�cie" << endl;
				}
				else
					cout << "Element nie znajduje si� w li�cie" << endl;
				continue;

			}
			if (dataStructureInput == 5) {
				list->Show();
				continue;

			}
		}
		if (input == 3) {
			if (dataStructureInput == 1) {
				heap = Heap::GetInstance();
				cout << "Kopiec zosta� wczytany" << endl;
				continue;
			}
			if (dataStructureInput == 2) {
				cout << "Podaj warto��, kt�r� chcesz wstawi�" << endl;
				cin >> argumentone;
				heap->Add(argumentone);
				continue;
			}
			if (dataStructureInput == 3){
				cout << "Podaj warto��, kt�r� chcesz usun��" << endl;
				cin >> argumentone;
				heap->Delete(argumentone);
				continue;
			}
			if (dataStructureInput == 4) {
				cout << "Podaj warto�� elementu do znalezienia" << endl;
				cin >> argumentone;
				bool found = heap->Find(argumentone, 0);
				if (found)
					cout << "Element znajduje si� w kopcu" << endl;
				else
					cout << "Element nie znajduje si� w kopcu" << endl;
				continue;
			}
			if (dataStructureInput == 5) {
				setlocale(LC_ALL, "C");
				heap->Show();
				setlocale(LC_ALL, "");
				continue;
			}
		}
		//if (input == 4) {
		//	if (dataStructureInput == 1) {
		//		rbtree = RBTree::GetInstance();
		//		cout << "Drzewo czerwono-czarne zosta�o wczytane" << endl;
		//		continue;
		//	}
		//	if (dataStructureInput == 2) {
		//		cout << "Podaj warto��, kt�r� chcesz wstawi�" << endl;
		//		cin >> argumentone;
		//		rbtree->Add(argumentone);
		//		continue;
		//	}
		//	if (dataStructureInput == 3) {
		//		cout << "Podaj warto��, kt�r� chcesz usun��" << endl;
		//		cin >> argumentone;
		//		rbtree->Delete(argumentone);
		//		continue;
		//	}
		//	if (dataStructureInput == 4) {
		//		cout << "Podaj warto�� elementu do znalezienia" << endl;
		//		cin >> argumentone;
		//		bool found = rbtree->Find(argumentone);
		//		if (found)
		//			cout << "Element znajduje si� w drzewie czerwono-czarnym" << endl;
		//		else
		//			cout << "Element nie znajduje si� w drzewie czerwono-czarnym" << endl;
		//		continue;
		//	}
		//	if (dataStructureInput == 5) {
		//		setlocale(LC_ALL, "C");
		//		rbtree->Show();
		//		setlocale(LC_ALL, "");
		//		continue;
		//	}
		//}
		if (input == 9) {
			if (dataStructureInput == 1) {
				
				cout << "Drzewo czerwono-czarne zosta�o wczytane" << endl;
				continue;
			}
			if (dataStructureInput == 2) {
				cout << "Podaj warto��, kt�r� chcesz wstawi�" << endl;
				cin >> argumentone;
				trbtree->insertRBT(argumentone);
				continue;
			}
			if (dataStructureInput == 3) {
				cout << "Podaj warto��, kt�r� chcesz usun��" << endl;
				cin >> argumentone;
				trbtree->removeRBT(trbtree->findRBT(argumentone));
				continue;
			}
			if (dataStructureInput == 4) {
				cout << "Podaj warto�� elementu do znalezienia" << endl;
				cin >> argumentone;
				bool found = trbtree->findRBT(argumentone);
				if (found)
					cout << "Element znajduje si� w drzewie czerwono-czarnym" << endl;
				else
					cout << "Element nie znajduje si� w drzewie czerwono-czarnym" << endl;
				continue;
			}
			if (dataStructureInput == 5) {
				setlocale(LC_ALL, "C");
				trbtree->print();
				setlocale(LC_ALL, "");
				continue;
			}
		}
	}
}
