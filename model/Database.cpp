#include "Database.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void Database::fillAll() {
	fillAdvertisers();
	fillAdvertisements();
	fillPaperbacks();
	fillHardbacks();
	fillMagazines();
}

string Database::read(string file) {
	string content;
	string tmp;
	ifstream myfile(file);
	if (!myfile)
    {
        throw string("Couldn't read or find file " + file);
    }
    while (getline(myfile, tmp))
    {
        content += tmp + "\n";
    }
    return content;
}

void Database::fillAdvertisers() {
	advertisers.push_back(Advertiser(1, "Amazon"));
	advertisers.push_back(Advertiser(2, "McDonald's"));
	advertisers.push_back(Advertiser(3, "Facebook"));
	advertisers.push_back(Advertiser(4, "Tesla"));
	advertisers.push_back(Advertiser(5, "SpaceX"));
}

void Database::fillAdvertisements() {
	advertisements.push_back(Advertisement("Fusce eget mi metus.",1));
	advertisements.push_back(Advertisement("Aliquam tempor consectetur condimentum.",2));
	advertisements.push_back(Advertisement("Cras eget rutrum ligula.",3));
	advertisements.push_back(Advertisement("Etiam id pretium justo. ",4));
	advertisements.push_back(Advertisement("Etiam consectetur mollis scelerisque.",5));
}

void Database::fillPaperbacks() {
  	paperbacks.push_back(Paperback("The C++ Programming Language", 1376, act1));
	paperbacks.push_back(Paperback("C++ Primer", 972, act1));
	paperbacks.push_back(Paperback("Effective C++", 334, act2));
	paperbacks.push_back(Paperback("TProgramming: Principles and Practice Using C++", 1282, act2));
	paperbacks.push_back(Paperback("A Tour of C++", 246, act1));
}

void Database::fillHardbacks() {
	hardbacks.push_back(Hardback("Head First Design Patterns",676,act1,0.7));
	hardbacks.push_back(Hardback("Code: The Hidden Language of Computer Hardware and Software",400,act2,0.3));
	hardbacks.push_back(Hardback("Peopleware: Productive Projects and Teams",272,act2,0.1));	
	hardbacks.push_back(Hardback("Pro Git",458,act1,0.4));
	hardbacks.push_back(Hardback("The Manager's Path: A Guide for Tech Leaders Navigating Growth and Change",246,act2,0.2));
}

void Database::fillMagazines() {
	vector<Advertisement> adv;
	adv.push_back(advertisements[0]);
	adv.push_back(advertisements[1]);
	magazines.push_back(Magazine("The Guardian",30,act2,adv));
	adv.clear();
	adv.push_back(advertisements[2]);
	adv.push_back(advertisements[2]);
	adv.push_back(advertisements[4]);
	magazines.push_back(Magazine("Fast Company",47,act1,adv));
	adv.clear();
	adv.push_back(advertisements[3]);
	magazines.push_back(Magazine("Forbes",36,act1,adv));
	adv.clear();
	adv.push_back(advertisements[4]);
	magazines.push_back(Magazine("Platinum Business",33,act1,adv));
	adv.clear();
	adv.push_back(advertisements[2]);
	magazines.push_back(Magazine("Wired",25,act1,adv));
	adv.clear();
}

vector<Book> Database::getBooks() {
	vector<Book> books;
	for (Paperback p : getPaperbacks()) {
		books.push_back(p);
	}
	for (Hardback h : getHardbacks()) {
		books.push_back(h);
	}
	for (Magazine m : getMagazines()) {
		books.push_back(m);
	}
	return books;
}

vector<Paperback> Database::getPaperbacks() {
	return paperbacks;
}

vector<Hardback> Database::getHardbacks() {
	return hardbacks;
}

vector<Magazine> Database::getMagazines() {
	return magazines;
}

vector<Advertiser> Database::getAdvertisers() {
	return advertisers;
}
/*
vector<Advertiser> Database::getAdvertiserById(int id) const {
	vector<Advertiser> result;
	for (Advertiser a : advertisers) {
		if (a.getId() == id)
			result.push_back(a);
	}
	return result;
}
*/
Advertiser Database::getAdvertiserById(int id) {
	Advertiser advertiser;
	for (Advertiser a : advertisers) {
		if (a.getId() == id)
			advertiser = a;
	}
	return advertiser;
}

vector<Magazine> Database::getMagazineById(int id) const {
	vector<Magazine> result;
	for (Magazine m : magazines) {
		if (m.getId() == id)
			result.push_back(m);
	}
	return result;
}