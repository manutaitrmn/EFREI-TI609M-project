#pragma once
#include "Book.h"

class Hardback : public Book
{
public:
	Hardback(string title, int nbPages, string content, double weight) : Book(title, nbPages, content), weight(weight) {};
	double getWeight() const;
	void setWeight(double weight);
private:
	double weight;
};

