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
	string content1;
	string content2;

public:
	Database() : content1(read("./files/Act1.txt")), content2(read("./files/Act2.txt")) {fillAll();};

	friend Database operator- (Database db, int id);

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

	bool isInPaperbacks(int id);
	bool isInHardbacks(int id);
	bool isInMagazines(int id);

	void addMagazine(Magazine magazine);

	void setPaperbacks(vector<Paperback> paperbacks);
	void setHardbacks(vector<Hardback> hardbacks);
	void setMagazines(vector<Magazine> magazines);

	string getContent1();
	string getContent2();

	vector<Book> getBooks();
	vector<Paperback> getPaperbacks();
	vector<Hardback> getHardbacks();
	vector<Magazine> getMagazines();
	vector<Advertiser> getAdvertisers();
	vector<Advertisement> getAdvertisements();
	vector<Magazine> getMagazineById(int id) const;
	Advertiser getAdvertiserById(int id);
};

