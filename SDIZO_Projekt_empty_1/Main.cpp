//Projekt ze wzglêdu na swoj¹ specyfikê zosta³ stworzony we wzorcu projektowym (przez niektórych uznawany za antywzorzec...) Singleton
//To znaczy, ¿e wszystkie zmienne oraz metody powsta³ych obiektów s¹ statyczne, przez co w programie mo¿e znajdowaæ siê tylko jedna instancja
//Danego obiektu (np. listy) na raz, tê instancjê otrzymuje siê za pomoc¹ metody GetInstance, która jest zaimplementowana w ten sam sposób
//w ka¿dej klasie programu. Ka¿da klasa posiada równie¿ statyczne pole instance, w którym przechowywana jest instancja obiektu uzyskana
//za pomoc¹ metody GetInstance
//Jakub Oszust kwiecieñ 2019
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
		cout << "Uwaga, Nie mo¿na wyœwietliæ polskich znaków\n\n\n\n" << endl;
	int input = 0;
	cout << "Wybierz strukturê danych" << endl;
	cout << "1. Tablica" << endl;
	cout << "2. Lista" << endl;
	cout << "3. Kopiec binarny" << endl;
	cout << "4. Drzewo czerwono-czarne" << endl;
	cout << "5. Drzewo AVL" << endl;
	cout << "6. Zakoñcz program" << endl;
	cin >> input;
	if (/*input > 6 ||*/ input < 1) {
		cout << "Wybra³eœ z³¹ liczbê, wpisz j¹ ponownie" << endl;
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
	cout << "3. Usuñ element" << endl;
	cout << "4. Wyszukaj element" << endl;
	cout << "5. Wyœwietl" << endl;
	cout << "6. WyjdŸ do g³ównego menu" << endl;
	int dataStructureInput = 0;
	int argumentone = 0;
	int argumenttwo = 0;
	while (true) {
		cin >> dataStructureInput;
		if (input == 1) {
			if (dataStructureInput == 1) {
				table = Table::GetInstance();
				cout << "Tablica zosta³a zbudowana" << endl;
				continue;
			}
			if (dataStructureInput == 2) {
				cout << "Podaj indeks elementu tablicy, który chcesz wstawiæ" << endl;
				cin >> argumentone;
				cout << "Podaj wartoœæ elementu tablicy" << endl;
				cin >> argumenttwo;
				table->Add(argumentone, argumenttwo);
				continue;
			}
			if (dataStructureInput == 3) {
				cout << "Podaj indeks elementu tablicy, który chcesz usun¹æ"<<endl;
				cin >> argumentone;
				table->Delete(argumentone);
				continue;
			}
			if (dataStructureInput == 4) {
				cout << "Podaj wartoœæ elementu do wyszukania" << endl;
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
				cout << "Lista zosta³a zbudowana" << endl;
				continue;
			}
			if (dataStructureInput == 2) {
				cout << "Podaj wartoœæ, za któr¹ chcesz wstawiæ element" << endl;
				cin >> argumentone;
				cout << "Podaj wartoœæ, któr¹ chcesz wstawiæ" << endl;
				cin >> argumenttwo;
				list->Add(argumentone, argumenttwo);
				continue;
			}
			if (dataStructureInput == 3) {
				cout << "Podaj wartoœæ elementu do usuniêcia" << endl;
				cin >> argumentone;
				list->Delete(argumentone);
				continue;
			}
			if (dataStructureInput == 4) {
				cout << "Podaj wartoœæ elementu do znalezienia" << endl;
				cin >> argumentone;
				if (list->Find(argumentone)) {
					cout << "Element znajduje siê w liœcie" << endl;
				}
				else
					cout << "Element nie znajduje siê w liœcie" << endl;
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
				cout << "Kopiec zosta³ wczytany" << endl;
				continue;
			}
			if (dataStructureInput == 2) {
				cout << "Podaj wartoœæ, któr¹ chcesz wstawiæ" << endl;
				cin >> argumentone;
				heap->Add(argumentone);
				continue;
			}
			if (dataStructureInput == 3){
				cout << "Podaj wartoœæ, któr¹ chcesz usun¹æ" << endl;
				cin >> argumentone;
				heap->Delete(argumentone);
				continue;
			}
			if (dataStructureInput == 4) {
				cout << "Podaj wartoœæ elementu do znalezienia" << endl;
				cin >> argumentone;
				bool found = heap->Find(argumentone, 0);
				if (found)
					cout << "Element znajduje siê w kopcu" << endl;
				else
					cout << "Element nie znajduje siê w kopcu" << endl;
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
		//		cout << "Drzewo czerwono-czarne zosta³o wczytane" << endl;
		//		continue;
		//	}
		//	if (dataStructureInput == 2) {
		//		cout << "Podaj wartoœæ, któr¹ chcesz wstawiæ" << endl;
		//		cin >> argumentone;
		//		rbtree->Add(argumentone);
		//		continue;
		//	}
		//	if (dataStructureInput == 3) {
		//		cout << "Podaj wartoœæ, któr¹ chcesz usun¹æ" << endl;
		//		cin >> argumentone;
		//		rbtree->Delete(argumentone);
		//		continue;
		//	}
		//	if (dataStructureInput == 4) {
		//		cout << "Podaj wartoœæ elementu do znalezienia" << endl;
		//		cin >> argumentone;
		//		bool found = rbtree->Find(argumentone);
		//		if (found)
		//			cout << "Element znajduje siê w drzewie czerwono-czarnym" << endl;
		//		else
		//			cout << "Element nie znajduje siê w drzewie czerwono-czarnym" << endl;
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
				
				cout << "Drzewo czerwono-czarne zosta³o wczytane" << endl;
				continue;
			}
			if (dataStructureInput == 2) {
				cout << "Podaj wartoœæ, któr¹ chcesz wstawiæ" << endl;
				cin >> argumentone;
				trbtree->insertRBT(argumentone);
				continue;
			}
			if (dataStructureInput == 3) {
				cout << "Podaj wartoœæ, któr¹ chcesz usun¹æ" << endl;
				cin >> argumentone;
				trbtree->removeRBT(trbtree->findRBT(argumentone));
				continue;
			}
			if (dataStructureInput == 4) {
				cout << "Podaj wartoœæ elementu do znalezienia" << endl;
				cin >> argumentone;
				bool found = trbtree->findRBT(argumentone);
				if (found)
					cout << "Element znajduje siê w drzewie czerwono-czarnym" << endl;
				else
					cout << "Element nie znajduje siê w drzewie czerwono-czarnym" << endl;
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
