#pragma once
#include <string>

using namespace std;

class Book
{
public:
	Book();
	Book(string title, int nbPages, string content)
		: id(c), title(title), nbPages(nbPages), content(content) {c++;};
	int getId() const;
	string getTitle() const;
	int getNbPages() const;
	string getContent() const;
	void setId(int id);
	void setTitle(string title);
	void setNbPages(int nbPages);
	void setContent(string content);

private:
	static int c;
	int id;
	string title;
	int nbPages;
	string content;
};

