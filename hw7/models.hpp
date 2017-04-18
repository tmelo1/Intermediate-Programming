#ifndef HW7A_H
#define HW7A_H
#include <map>

using std::string;
using std::map;



class Model {

public:
	void createModel(string fileName);
	void printForwardOrder();
	void printReverseOrder();
	void printByFrequency();
	void makeModelFile();


private:
	map<string, int> model;
};



#endif