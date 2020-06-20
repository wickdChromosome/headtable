/* This is a simple replacement for head*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#include <boost/algorithm/string.hpp>


using namespace std;


vector<string> read_file(string& filename) {

	ifstream infile(filename);

	vector<string>lines;
	string line;
	//Fill main vector with lines 
	while(getline(infile, line)) {

		lines.push_back(line);	

	}

	return lines;

}



int main(int argc, char* argv[]) {
	
	
	string filename = argv[1];
	int linelimit = stoi(argv[2]);
	const char separator    = ' ';
	const int nameWidth     = 28;
	const int numWidth      = 8;
	int linec = 0; //for storing how many lines we are done with

	//Read in the whole file
	auto filevect = read_file(filename);

	//Iterate over the whole file row by row
	for (auto& row : filevect) {

		//lets quit if we are done printing
		if (linec > linelimit) return 0;

		//split the string using boost
		vector<string> splitrow;
		string delim = ",";
		boost::split(splitrow, row, boost::is_any_of(delim));

		//now iterate over each row and print each time for that row	
		for(auto& col : splitrow) {

			cout << left << setw(nameWidth) << setfill(separator) << col;

		}

		linec += 1;
		cout << endl;

	}
		



}
