#ifndef NODE_H
#define NODE_H

class node {
	public:
		int freq;
		char ch;
		node* left;
		node* right;
		node(int freq, node* left, node* right):ch('\0'), freq(freq), left(left), right(right) {}
		node(char ch, int freq, node* left, node* right):ch(ch), freq(freq), left(left), right(right) {}
		~node() { delete left; delete right; }
};

#endif

