#include "models.hpp"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
	if (argc == 1) {
		cout << "Invalid arguments" << endl;
		return 2;
	}
	std::string fileList = argv[1];
	Model m;
	std::string fileName;
	std::ifstream in(fileList);
	while (in >> fileName) {
		m.createModel(fileName);
	}

	switch(*(argv[2])) {
		case 'a':
			m.printForwardOrder();
			break;
		case 'r':
			m.printReverseOrder();
			break;
		case 'c':
			m.printByFrequency();
			break;
		default:
			cout << "Invalid input" << endl;
			break;
	}

	return 0;
}