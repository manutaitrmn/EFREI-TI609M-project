#include "Book.h"
#include <string>
#include <iostream>

using namespace std;

int Book::c = 1;

int Book::getId() const {
	return id;
}

string Book::getTitle() const {
	return title;
}

int Book::getNbPages() const {
	return nbPages;
}

string Book::getContent() const {
	return content;
}

void Book::setId(int id) {
	this->id = id;
}

void Book::setTitle(string title) {
	this->title = title;
}

void Book::setNbPages(int nbPages) {
	this->nbPages = nbPages;
}

void Book::setContent(string content) {
	this->content = content;
}

void Book::print() {
	cout << "Book" << endl;
}