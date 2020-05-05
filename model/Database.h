#pragma once
#include "Book.h"
#include "Paperback.h"
#include "Hardback.h"
#include "Magazine.h"
#include "Advertiser.h"
#include "Advertisement.h"

#include <string>

using namespace std;

class Database
{
private:
	vector<Paperback> paperbacks;
	vector<Hardback> hardbacks;
	vector<Magazine> magazines;
	vector<Advertiser> advertisers;
	vector<Advertisement> advertisements;
	string act1;
	string act2;

public:
	Database() : act1(read("./files/Act1.txt")), act2(read("./files/Act2.txt")) {fillAll();};
	string read(string file);
	void fillAll();
	void fillContent();
	void fillPaperbacks();
	void fillHardbacks();
	void fillMagazines();
	void fillAdvertisers();
	void fillAdvertisements();
	void listPaperbacks();
	void listHardbacks();
	void listMagazines();
	void listAdvertisers();

	vector<Book> getBooks();
	vector<Paperback> getPaperbacks();
	vector<Hardback> getHardbacks();
	vector<Magazine> getMagazines();
	vector<Advertiser> getAdvertisers();
	vector<Magazine> getMagazineById(int id) const;
	Advertiser getAdvertiserById(int id);
};

