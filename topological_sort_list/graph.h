#pragma once
#include <iostream>

struct Trailer;

struct Lider
{
	int key, count;  //count -���������� �������� �����
	Lider* next;
	Trailer* tr;
	Lider() { key = count = 0; next = 0; tr = 0; };
	void AddTrailer(Lider *p);
	void DelTrailer(Lider *p);
	void ReduceCount();
	void IncreaseCount();
};

struct Trailer
{
	Lider* pointer;
	Trailer* next;
	Trailer() { pointer = 0; next = 0; };
};


struct Graph  //������ � ��������� �������
{
	Lider* head;

	Graph();
	~Graph();

	void AddToHead(int k);
	void AddToTail(Lider* q);
	void Del(Lider* q);  //���������� �������� ����, ��� Clear()
	void Exclude(Lider* q); //���������� ���� �� ������, 
	//��� ������������ �������������� ������
	Lider* FindKey(int k);
	Lider* FindCount(int x);

	int FormGraph();
	void SortGraph(Graph &);
	void Clear();
	bool Empty();
	void Print(int n);
};