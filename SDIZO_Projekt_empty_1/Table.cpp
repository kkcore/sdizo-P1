#include "Table.h"


Table*  Table::instance;
int Table::size;
int* Table::table;

Table::Table(std::string data)
{
	std::ifstream tabletxt(data);
	int i = 0;
    table = NULL;
	for (std::string line; getline(tabletxt, line);) {
		if (i == 0) {
			size = stoi(line);
			table = new int[size];
		}
		else
			table[i - 1] = stoi(line);
		i++;
	}
}

Table* Table::GetInstance()
{
	if (instance == NULL)
		instance = new Table();
	return instance;
}

void Table::Show() {
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << table[i] << ", ";

	}
	cout << "]" << endl;
}

void Table::Delete(int index)
{
	if (index< 0 || index >= size) {
		cout << "Podano z³y indeks" << endl;
		return;
	}
	int * tmp = new int[size-1];
	memmove(table + index, table + index + 1, (size - index - 1) * sizeof(int) );
	memcpy(tmp, table, (size - 1) * sizeof(int));
	delete[] table;
	table = tmp;
	size--;
	cout << "Element zosta³ usuniêty" << endl;
}

void Table::Add(int index, int value)
{
	if (index< 0 || index > size) {
		cout << "Podano z³y indeks" << endl;
		return;
	}
	int* tmp = new int[size + 1];
	int i = 0;
	while (i < index) {
		tmp[i] = table[i];
		i++;
	}
	tmp[i] = value;
	i++;
	while (i < size + 1) {
		tmp[i] = table[i - 1];
		i++;
	}
	delete[] table;
	table = tmp;
	size++;
	cout << "Element zosta³ wstawiony" << endl;
}

bool Table::Find(int value)
{
	for (int i = 0; i < size; i++) {
		if (value == table[i])
			return true;
	}
	return false;
}


