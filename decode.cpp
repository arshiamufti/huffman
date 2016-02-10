#include "node.h"

#include <string>
#include <iostream>
using namespace std;

// TODO: make `decode` more efficient using memoization maybe?
// TODO: write `decode` using recursion
// TODO: read up on improvements to huffman coding
// TODO: write better tests
// TODO: write `encode`

bool is_leaf(node * n) {
    return !(n->left || n->right);
}

string decode_huff(node * root,string s) {
    if (!root) return "";
    node * n = root;
    string res = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '0') {
            n = n->left;
        } else if (s[i] == '1') {
            n = n->right;
        }
        
        if (is_leaf(n)) {
            res += n->data;
            n = root;
        }
    }
    cout << res;
    return res;
}


