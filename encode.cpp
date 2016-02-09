/*

Steps for encoding a string:

1. Get a list of symbols in the message, sorted by their frequency in the message.
2. Combine the two smallest frequencies
3. Resort the list.

Repeat steps till we get one frequency (should be equal to character length of the string).

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef vector<pair<char, int> > table;

void printfTable(table t) {
	for (table::iterator it = t.begin(); it != t.end(); ++it) {
		cout<< it->first << " => " << it->second << endl;
	}
}

void insert(table &fTable, char c) {
	bool inserted = false;
	for(table::iterator it = fTable.begin(); it != fTable.end(); ++it) {
		if (it->first == c) {
			++(it->second);
			inserted = true;
			break;
		}
	}
	if (!inserted) {
		pair<char, int> ins(c, 1);
		fTable.push_back(ins);
		fTable.push_back(make_pair('t', 7));
	}
}

bool comp (const pair<char, int> f, const pair<char, int> s) { return (f.second < s.second); }

void sortByFreq(table &v) { sort(v.begin(), v.end(), comp); }

table getFrequencies(string message) {
	table fTable;
	for (int i = 0; i < message.length(); ++i) {
		char currentChar = message[i];
		insert(fTable, currentChar);
	}
	sortByFreq(fTable);
	return fTable;
}

int main() {
	string testMessage = "This is a test message with lots of words, and phrases and special characters!!#~*";
	table testTable = getFrequencies(testMessage);
	cout << "Message: " << testMessage << endl;
	cout << "Frequency Table: " << endl;
	printfTable(testTable);
}
