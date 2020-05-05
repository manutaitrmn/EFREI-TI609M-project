#pragma once
#include <string>

using namespace std;

class Advertisement
{
public:
	Advertisement(string title, int advertiserId) : title(title), advertiserId(advertiserId) {};
	string getTitle() const;
	int getAdvertiserId() const;
	void setTitle(string title);
	void setAdvertiserId(int advertiserId);
private:
	string title;
	int advertiserId;
};

