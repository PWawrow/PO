#pragma once
#include <vector>
#include <iostream>
#include "Point.h"

class List
{
	size_t size;
	struct Node
	{
		Point point;
		Node * next;
		Node(const Point & p) : point(p.x, p.y, p.z), next(nullptr){}
	};
	Node * first;

	Node * find(const size_t);
	void push(const Point &, const size_t);
	void push(const List &, const size_t);
	void pop(const size_t);
	void multiply(size_t nb);

public:
	List();
	List(const List&);
	List(const std::vector<Point>&);
	~List();

	enum Error
	{
		SUCCESS,
		LIST_EMPTY,
		OUT_OF_BOUNDS
	};
	Error insert(const Point&, const std::size_t);
	Error find(Point&, const std::size_t);
	Error push_back(const Point&);
	Error pop_back();
	Error pop_front();
	size_t getSize();
	List operator+(const List&);
	List& operator+=(const List&);
	List& operator=(const List&);
	List operator--(int);
	List operator*(size_t);
	Point& operator[](size_t);
	List& operator++(int);

	friend std::ostream& operator<<(std::ostream&, List&);


	//Proszê pamiêtaæ, ¿e to nie jest pe³na implementacja, nale¿y kod uzupe³niæ zgodnie z instrukcj¹
};

