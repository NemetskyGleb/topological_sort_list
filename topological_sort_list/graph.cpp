#include "graph.h"
#include <iostream>

void Lider::AddTrailer(Lider *p) {
	if (tr == 0) {
		tr = new Trailer;
		tr->pointer = p;
	}
	else {
		Trailer *tr1;
		tr1 = new Trailer;
		tr1->pointer = p;
		tr1->next = tr->next;
		tr->next = tr1;
	}
}
void Lider::DelTrailer(Lider *q) {
	while (q->tr) {
		Trailer *t = q->tr;
		t->pointer->count--;
		t = t->next;
		delete t;
	}
}
Graph::Graph() {
	head = new Lider;
}
Graph:: ~Graph() {
	Lider *t = head;
	while (t->next) {
		t->DelTrailer(t->next);
		t = t->next;
	}
	delete head;
}
void Graph::AddToHead(int k) {
	Lider *t;
	t = new Lider;
	t->key = k;
	t->next = head->next;
	head->next = t;
}
void Graph::AddToTail(Lider *q) {
	Lider *p = head;
	for (; p->next != NULL; p = p->next);
	p->next = q;
	q->next = 0;
}
void Graph::Del(Lider *q) {
	Lider *p = head;
	for (; p->next != q && p->next; p = p->next);
	if (p->next != 0)
		std::cout << "Lider q not found";
	else {
		while (q->tr) {
			Trailer *t = q->tr;
			q->tr->pointer->count--;
			q->tr = q->tr->next;
			delete t;
		}
		p->next = q->next;
		delete q;
	}
}
void Graph::Exclude(Lider *q) {
	Lider *p = head;
	if (!Empty()) {
		for (p; p->next != q && p->next != NULL; p = p->next);
		if (p->next != q)
			std::cout << "lider q not found";
		else {
			p->next = q->next;
		}
	}
}
Lider* Graph::FindKey(int k) {
	Lider* p = head->next;
	if (!Empty()) {
		while (p){
			if (p->key == k)
				return p;
			p = p->next;
		}
	}
	return 0;
}
Lider* Graph::FindCount(int x) {
	Lider* p = head->next;
	if (!Empty()) {
		while (p){
			if (p->count == x)
				return p;
			p = p->next;
		}
	}
	return 0;
}
void Graph::Clear() {
	while (!Empty())
		Del(head->next);
}
bool Graph::Empty() {
	if (head->next == NULL)
		return true;
	return false;
}
void Lider::ReduceCount() {
	Trailer *t = tr;
	while (t)
	{
		t->pointer->count--;
		t = t->next;
	}
}
void Lider::IncreaseCount() {
	Trailer *t = tr;
	while (t)
	{
		t->pointer->count++;
		t = t->next;
	}	
}
int Graph::FormGraph()
{
	int n = 0, x, y;
	Lider *px, *py;
	std::cout << "Enter x and y: ";
	std::cin >> x >> y;
	while (x && y)
	{
		if (FindKey(x) == 0)
		{
			AddToHead(x);
			px = head->next;
			n++;
		}
		else px = FindKey(x);

		if (FindKey(y) == 0)
		{
			AddToHead(y);
			py = head->next;
			n++;
		}
		else py = FindKey(y);

		py->count++;
		px->AddTrailer(py);

		std::cout << "enter x and y: ";
		std::cin >> x >> y;
	}
	return n;
}
void Graph::SortGraph(Graph& newLD)
{
	Lider *p, *q;
	while (!Empty())
	{
		p = FindCount(0);
		if (p == 0 && !Empty())
		{
			std::cout << "cycle"; return;
		}
		Exclude(p);
		newLD.AddToTail(p);
		p->ReduceCount();
	}
	q = newLD.head->next;
	while (q != 0)
	{
		q->IncreaseCount(); q = q->next;
	}
}
void Graph::Print(int n) {
	Lider *q = head->next;
	if (n != 0){
		for (; q && (n > 0); q = q->next, n--)
			std::cout << q->key << " ";
	}
	else
		std::cout << "Graph is empty";
	std::cout << std::endl;
}
//void Output(Leader *graph)
//{
//	for (Leader *it = graph->next; it; it = it->next)
//	{
//		cout << it->key << " ";
//	}
//
//	cout << endl;
//}