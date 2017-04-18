#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <tuple>
#include "models.hpp"
#include <string>

using std::string;
using std::map;
using std::tuple;
using std::cout;
using std::endl;



void Model::createModel(string fileName) {
	string word1 = "<START_1>";
	string word2 = "<START_2>";
	string word3 = "";
	string end1 = "<END_1>";
	string end2 = "<END_2>";
	string trigram;
	map<string, int>::iterator it;
	std::ifstream input(fileName);
	while (input >> word3) {
		trigram = word1 + " " + word2 + " " + word3;
		it = model.find(trigram);
		if (it == model.end()) {
			model[trigram] = 1;
		} else {
			model[trigram]++;
		}
		word1 = word2;
		word2 = word3;
	}

	trigram = word1 + " " + word3 + " " + end1;
	model[trigram] = 1;
	trigram = word3 + " " + end1 + " " + end2;
	model[trigram] = 1;
	input.close();
	makeModelFile();
}

void Model::printForwardOrder() {
	map<string, int>::iterator it;
	for (it = model.begin(); it != model.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}

}

void Model::printReverseOrder() {
	map<string, int>::reverse_iterator rit;
	for (rit = model.rbegin(); rit != model.rend(); ++rit) {
		cout << rit->first << " " << rit->second << endl;
	}
}

void Model::printByFrequency() {
    int max = 0;                                   
    map<string, int>::iterator it;  
    for (it = model.begin(); it != model.end(); ++it) {  
        if (it -> second > max) {
            max = it -> second;    
        }
    }

    for (int current = 1; current <= max; current++) {   
        for (it = model.begin(); it != model.end(); ++it) {
            if (it -> second == current) {  
                cout << it->first << " " << it->second << endl;
            }
        }
    }
}

void Model::makeModelFile() {
    map<string, int>::iterator it; 
    std::ofstream output("model.txt");   
    for (it = model.begin(); it != model.end(); ++it) {   
        output << it->first << " " << it->second << endl;
    }
    output.close();  
}
