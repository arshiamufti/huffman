#include "node.h"
#include <vector>
#include <utility>
#include <string>

using namespace std;

typedef vector<pair<char, int> > table;

void printfTable(table t);
void insert(table &fTable, char c);
bool comp (const pair<char, int> f, const pair<char, int> s);
void sortByFreq(table &v);
table getFrequencies(string message);
node* buildTree(table& fTable);

