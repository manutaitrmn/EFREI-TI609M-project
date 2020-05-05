#include "model/Database.h"
#include "view/View.h"
#include "controller/Controller.h"

#include <iostream>

using namespace std;

int main() {
	try {
		Database db;
		View view;
		Controller controller(db,view);
		controller.menu();
	} catch(string const& e) {
		cerr << "ERROR : " << e << endl;
	}
	return 0;
}
