//============================================================================
// Name        : aldebaran2dot.cpp
// Author      : Huu Nghia NGUYEN
// Version     :
// Copyright   : You can use this freely!
// Description : Convert Aldebaran format into Graphviz DOT format
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char * argv[]) {
	if (argc != 2){
		cout <<endl <<"This program converts a graph in aldebaran format into graphviz format." <<endl;
		cout <<"Usage: " <<argv[0] <<" aldebaranfile" << endl <<endl;
		return 0;
	}
	ifstream infile(argv[1]);
	if (!infile){
		cout <<endl <<"Cannot read file " <<argv[1] <<endl <<endl;
		return 0;
	}
	//create dot file
	string fname;
	fname.append((argv[1]));
	fname = fname.substr(0, fname.find_last_of("."));
	fname = fname.append(".dot");
	ofstream outfile(fname);

	outfile << "digraph name {";
	string line;
	int i=0;
	while (getline(infile, line)){
		i++;
		if (i==1)
			continue;		//pass the first line

		//a line is a string in format: (source,"label",destination)
		line = line.substr(1, line.size()-2);	//remove ( and )

		istringstream iss(line);
		string src, dst, label;
		getline(iss, src, ',');
		getline(iss, label, ',');
		getline(iss, dst, ',');
		outfile <<src <<" -> " <<dst <<" [label=" <<label <<"];" <<endl;
	}
	outfile <<"}";
	return 1;
}
