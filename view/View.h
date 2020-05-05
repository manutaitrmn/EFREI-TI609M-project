#pragma once

#include "../model/Book.h"
#include "../model/Magazine.h"
#include "../model/Paperback.h"
#include "../model/Hardback.h"
#include "../model/Advertiser.h"

#include <set>

using namespace std;

class View 
{
public:
	void printMenu();
	void printBooks(vector<Book> books);
	void printMagazines(vector<Magazine> magazines);
	void printPaperbacks(vector<Paperback> paperbacks);
	void printHardbacks(vector<Hardback> hardbacks);
	void printAdvertisers(vector<Advertiser> advertisers);
	void printMagazineInfo(int advNumber, vector<Advertiser> advertisers);
	void printTotalHardbacksWeight(double totalWeight);
};