/* This is a simple replacement for head*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

#include <boost/algorithm/string.hpp>


using namespace std;

void checkinputs(int& argc) {

	//Lets warn the user if the input makes no sense
	if (argc < 2 || argc > 3) {

		cout << "USAGE: headtable filename linelimit\n";
		exit(EXIT_FAILURE);

	} 
}

vector<vector<string>> read_file(string& filename, int& linelimit) {

	/* Returns a vector of string vectors, each 
	internal vector containing a single column*/

	ifstream infile(filename);
	vector<vector<string>> fullfile;

	string line;
	int linec = 0;
	int numcols = 0;

	//Fill main vector with lines 
	while(getline(infile, line)) {

		//split the string using boost
		vector<string> splitrow;
		string delim = ",";
		boost::split(splitrow, line, boost::is_any_of(delim));

		//if this is the first row, allocate the
		//a vector for each column
		if (linec == 0) {
	
			numcols = splitrow.size();
			//cout << "Found number of columns to be " << numcols << endl;
			//Allocate a vector in the main vector for each column
			for (int i = 0; i < numcols; i++) {

				vector<string> col;
				fullfile.push_back(col);

			}	

		}

		//now store the correct value in each vector
		for (int i = 0; i < numcols; i++) {
		
			fullfile.at(i).push_back(splitrow.at(i));

		}

		linec += 1;
		if (linec == linelimit) break ;


	}
	
	return fullfile;


}

int getcolwidth (vector<string> incol) {

	/*Finds the width that should be used in order to have enough padding
	for all columns to display correctly*/

	//get the maximum string length in this column
	int maxdatasize = 0;
	for (auto& data : incol) {

		int datasize = data.length();
		if (datasize > maxdatasize) maxdatasize = datasize;
		
	}

	return maxdatasize + 3;
	
}

int main(int argc, char* argv[]) {

	//print usage info if the input is a total mess
	checkinputs(argc);	

	string filename = argv[1];

	int linelimit;
	if (argc == 3) {
		linelimit = stoi(argv[2]);
	} else {
		//defaults to 10 lines to print
		linelimit = 10;
	}

	const char separator    = ' ';
	int linec = 0; //for storing how many lines we are done with

	//read in the whole file
	auto filevect = read_file(filename, linelimit);
	int ncols = filevect.size();
	//cout << "Read in " << ncols << " columns \n";


	//here is a vector containing the padding values
	vector<int> paddings;

	//iterate over each column
	for (int j = 0; j < ncols; j++) {

		//get the padding size for this row
		int paddingw = getcolwidth(filevect.at(j));
		paddings.push_back(paddingw);

	}
		

	//now lets print the results for each row
	for (int i = 0; i < linelimit; i++) {

		//lets quit if we are done printing
		if (linec > linelimit) break;

		//now iterate over each row and print each column with the
		//required padding
		for (int j = 0; j < ncols; j++) {

			cout << left << setw(paddings.at(j)) << setfill(separator) << filevect.at(j).at(i);

		}	

		linec += 1;
		cout << endl;
	}


}
