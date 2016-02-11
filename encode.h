#include "node.h"
#include <vector>
#include <utility>
#include <string>
#include <map>

using namespace std;

typedef vector<pair<char, int> > table;
typedef map<char, string> huffTable;

void printfTable(table t);
void insert(table &fTable, char c);
bool comp (const pair<char, int> f, const pair<char, int> s);
void sortByFreq(table &v);
table getFrequencies(string message);
node* buildTree(table& fTable);
void generateCode(node* huffTree, huffTable& codes, string code = "");
string encode(huffTable& ht, string message);
