#include "Heap.h"
using namespace std;

Heap* Heap::instance;
int Heap::tableSize;
int* Heap::table;
int Heap::heapSize;

Heap::Heap(string data)
{
	std::ifstream heaptxt(data);
	int i = 0;
	table = NULL;
	for (std::string line; getline(heaptxt, line);) {
		if (i == 0) {
			int valuesCount = stoi(line);
			heapSize = valuesCount;

			tableSize = FindTableSize(valuesCount);
			table = new int[tableSize];
		}
		else if ((i - 1) < tableSize)
			table[i - 1] = stoi(line);
		else
			break;
		i++;
	}
	BuildMaxHeap();
}

int Heap::FindTableSize(int values_count)
{
	int sum = 0;
	for (int i = 0; sum < values_count; i++) {
		sum += pow(2, i);
	}
	return sum;
}

Heap* Heap::GetInstance() 
{
	if (instance == NULL)
		instance = new Heap();
	return instance;
}

Heap * Heap::RefreshInstance()
{
	instance = new Heap();
	return instance;
}

int Heap::GetLeftSon(int parent_index)
{
	return 2 * parent_index + 1;
}

int Heap::GetRightSon(int parent_index)
{
	return 2 * parent_index + 2;
}

int Heap::GetParent(int son_index)
{
	return ((son_index - 1) / 2);
}

int Heap::GetLeftSonValue(int parent_index)
{
	return table[2 * parent_index + 1];
}

int Heap::GetRightSonValue(int parent_index)
{
	return table[2 * parent_index + 2];
}

int Heap::GetParentValue(int son_index)
{
	return table[((son_index - 1) / 2)];
}


void Heap::Show(std::string sp, std::string sn, int v)
{
	std::string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218;
	cr[1] = 196;
	cl[0] = 192;
	cl[1] = 196;
	cp[0] = 179;

	std::string s;

	if (v < heapSize)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		Show(s + cp, cr, 2 * v + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << table[v] << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		Show(s + cp, cl, 2 * v + 1);
	}
}

bool Heap::Find(int value, int index)
{
	bool leftSearch = false;
	bool rightSearch = false;
	if (value == table[index])
		return true;
	if (value > table[index])
		return false;
	int left = GetLeftSon(index);
	int right = GetRightSon(index);
	if (left < heapSize && value <= table[left])
		 leftSearch = Find(value, left);
    if (right < heapSize && value <= table[right])
		 rightSearch = Find(value, right);
	return (leftSearch || rightSearch);
}

int Heap::GetIndex(int value)
{
	for (int i = 0; i < heapSize; i++) {
		if (value == table[i])
			return i;
	}
}
void Heap::MaxHeapify(int index) 
{
	int left = GetLeftSon(index);
	int right = GetRightSon(index);
	int largest = 0;
	if (left <= heapSize && table[left] > table[index])
		largest = left;
	else
		largest = index;
	if (right <= heapSize &&  table[right] > table[largest])
		largest = right;
	if (largest != index) {
		Switch(index, largest);
		MaxHeapify(largest);
	}
}

void Heap::BuildMaxHeap()
{
	for (int i = (heapSize - 2) / 2; i >= 0; i--)
	{
		MaxHeapify(i);
	}
}


void Heap::Switch(int index_one, int index_two) 
{
	int tmp = table[index_one];
	table[index_one] = table[index_two];
	table[index_two] = tmp;
}

void Heap::Add(int value)
{
	if (heapSize != tableSize) 
	{
		int i = heapSize;
		int parentindex = 0;
		table[i] = value;
		while (i >= 0) {
			parentindex = GetParent(i);
			if (table[i] > table[parentindex]) {
				i = parentindex;
			}
			else {
				heapSize++;
				BuildMaxHeap();
				cout << "Element zosta³ dodany" << endl;
				break;
			}
		}
	}
	else {
		cout << "Kopiec jest pe³ny" << endl;
	}
}

void Heap::Delete(int value)
{
	int i = 0;
	if (Find(value)) {
		int index = GetIndex(value);
		int * tmp = new int[tableSize];
		while (i < index) {
			tmp[i] = table[i];
			i++;
		}
		tmp[i] = table[i + 1];
		i++;
		while (i < heapSize - 1) {
			tmp[i] = table[i + 1];
			i++; 
		}
		delete[] table;
		table = tmp;
		heapSize--;
		BuildMaxHeap();
		cout << "Element zosta³ usuniêty" << endl;
	}
	else
		cout << "Nie ma takiej wartoœci w kopcu" << endl;
}