#pragma once
#include <string>
#include "Book.h"

using namespace std;

class Paperback : public Book
{
public:
	Paperback(string title, int nbPages, string content)
		: Book(title, nbPages, content) {};
};

