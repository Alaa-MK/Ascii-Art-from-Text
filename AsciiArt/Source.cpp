#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

const int MAX_CHAR_HEIGHT = 30;
const int MAX_CHAR_WIDTH = 30;
int charHeight;
int charWidth;
int CharsPerLine = 20;
bool readFile(const string fileName, string arr[36][MAX_CHAR_HEIGHT]) {
	ifstream ifile;
	string line;
	ifile.open(fileName);
	if (!ifile.is_open()) {
		cout << "Couldn't open the file!" << endl;
		return false;
	}
	getline(ifile, line);
	charHeight = atoi(line.c_str());
	getline(ifile, line);
	charWidth = atoi(line.c_str());
	for (int i = 0; i < 36; i++)
		for (int j = 0; j < charHeight; j++)
			getline(ifile, arr[i][j]);
	ifile.close();
	return true;
}

string space() {
	string s = "";
	for (int i = 0; i < charWidth; i++) s += ' ';
	return s;
}


string strToAscii(const string str, const string arr[36][MAX_CHAR_HEIGHT]) {
	queue <string> Q[MAX_CHAR_HEIGHT];
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < charHeight; j++) {
			if (str[i] == ' ') Q[j].push(space());
			else if (isdigit(str[i])) Q[j].push(arr[(int)str[i] - (int)'0' + 26][j]);
			else Q[j].push(arr[(int)tolower(str[i]) - (int)'a'][j]);
		}
	}
	string ascii = "";
	int iterations = ceil((double)Q[0].size() / CharsPerLine);
	for (int t = 0; t < iterations; t++) {
		for (int i = 0; i < charHeight; i++) {
			for (int j = 0; j < CharsPerLine; j++) {
				if (Q[i].empty()) break;
				string s;
				s = Q[i].front();
				ascii += s;
				Q[i].pop();
			}
			ascii += '\n';
		}
	}
	return ascii;
}

int main() {
	string letters[36][MAX_CHAR_HEIGHT];
	string fileName = "Letters.txt";
	readFile(fileName, letters);
	//header
	cout << strToAscii("ascii art", letters) << "\n===============================================================\n";

	string str, asciiStr;
	char input = 'n';
	bool firstTime = true;
	while (true)
	{
		if (tolower(input) == 'p')
			cout << asciiStr << endl;
		else if (tolower(input) == 's') {
			string ofileName;
			ofstream ofile;
			cout << "\nPlease enter a file name..\n";
			cin.ignore();
			getline(cin, ofileName);
			ofile.open(ofileName);
			ofile << asciiStr;
			ofile.close();
			cout << "\nFile saved!\n";
		}
		else if (tolower(input) == 'q')
			break;
		else if (tolower(input) == 'n') {
			cout << "\nPlease enter some text to create ASCII art..\n";
			if (!firstTime) 
				cin.ignore();
			getline(cin, str);
			asciiStr = strToAscii(str, letters);
			cout << "Art created! \n";
		}
		else
			cout << "\nInvalid input!\n";

		firstTime = false;
		cout << "(P)rint to the console \n(S)ave to a file \n(Q)uit \n(N)ew Ascii art\n";
		cin >> input;
	}
	return 0;
}