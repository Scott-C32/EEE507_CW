#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	ifstream file("movies.csv");
	if (file.fail()) {
		cout << "Failed to open .csv file" << endl;
	}
	
	vector <vector <string>> arrayList; // main input movie array - will contain movies and other fields from csv
	string line;
	string field;
	while (getline(file, line)) { // next line in file is selected
		stringstream lineStream(line);
		vector<string>lineParsed;

		while (getline(lineStream, field, ',')) { // breaks each line into comma separated fields
			lineParsed.push_back(field); // adds each field to the parsed line vector
		}
		arrayList.push_back(lineParsed); // adds each parsed line to the main input movie array
	}

	int counterLines = arrayList.size();
	
	// Print number of movies
	// cout << "There are " << counterLines << " movies in the input dataset." << endl;
	
	// Print imported movie set
	for (int rows = 0; rows < arrayList.size(); rows++){
		for (int columns = 0; columns < arrayList[rows].size(); columns++){
			cout << arrayList[rows][columns] << ","; // fields are separated with ','
		}
		cout << endl; // new line taken after all fields on the current line have been printed 
	}

	return 0;
}