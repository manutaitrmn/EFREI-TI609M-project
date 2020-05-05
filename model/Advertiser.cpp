#include "Advertiser.h"

int Advertiser::getId() const {
	return id;
}

string Advertiser::getName() const {
	return name;
}

void Advertiser::setId(int id) {
	this->id = id;
}

void Advertiser::setName(string name) {
	this->name = name;
}