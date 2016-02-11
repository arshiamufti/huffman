/*

Steps for encoding a string:

1. Get a list of symbols in the message, sorted by their frequency in the message.
2. Combine the two smallest frequencies
3. Resort the list.

Repeat steps till we get one frequency (should be equal to character length of the string).

*/

#include "encode.h"
#include "decode.h"
#include "node.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

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
	}
}

bool comp (const pair<char, int> f, const pair<char, int> s) {
		return (f.second < s.second);
}

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

struct nodeComp{
	bool operator()(const node* f, const node* s) { return f->freq > s->freq; }
};

node* buildTree(table& fTable) {
	priority_queue<node*, vector<node*>, nodeComp > huffTree;
	for (table::iterator it = fTable.begin(); it != fTable.end(); ++it) {
		huffTree.push(new node(it->first, it->second, NULL, NULL));
	}
	while (huffTree.size() > 1) {
		node* r = huffTree.top();
		huffTree.pop();
		node* l = huffTree.top();
		huffTree.pop();
		int newFreq = r->freq + l->freq;
		node* combined = new node(newFreq, l, r);
		huffTree.push(combined);
	}
	return huffTree.top();
}
 
void generateCode(node* huffTree, huffTable& codes, string code) {
	if (huffTree->is_leaf()) {
		codes[huffTree->data] =  code;
	} else {
	string leftCode = code;
	leftCode += "0";
	generateCode(huffTree->left, codes, leftCode);
	string rightCode = code;
	rightCode += "1";
	generateCode(huffTree->right, codes, rightCode);
	}
}

string encode(huffTable& ht, string message) {
	string res = "";
	for (int i = 0; i < message.length(); ++i) {
		char ch = message[i];
		res += ht[ch];
	}
	return res;
}
