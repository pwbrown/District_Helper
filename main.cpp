// Created by Philip Brown
// Description: Helper tool to conver space seperated list of three column rows each with state number, zip code, and congressional district.
//				Converts the space seperated list into formatted JavaScript Object syntax with zipcode as key, and state and district as values

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const string fileName = "input.txt";
const string outFile = "output.txt"; 

int main() {
	// VARIABLES
	char exit;
	ifstream fin;
	ofstream fout;
	int state,
		zip,
		district,
		previousZip = 0;
	bool firstTime = true;

	// FILE SETUP
	fin.open(fileName.c_str());
	fout.open(outFile.c_str());

	// VERIFY OPEN FILE
	if (!fin) {
		cout << "Unable to locate file" << endl << endl;
		cout << "Press any key to exit: ";
		cin >> exit;
		return 0;
	}

	//INITIAL STRING SETUP
	fout << "{" << endl;


	cout << "Starting processing ..." << endl << endl;
	//BEGIN PROCESSING LOOP
	for (; fin >> state >> zip >> district;) {
		if (previousZip != 0 && previousZip == zip) {  //checks to see if the last iteration was the same zip code
			//will append district to the list of districts for specified zip
			fout << ",\"" << district << "\"";
		}
		else {
			if (previousZip != 0)
				fout << "]}," << endl;
			fout << zip << ": {\"state\": \"" << state << "\", \"districts\": [\"" << district << "\"";
		}
		previousZip = zip;
	}
	fout << endl << "}";
	cout << "Processing finished!" << endl << endl;

	// EXIT PROCESS
	cout << "Press any key to exit: ";
	cin >> exit;
	return 0;
}