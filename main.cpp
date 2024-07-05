#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List list;
	list.Add('H');
	list.Add('E');
	list.Add('L');
	list.Add('0');
	list.Print();
	list.CertainAdd('L', 3);
	list.Print();
	list.CertainDel(5);
	list.Add('A');
	list.Print();
	cout << "Position of \'L\' = " << list.SeekPos('L') << endl;
	cout << "count = " << list.GetCount() << endl;
}