#include "node.h"
#include "encode.h"
#include "decode.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
        string testMessage = "This is a test message with lots of words, and phrases and special characters!!#~*";
        table testTable = getFrequencies(testMessage);
        cout << "Message: " << testMessage << endl;
        cout << "Frequency Table: " << endl;

        printfTable(testTable);
        node* huffTree = buildTree(testTable);
        cout << "ftable size: " << testTable.size() << endl;

        huffTable ht;
        generateCode(huffTree, ht);

        for (huffTable::iterator it = ht.begin(); it != ht.end(); ++it) {
                cout << it->first << "=>" << it->second << endl;
        }

        string enc = encode(ht, testMessage);
        cout << "encoded: " << enc << endl;
        cout << "decoded: " << decode_huff(huffTree, enc);

	// gotta collect that memory
        delete huffTree;
}
