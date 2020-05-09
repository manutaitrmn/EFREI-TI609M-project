#pragma once
#include "../model/Database.h"
#include "../view/View.h"

class Controller {
public:
	Controller(Database &db, View view) : db(db), view(view) {};

	void menu();

	void showBooks();
	void showMagazines();
	void showPaperbacks();
	void showHardbacks();
	void showAdvertisers();
	void showMagazineInfo();
	void showTotalHardbacksWeight();
	void removeBook();
	void addMagazine();
	void searchWord();
	bool equals(string a, string b);
	bool isNumber(string nb);
	string toAlnum(string text);

private:
	Database db;
	View view;
};