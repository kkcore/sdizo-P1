#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Table.h"
#include "List.h"
#include "Heap.h"
#include "TRBTree.h"
#include "Timer.h"
using namespace std;

void ShowMenu(int);
void GenerateData(string path, int count, bool random = 1);
void ShowMainMenu();
void Test();
LONGLONG GetTime();

LARGE_INTEGER performanceCountStart, performanceCountEnd;
Table* table;
List* list;
Heap* heap;
TRBTree* trbtree;
Timer* timer;

int main()
{
	srand(time(NULL));
	if (setlocale(LC_ALL, "") == NULL)
		cout << "Uwaga, Nie mo¿na wyœwietliæ polskich znaków\n\n\n\n" << endl;
	//ShowMainMenu(); 
	Test();
	//getchar();
}

void ShowMenu(int input)
{
	//system("cls");
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
			if (dataStructureInput == 6) {
				ShowMainMenu();
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
			if (dataStructureInput == 6) {
				ShowMainMenu();
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
			if (dataStructureInput == 6) {
				ShowMainMenu();
			}
		}
		if (input == 4) {
			if (dataStructureInput == 1) {
				trbtree = new TRBTree();
				cout << "Drzewo czerwono-czarne zosta³o wczytane" << endl;
				continue;
			}
			if (dataStructureInput == 2) {
				cout << "Podaj wartoœæ, któr¹ chcesz wstawiæ" << endl;
				cin >> argumentone;
				trbtree->Add(argumentone);
				continue;
			}
			if (dataStructureInput == 3) {
				cout << "Podaj wartoœæ, któr¹ chcesz usun¹æ" << endl;
				cin >> argumentone;
				trbtree->Delete(trbtree->Find(argumentone));
				continue;
			}
			if (dataStructureInput == 4) {
				cout << "Podaj wartoœæ elementu do znalezienia" << endl;
				cin >> argumentone;
				bool found = trbtree->Find(argumentone);
				if (found)
					cout << "Element znajduje siê w drzewie czerwono-czarnym" << endl;
				else
					cout << "Element nie znajduje siê w drzewie czerwono-czarnym" << endl;
				continue;
			}
			if (dataStructureInput == 5) {
				setlocale(LC_ALL, "C");
				trbtree->Show();
				setlocale(LC_ALL, "");
				continue;
			}
			if (dataStructureInput == 6) {
				ShowMainMenu();
			}
		}
	}
}


void GenerateData(string path, int count, bool random) {
	ofstream ofile;
	ofile.open(path);
	ofile << count << endl;
	if (random) {
		for (int i = 0; i < count; i++) {
			ofile << (rand() % 1000000) << endl;
		}
	}
	else {
		for (int i = 0; i < count; i++) {
			ofile << i << endl;
		}
	}
}

void ShowMainMenu() {
	system("cls");
	int input = 0;
	cout << endl;
	cout << "Wybierz strukturê danych" << endl;
	cout << "1. Tablica" << endl;
	cout << "2. Lista" << endl;
	cout << "3. Kopiec binarny" << endl;
	cout << "4. Drzewo czerwono-czarne" << endl;
	cout << "5. Zakoñcz program" << endl;
	cin >> input;
	if (input > 6 || input < 0) {
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
		case 5: exit(0); break;
		}
	}
}

void Test() {
	//Pêtla zmieniaj¹ca liczbê elementów struktury i generuj¹ca data od nowa
	ofstream wyniki;
	wyniki.open("C:\\Users\\oszus\\source\\repos\\SDIZO_Projekt1\\wyniki.txt");
	int count = 10;
	table = Table::GetInstance();
	list = List::GetInstance();
	heap = Heap::GetInstance();
	trbtree = new TRBTree();
	while (count < 1000000) {
		count *= 10;
		GenerateData("C:\\Users\\oszus\\source\\repos\\SDIZO_Projekt1\\data.txt", count);
		//Odœwie¿enie instancji (ponowne pobranie danych)
		table = Table::RefreshInstance();
		list = List::RefreshInstance();
		heap = Heap::RefreshInstance();
		timer = Timer::GetInstance();
		trbtree = new TRBTree();
		//Testy dla list i tablic dodawanie/usuwanie/wyszukiwanie elementow w trzech miejscach (poczatek/koniec/srodek) tablicy/listy
		int half = count / 2;
		int end = count - 1;
		//Testy dla tablicy dodawanie, usuwanie wyszukiwanie
		//Na pocz¹tku tablicy
		performanceCountStart = timer->StartTimer();
		table->Add(0, -1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "TABLICA dodawanie pocz¹tek iloœæ elementów: "<< count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		table->Find(-1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "TABLICA wyszukiwanie pocz¹tek iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		table->Delete(0);
		performanceCountEnd = timer->EndTimer();
		wyniki << "TABLICA usuwanie pocz¹tek iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		//Na œrodku tablicy
		performanceCountStart = timer->StartTimer();
		table->Add(half, -1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "TABLICA dodawanie œrodek iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		table->Find(-1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "TABLICA wyszukiwanie œrodek iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		table->Delete(half);
		performanceCountEnd = timer->EndTimer();
		wyniki << "TABLICA usuwanie œrodek iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		//Na koñcu tablicy
		performanceCountStart = timer->StartTimer();
		table->Add(end, -1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "TABLICA dodawanie koniec iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		table->Find(-1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "TABLICA wyszukiwanie koniec iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		table->Delete(end);
		performanceCountEnd = timer->EndTimer();
		wyniki << "TABLICA usuwanie koniec iloœæ elementów: " << count << " Czas: " << GetTime() << endl;

		ListElement* firstElement = list->GetElement(0);
		ListElement* halfElement = list->GetElement(half);
		ListElement* endElement = list->GetElement(end);
		//Testy dla listy (dodawanie, usuwanie, wyszukiwanie)
		//Na pocz¹tku listy
		performanceCountStart = timer->StartTimer();
		list->Add(firstElement->value, -1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "LISTA dodawanie poczatek iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		list->Find(-1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "LISTA wyszukiwanie pocz¹tek iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		list->Delete(-1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "LISTA usuwanie pocz¹tek iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		//Na œrodku listy
		performanceCountStart = timer->StartTimer();
		list->Add(halfElement->value, -1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "LISTA dodawanie œrodek iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		list->Find(-1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "LISTA wyszukiwanie œrodek iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		list->Delete(-1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "LISTA usuwanie œrodek iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		//Na koñcu listy
		performanceCountStart = timer->StartTimer();
		list->Add(endElement->value, -1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "LISTA dodawanie koniec iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		list->Find(-1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "LISTA wyszukiwanie koniec iloœæ elementów: " << count << " Czas: " << GetTime() << endl;
		performanceCountStart = timer->StartTimer();
		list->Delete(-1);
		performanceCountEnd = timer->EndTimer();
		wyniki << "LISTA usuwanie koniec iloœæ elementów: " << count << " Czas: " << GetTime() << endl;

		for (int i = 0; i < 100; i++) {
			int x = rand() % 1000000;
			performanceCountStart = timer->StartTimer();
			heap->Add(x);
			performanceCountEnd = timer->EndTimer();
			wyniki << "KOPIEC dodawanie iloœæ elementów: " << count << " Czas: " << GetTime() << " LOSOWE ELEMENTY" << endl;
			performanceCountStart = timer->StartTimer();
			heap->Find(x);
			performanceCountEnd = timer->EndTimer();
			wyniki << "KOPIEC wyszukiwanie iloœæ elementów: " << count << " Czas: " << GetTime() << " LOSOWE ELEMENTY" << endl;
			performanceCountStart = timer->StartTimer();
			heap->Delete(x);
			performanceCountEnd = timer->EndTimer();
			wyniki << "KOPIEC usuwanie iloœæ elementów: " << count << " Czas: " << GetTime() <<" LOSOWE ELEMENTY"<< endl;
			performanceCountStart = timer->StartTimer();
			trbtree->Add(x);
			performanceCountEnd = timer->EndTimer();
			wyniki << "DRZEWO CZERWONO-CZARNE dodawanie iloœæ elementów: " << count << " Czas: " << GetTime() << " LOSOWE ELEMENTY" << endl;
			performanceCountStart = timer->StartTimer();
			trbtree->Find(x);
			performanceCountEnd = timer->EndTimer();
			wyniki << "DRZEWO CZERWONO-CZARNE wyszukiwanie iloœæ elementów: " << count << " Czas: " << GetTime() << " LOSOWE ELEMENTY" << endl;
			performanceCountStart = timer->StartTimer();
			trbtree->Delete(trbtree->Find(x));
			performanceCountEnd = timer->EndTimer();
			wyniki << "DRZEWO CZERWONO-CZARNE usuwanie iloœæ elementów: " << count << " Czas: " << GetTime() << " LOSOWE ELEMENTY" << endl;
		}
	}
	count = 10;
	while (count < 1000000) {
		count *= 10;
		GenerateData("C:\\Users\\oszus\\source\\repos\\SDIZO_Projekt1\\data.txt", count, false);
		heap = Heap::GetInstance();
		trbtree = new TRBTree();
		for (int i = 0; i < 100; i++) {
			int x = rand() % 1000000;
			performanceCountStart = timer->StartTimer();
			heap->Add(x);
			performanceCountEnd = timer->EndTimer();
			wyniki << "KOPIEC dodawanie iloœæ elementów: " << count << " Czas: " << GetTime() << " UPORZADKOWANE ELEMENTY" << endl;
			performanceCountStart = timer->StartTimer();
			heap->Find(x);
			performanceCountEnd = timer->EndTimer();
			wyniki << "KOPIEC wyszukiwanie iloœæ elementów: " << count << " Czas: " << GetTime() << " UPORZADKOWANE ELEMENTY" << endl;
			performanceCountStart = timer->StartTimer();
			heap->Delete(x);
			performanceCountEnd = timer->EndTimer();
			wyniki << "KOPIEC usuwanie iloœæ elementów: " << count << " Czas: " << GetTime() << " UPORZADKOWANE ELEMENTY" << endl;
			performanceCountStart = timer->StartTimer();
			trbtree->Add(x);
			performanceCountEnd = timer->EndTimer();
			wyniki << "DRZEWO CZERWONO-CZARNE dodawanie iloœæ elementów: " << count << " Czas: " << GetTime() << " UPORZADKOWANE ELEMENTY" << endl;
			performanceCountStart = timer->StartTimer();
			trbtree->Find(x);
			performanceCountEnd = timer->EndTimer();
			wyniki << "DRZEWO CZERWONO-CZARNE wyszukiwanie iloœæ elementów: " << count << " Czas: " << GetTime() << " UPORZADKOWANE ELEMENTY" << endl;
			performanceCountStart = timer->StartTimer();
			trbtree->Delete(trbtree->Find(x));
			performanceCountEnd = timer->EndTimer();
			wyniki << "DRZEWO CZERWONO-CZARNE usuwanie iloœæ elementów: " << count << " Czas: " << GetTime() << " UPORZADKOWANE ELEMENTY" << endl;
		}
	}
}

LONGLONG GetTime() {
	return performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
}