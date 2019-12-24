#pragma once
#include <iostream>

struct Trailer;

struct Lider
{
	int key, count;  //count -количество входящих ребер
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


struct Graph  //список с фиктивной головой
{
	Lider* head;

	Graph();
	~Graph();

	void AddToHead(int k);
	void AddToTail(Lider* q);
	void Del(Lider* q);  //физическое удаление узла, для Clear()
	void Exclude(Lider* q); //исключение узла из списка, 
	//для формирования упорядоченного списка
	Lider* FindKey(int k);
	Lider* FindCount(int x);

	int FormGraph();
	void SortGraph(Graph &);
	void Clear();
	bool Empty();
	void Print(int n);
};