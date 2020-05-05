#pragma once
#include "Book.h"
#include "Advertisement.h"
#include <vector>
#include <string>

using namespace std;

class Magazine : public Book
{
public:
	Magazine();
	Magazine(string title, int nbPages, string content, vector<Advertisement> advertisements) : Book(title, nbPages, content), advertisements(advertisements) {};
	vector<Advertisement> getAdvertisements() const;
	void setAdvertisements(vector<Advertisement> advertisements);
private:
	vector<Advertisement> advertisements;
};

