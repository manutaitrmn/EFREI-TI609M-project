#include "View.h"

#include <iostream>
#include <vector>
#include <set>

using namespace std;



void View::print(string text) {
	cout << text;
}

void View::println(string text) {
	cout << text << endl;
}

void View::newLine() {
	cout << endl;
}

void View::printMenu() {
	cout << endl << "Choose an action:" << endl
		<< "1. List all magazines" << endl
		<< "2. List all paperback books" << endl
		<< "3. List all hardback books" << endl
		<< "4. List all advertisers" << endl
		<< "5. List advertisements number and advertisers for a magazine" << endl
		<< "6. Remove a Book / Magazine by ID" << endl
		<< "7. Add a magazine" << endl
		<< "8. Search for a word" << endl
		<< "9. Total weight of hardback books" << endl
		<< "10. Quit the program\n" << endl;
	cout << "n°: ";
}

void View::printWordSearch(int id, string word, int c) {
	cout << "In the book id: " << id << " the word \"" << word << "\" appears " << c << " time(s)." << endl;
}

void View::printBooks(vector<Book> books) {
	cout << "All books:" << endl;
	for(Book &b : books) {
		cout << to_string(b.getId()) + " | " + b.getTitle() + " | " + to_string(b.getNbPages()) << endl;
	}
}

void View::printMagazines(vector<Magazine> magazines) {
	cout << "All magazines:" << endl;
	for(Magazine &m : magazines) {
		cout << to_string(m.getId()) + " | " + m.getTitle() + " | " + to_string(m.getNbPages()) << endl;
	}
}

void View::printPaperbacks(vector<Paperback> paperbacks) {
	cout << "All paperback books:" << endl;
	for(Paperback &p : paperbacks) {
		cout << to_string(p.getId()) + " | " + p.getTitle() + " | " + to_string(p.getNbPages()) << endl;
	}
}

void View::printHardbacks(vector<Hardback> hardbacks) {
	cout << "All hardback books:" << endl;
	for(Hardback &h : hardbacks) {
		cout << to_string(h.getId()) + " | " + h.getTitle() + " | " + to_string(h.getNbPages()) + " | " + to_string(h.getWeight()) + "kg" << endl;
	}
}

void View::printAdvertisers(vector<Advertiser> advertisers) {
	cout << "All advertisers:" << endl;
	for(Advertiser &a : advertisers) {
		cout << to_string(a.getId()) + " | " + a.getName()<< endl;
	}
}

void View::printMagazineInfo(int advNumber, vector<Advertiser> advertisers) {
	cout << "Number of advertisements: " + to_string(advNumber) << endl;
	cout << "Advertisers: " << endl;
	for(Advertiser a : advertisers) {
		cout << to_string(a.getId()) + " | " + a.getName()<< endl;
	}
}

void View::printTotalHardbacksWeight(double totalWeight) {
	cout << "Total weight of hardback books: " + to_string(totalWeight) + "kg" << endl;
}