#include "Magazine.h"
#include "Book.h"

vector<Advertisement> Magazine::getAdvertisements() const {
	return advertisements;
}

void Magazine::setAdvertisements(vector<Advertisement> advertisements) {
	this->advertisements = advertisements;
}