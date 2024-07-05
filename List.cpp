#include "List.h"
#include <iostream>
using namespace std;

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	DelAll();
}

int List::GetCount()
{
	return Count;
}

int List::SeekPos(char data)
{
	Element* temp = Head;
	int pos = 1;
	while (temp != 0)
	{
		if (temp->data == data)
		{
			return pos;
		}
		temp = temp->Next;
		pos++;
	}
	return 0;
}

void List::Add(char data)
{
	Element* temp = new Element;
	temp->data = data;
	temp->Next = NULL;
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	else {
		Head = Tail = temp;
	}
	Count++;
}

void List::CertainAdd(char data, int ind)
{
	if (ind > Count)
	{
		cout << "Unable to add." << endl;
		return;
	}
	Element* temp = new Element;
	temp->data = data;
	temp->Next = NULL;
	Element* temp1 = new Element;
	temp1 = Head;
	if (ind == 1)
	{
		temp->Next = temp1;
		Head = temp;
	}
	else if (ind == Count)
	{
		Add(data);
	}
	else
	{
		Element* temp2 = new Element;
		for (int i = 1; i < ind; i++)
		{
			if (i == ind - 1)
			{
				temp2->data = temp1->data;
				temp2->Next = temp1->Next;
				break;
			}
			temp1 = temp1->Next;
		}
		temp->Next = temp2->Next;
		temp1->Next = temp;
	}
	Count++;
}

void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
	Count--;
}

void List::CertainDel(int ind)
{
	if (ind > Count || Count == 0)
	{
		cout << "Unable to delete." << endl;
		return;
	}
	Element* temp1 = new Element;
	temp1 = Head;
	if (ind == 1)
	{
		Del();
	}
	else if (ind == Count)
	{
		for (int i = 1; i <= ind; i++)
		{
			if (i == ind)
			{
				delete temp1;
				break;
			}
			temp1 = temp1->Next;
		}
		temp1 = Head;
		for (int i = 1; i < ind; i++)
		{
			if (i == ind - 1)
			{
				temp1->Next = NULL;
				Tail->Next = temp1;
				Tail = temp1;
				break;
			}
			temp1 = temp1->Next;
		}
	}
	else
	{
		Element* temp2 = new Element;
		for (int i = 1; i <= ind; i++)
		{
			if (i == ind)
			{
				temp2->Next = temp1->Next;
				break;
			}
			temp1 = temp1->Next;
		}
		delete temp1;
		temp1 = Head;
		for (int i = 1; i < ind; i++)
		{
			if (i == ind - 1)
			{
				temp1->Next = temp2->Next;
				break;
			}
			temp1 = temp1->Next;
		}
	}
	Count--;
}

void List::DelAll()
{
	while (Head != 0)
		Del();
}

void List::Print()
{
	Element* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}
	cout << "\n\n";
}