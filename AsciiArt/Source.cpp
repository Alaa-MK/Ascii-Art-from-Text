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
const int MAX_LETTERS = 7;
bool readFile(string fileName, string arr[36][MAX_CHAR_HEIGHT]) {
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


string strToAscii(string str, string arr[36][MAX_CHAR_HEIGHT]) {
	queue <string> Q[MAX_CHAR_HEIGHT];
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < charHeight; j++) {
			if (str[i] == ' ') Q[j].push(space());
			else if (isdigit(str[i])) Q[j].push(arr[(int)str[i] - (int)'0' + 26][j]);
			else Q[j].push(arr[(int)tolower(str[i]) - (int)'a'][j]);
		}
	}
	string ascii = "";
	int iterations = ceil((double)Q[0].size() / MAX_LETTERS);
	for (int t = 0; t < iterations; t++) {
		for (int i = 0; i < charHeight; i++) {
			for (int j = 0; j < MAX_LETTERS; j++) {
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
	string str;
	getline(cin, str);
	cout << strToAscii(str, letters);
	return 0;
}