#include "Controller.h"

#include <iostream>
#include <sstream>
#include <set>

void Controller::menu() {
	bool cond(true);
	while (cond) {
		string input;
		int choice;
		view.printMenu();
		getline(cin >> ws, input);
		istringstream(input) >> choice;
		cout << endl;
		switch (choice)
		{
		default:
			cout << "Please fill a correct instruction." << endl;
			break;
		case 1:
			showMagazines();
			break;
		case 2:
			showPaperbacks();
			break;
		case 3:
			showHardbacks();
			break;
		case 4:
			showAdvertisers();
			break;
		case 5:
			showMagazineInfo();
			break;
		case 6:
			showBooks();
			break;
		case 7:
			cout << "Add a Book" << endl;
			break;
		case 8:
			cout << "Search for a word" << endl;
			break;
		case 9:
			showTotalHardbacksWeight();
			break;
		case 10:
			cond = false;
			break;
		}
	}
}

void Controller::showBooks() {
	view.printBooks(db.getBooks());
}

void Controller::showMagazines() {
	view.printMagazines(db.getMagazines());
}

void Controller::showPaperbacks() {
	view.printPaperbacks(db.getPaperbacks());
}

void Controller::showHardbacks() {
	view.printHardbacks(db.getHardbacks());
}

void Controller::showAdvertisers() {
	view.printAdvertisers(db.getAdvertisers());
}

void Controller::showMagazineInfo() {
	string input;
	int id;
	do {
		cout << "Magazine ID (0 to quit): ";
		getline(cin >> ws, input);
		istringstream(input) >> id;
		cout << endl;
		if (id != 0) {
			if (db.getMagazineById(id).size() == 1) {
				Magazine magazine(db.getMagazineById(id)[0]);
				set<int> advertisersID;
				vector<Advertiser> advertisers;
				for (Advertisement &a : db.getMagazineById(id)[0].getAdvertisements()) {
					advertisersID.insert(a.getAdvertiserId());
				}
				for (int aID : advertisersID) {
					if (db.getAdvertiserById(aID).getId() != 0) {
						advertisers.push_back(db.getAdvertiserById(aID));
					}
				}
				view.printMagazineInfo(magazine.getAdvertisements().size(), advertisers);
			} else {
				cout << "There is no magazine associated with id " + to_string(id) + ". Make sure to enter a correct id." << endl;
			}
		}
		cout << endl;

	} while (id != 0);
}

void Controller::showTotalHardbacksWeight() {
	double totalWeight(0);
	for (Hardback h : db.getHardbacks()) {
		totalWeight += h.getWeight();
	}
	view.printTotalHardbacksWeight(totalWeight);
}