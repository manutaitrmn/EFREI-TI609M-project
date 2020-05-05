#include "Advertisement.h"

string Advertisement::getTitle() const {
	return title;
}

int Advertisement::getAdvertiserId() const {
	return advertiserId;
}

void Advertisement::setTitle(string title) {
	this->title = title;
}

void Advertisement::setAdvertiserId(int advertiserId) {
	this->advertiserId = advertiserId;
}