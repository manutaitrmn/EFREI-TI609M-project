#include "Controller.h"
#include "../model/Paperback.h"

#include <iostream>
#include <typeinfo>
#include <sstream>
#include <set>
#include <mutex>
#include <thread>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

void Controller::menu() {
	bool cond(true);
	while (cond) {
		string input;
		int choice;
		view.printMenu();
		getline(cin >> ws, input);
		istringstream(input) >> choice;
		view.newLine();
		switch (choice)
		{
		default:
			view.println("Please fill a correct instruction.");
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
			removeBook();
			break;
		case 7:
			addMagazine();
			break;
		case 8:
			searchWord();
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
		view.print("Magazine ID (0 to quit): ");
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
				cout << endl;
			} else {
				view.println("There is no magazine associated with id " + to_string(id) + ". Make sure to enter a correct id.");
				view.newLine();
			}
		}
	} while (id != 0);
}

void Controller::showTotalHardbacksWeight() {
	double totalWeight(0);
	for (Hardback h : db.getHardbacks()) {
		totalWeight += h.getWeight();
	}
	view.printTotalHardbacksWeight(totalWeight);
}

void Controller::removeBook() {
	int id(1);
	string input;
	while (id != 0 && db.getBooks().size() != 0) {
		showBooks();
		Book b = db.getBooks()[0];
		view.newLine();
		view.print("Book id to delete (0 to quit): ");
		getline(cin >> ws, input);
		istringstream(input) >> id;
		if (id != 0) {
			view.newLine();
			db = db - id;
		}
	}
	if (db.getBooks().size() == 0) {
		view.println("No books found.");
	}
}

void Controller::addMagazine() {
	view.println("Add a magazine:");
	view.newLine();

	// Define variables
	string input;
	string title;
	int nbPages;

	// Input title
	view.print("Enter a Magazine title: ");
	getline(cin, title);

	// Input number of Pages
	bool cond(false);
	while (!cond) {
		view.newLine();
		view.println("Enter the number of pages: ");
		getline(cin >> ws, input);
		if (isNumber(input)) {
			cond = true;
			nbPages = stoi(input);
		} else {
			view.newLine();
			view.println("Number of page invalid.");
		}
	}

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	vector<string> contents;
	contents.push_back(db.getContent1());
	contents.push_back(db.getContent2());
	shuffle(contents.begin(), contents.end(), default_random_engine(seed));

	vector<Advertisement> dbAdvertisements = db.getAdvertisements();
	vector<Advertisement> advertisements;
	for (int i(0); i < 3; i++) {
		shuffle(dbAdvertisements.begin(), dbAdvertisements.end(), default_random_engine(seed));
		advertisements.push_back(dbAdvertisements[0]);
	}

	db.addMagazine(Magazine(title, nbPages, contents[0], advertisements));

	view.newLine();
	view.println("Magazine added.");
}

void Controller::searchWord() {
	// Define variables
	vector<thread> threads;
	string word;
	mutex m;

	view.print("Search for a word in books: ");
	cin >> word;

	// function search for a word
	auto search = [&m, this](int id, string content, string word) { 
		lock_guard<mutex> lock(m);
		string temp;
		int c(0);
		stringstream scontent(content);
		while (scontent >> temp) {
			if (toAlnum(temp) == toAlnum(word))
				c++;
		}
		view.printWordSearch(id, word, c);
		
	};

	for (Book b :db.getBooks()) {
		threads.push_back(thread(search, b.getId(), b.getContent(), word));
	}

	// Execute threads
	for (thread &t : threads) {
		t.join();
	}
}

string Controller::toAlnum(string text) {
	string result("");
	for (int i(0); i < text.size(); i++)
	{
		if (isalnum(text[i])) result+=text[i];
	}
	return result;
}

bool Controller::isNumber(string str) {
	bool cond(true);
	for(int i(0);i < str.length();i++) {
		if (!isdigit(str[i])) {
			cond = false;
			break;
		}
	}
	return cond;
}