#pragma once

struct Element
{
	char data;
	Element* Next;
};

class List
{
	Element* Head;
	Element* Tail;
	int Count;
public:
	List();
	void Add(char data);
	void CertainAdd(char data, int ind);
	void Del();
	void CertainDel(int ind); //WIP
	void DelAll();
	void Print();
	int GetCount();
	int SeekPos(char data);
	~List();
};