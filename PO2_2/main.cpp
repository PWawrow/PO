#include "List.h"
#include <iostream>
#include <vector>

int main() {
	
	std::vector<Point> points;

	for (size_t i = 0; i < 10; i++) 
	{
		points.push_back(Point((double)i, (double)i+1, (double)i+2));
	}
	List lista = List(points);
	std::cout << lista;

}