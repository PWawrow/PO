#include "List.h"




List::Node * List::find(const size_t idx)
{
	Node * node = first;

	for (size_t i = 0; i < idx; i++)
	{
		node = node->next;
	}

	return node;
}

void List::push(const Point & point, const size_t idx)
{
	if (idx == 0)
	{
		Node * tail = first;
		first = new Node(point);
		first->next = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next;
		prev->next = new Node(point);
		prev->next->next = tail;
	}
	size++;
}

void List::push(const List & list, const size_t idx)
{
	List copy(list);
	Node * it = copy.first;
	if (idx == 0)
	{
		Node * tail = first;
		Node * last = nullptr;
		if (it)
		{
			first = new Node(it->point);
			last = first;
			it = it->next;
		}
		while (it)
		{
			last->next = new Node(it->point);
			last = last->next;
			it = it->next;
		}
		if(last) last->next = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next;
		while (it)
		{
			prev->next = new Node(it->point);
			prev = prev->next;
			it = it->next;
		}
		prev->next = tail;
	}
	size += copy.size;
}

void List::pop(const size_t idx)
{
	if (idx == 0)
	{
		Node * tail = first->next;
		delete first;
		first = tail;
	}
	else
	{
		Node * prev = find(idx - 1);
		Node * tail = prev->next->next;
		delete prev->next;
		prev->next = tail;
	}
	size--;
}

void List::multiply(size_t nb)
{
	if (nb == 0) this->~List();
	for (size_t i = 0; i < nb; i++) {
		List copy(*this);
		this->push(copy, this->size);
	}
}

List::List() : size(0), first(nullptr){}


List::List(const List & list) : size(list.size), first(nullptr)
{
	Node * it = list.first;
	Node * last = first;
	if (it)
	{
		first = new Node(it->point);
		last = first;
		it = it->next;
	}
	while (it)
	{
		last->next = new Node(it->point);
		last = last->next;
		it = it->next;
	}
}

List::List(const std::vector<Point>& vect) : size(vect.size()), first(nullptr)
{
	if (vect.size() > 0)//check if vect not empty
	{
		Node* last;
		first = new Node(vect[0]);
		last = first;
		for (size_t i = 1; i < vect.size(); i++) {
			last->next = new Node(vect[i]);
			last = last->next;
		}
	}

}



List::~List()
{
	for (int i = 0; i < size; i++)
		pop(i);

}

List::Error List::insert(const Point& point, const std::size_t idx)
{
	List::Error error = List::Error::SUCCESS;

	if (idx < size && idx > -1)
	{
		push(point, idx);
	}
	else
	{
		error = List::Error::OUT_OF_BOUNDS;
	}
	return error;
}

List::Error List::find(Point& point, const std::size_t idx)
{
	List::Error error = List::Error::SUCCESS;
	if (size != 0) 
	{
		if(idx < size)
		{
			point = find(idx)->point;
		}
		else 
		{
			error = List::Error::OUT_OF_BOUNDS;
		}
	}else
	{
		error = List::Error::LIST_EMPTY;
	}
	return error;
}

List::Error List::push_back(const Point& point)
{
	List::Error error = List::Error::SUCCESS;
	
	push(point, size);
	

	return List::Error::SUCCESS;
}

List::Error List::pop_back()
{
	Error error = List::Error::SUCCESS;
	if (size != 0)
	{
		pop(size-1);
	}
	else 
	{
		error = List::Error::LIST_EMPTY;
	}
	
	return error;
}

List::Error List::pop_front()
{
	List::Error error = List::Error::SUCCESS;

	if (size == 0)
	{
		error = List::Error::LIST_EMPTY;
	}
	else
	{
		pop(0);
	}

	return error;
}

size_t List::getSize()
{
	return size;
}

List List::operator+(const List& list)
{
	List copy(*this);
	copy.push(list, copy.size);
	return copy;
}

List& List::operator+=(const List& list)
{
	push(list, size);
	return *this;
}

List & List::operator=(const List & list)
{
	List copy(list);
	this->~List(); 
	
	push(copy, 0);
	return *this;
}

List List::operator--(int)
{
	List copy(*this);
	pop_back();
	return copy;
}

List List::operator*(size_t nb)
{
	List copy(*this);
	copy.multiply(nb);
	return copy;
}

Point& List::operator[](size_t idx)
{
	return find(idx)->point;
}

List& List::operator++(int)
{
	List copy(*this);
	this->~List();
	return copy;
}

std::ostream& operator<<(std::ostream& os, List& list)
{
	for (size_t i = 0; i < list.size; i++) 
	{
		Point p;
		list.find(p, i);
		os << "Id: " << i << " x: " << p.x << " y: " << p.y << " z: " << p.z << "\n";
	}
	return os;
}
