#ifndef NODE_H
#define NODE_H

class node {
	public:
		int freq;
		char data;
		node* left;
		node* right;
		node(int freq, node* left, node* right):data('\0'), freq(freq), left(left), right(right) {}
		node(char data, int freq, node* left, node* right):data(data), freq(freq), left(left), right(right) {}
		~node() { delete left; delete right; }
};

#endif

