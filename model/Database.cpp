#include "Database.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstring>

using namespace std;

Database operator- (Database db, int id) {
	int cc(0);
	if (db.isInPaperbacks(id)) {
		cc = 1;
	} else if (db.isInHardbacks(id)) {
		cc = 2;
	} else if (db.isInMagazines(id)) {
		cc = 3;
	}
	vector<Paperback> ps;
	vector<Hardback> hs;
	vector<Magazine> ms;
	switch(cc) {
		default:
			cout << "No book associated with this id. Please make sure to enter a correct id." << endl << endl;
			break;
		case 1:
			for (Paperback p : db.getPaperbacks()) {
				if (p.getId() != id) {
					ps.push_back(p);
				}
			}
			db.setPaperbacks(ps);
			cout << "Paperback book deleted." << endl << endl;
			break;
		case 2:
			for (Hardback h : db.getHardbacks()) {
				if (h.getId() != id) {
					hs.push_back(h);
				}
			}
			db.setHardbacks(hs);
			cout << "Hardback book deleted." << endl << endl;
			break;
		case 3:
			for (Magazine m : db.getMagazines()) {
				if (m.getId() != id) {
					ms.push_back(m);
				}
			}
			db.setMagazines(ms);
			cout << "Magazine deleted." << endl << endl;
			break;
	}
	return db;
}

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
  	paperbacks.push_back(Paperback("The C++ Programming Language", 1376, content1));
	paperbacks.push_back(Paperback("C++ Primer", 972, content1));
	paperbacks.push_back(Paperback("Effective C++", 334, content2));
	paperbacks.push_back(Paperback("TProgramming: Principles and Practice Using C++", 1282, content2));
	paperbacks.push_back(Paperback("A Tour of C++", 246, content1));
}

void Database::fillHardbacks() {
	hardbacks.push_back(Hardback("Head First Design Patterns",676,content1,0.7));
	hardbacks.push_back(Hardback("Code: The Hidden Language of Computer Hardware and Software",400,content2,0.3));
	hardbacks.push_back(Hardback("Peopleware: Productive Projects and Teams",272,content2,0.1));	
	hardbacks.push_back(Hardback("Pro Git",458,content1,0.4));
	hardbacks.push_back(Hardback("The Manager's Path: A Guide for Tech Leaders Navigating Growth and Change",246,content2,0.2));
}

void Database::fillMagazines() {
	vector<Advertisement> adv;
	adv.push_back(advertisements[0]);
	adv.push_back(advertisements[1]);
	magazines.push_back(Magazine("The Guardian",30,content2,adv));
	adv.clear();
	adv.push_back(advertisements[2]);
	adv.push_back(advertisements[2]);
	adv.push_back(advertisements[4]);
	magazines.push_back(Magazine("Fast Company",47,content1,adv));
	adv.clear();
	adv.push_back(advertisements[3]);
	magazines.push_back(Magazine("Forbes",36,content1,adv));
	adv.clear();
	adv.push_back(advertisements[4]);
	magazines.push_back(Magazine("Platinum Business",33,content1,adv));
	adv.clear();
	adv.push_back(advertisements[2]);
	magazines.push_back(Magazine("Wired",25,content1,adv));
	adv.clear();
}

bool Database::isInPaperbacks(int id) {
	bool cond(false);
	for (Paperback p : getPaperbacks()) {
		if (p.getId() == id) {
			cond = true; break; 
		}
	}
	return cond;
}

bool Database::isInHardbacks(int id) {
	bool cond(false);
	for (Hardback h : getHardbacks()) {
		if (h.getId() == id) {
			cond = true; break; 
		}
	}
	return cond;
}

bool Database::isInMagazines(int id) {
	bool cond(false);
	for (Magazine m : getMagazines()) {
		if (m.getId() == id) {
			cond = true; break; 
		}
	}
	return cond;
}

string Database::getContent1() {
	return content1;
}

string Database::getContent2() {
	return content2;
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

void Database::setPaperbacks(vector<Paperback> paperbacks) {
	this->paperbacks = paperbacks;
}

vector<Paperback> Database::getPaperbacks() {
	return paperbacks;
}

void Database::setHardbacks(vector<Hardback> hardbacks) {
	this->hardbacks = hardbacks;
}

vector<Hardback> Database::getHardbacks() {
	return hardbacks;
}

void Database::addMagazine(Magazine magazine) {
	magazines.push_back(magazine);
}

void Database::setMagazines(vector<Magazine> magazines) {
	this->magazines = magazines;
}

vector<Magazine> Database::getMagazines() {
	return magazines;
}

vector<Advertiser> Database::getAdvertisers() {
	return advertisers;
}

vector<Advertisement> Database::getAdvertisements() {
	return advertisements;
}

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