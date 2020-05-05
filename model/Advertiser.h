#pragma once
#include <string>

using namespace std;

class Advertiser
{
public:
	Advertiser(int id, string name) : id(id), name(name) {};
	Advertiser() : id(0), name("") {};
	int getId() const;
	string getName() const;
	void setId(int id);
	void setName(string name);
private:
	int id;
	string name;
};

