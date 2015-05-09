#ifndef NODE_H_
#define NODE_H_

#include <iostream>

template <typename T>
class node {
    int *keys;  // An array of keys
    int degree;      //  Minimum degree (defines the range for number of keys)
    node **children; // An array of child pointers
    int currentKeys;     //  Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
 
	public:
	 
	
		void setKey(int pos, T k) {
			this->keys[pos] = k;		
		};

		T getKey(int pos) {
			return this->keys[pos];
		}

		void setChildren(int pos, node<T> *nd) {
			this->children[pos] = nd;		
		};

		node<T>* getChildren(int pos) {
			return this->children[pos];
		}

		void setCurrentKeys(int num) {
			this->currentKeys = num;
		};

		int getCurrentKeys() {
			return this->currentKeys;
		};
		
		bool getLeaf() {
			return this->leaf;
		}

		node<T> (int degree1, bool leaf1);   // Constructor
	 
		// A function to traverse all nodes in a subtree rooted with this node
		void traverse();
	 
		// A function to search a key in subtree rooted with this node.
		node<T> *search(T k);   // returns NULL if k is not present.
	 
		// A function that returns the index of the first key that is greater
		// or equal to k
		int findKey(T k);
	 
		// A utility function to insert a new key in the subtree rooted with
		// this node. The assumption is, the node must be non-full when this
		// function is called
		void insertNonFull(T k);
	 
		// A utility function to split the child y of this node. i is index
		// of y in child array children[].  The Child y must be full when this
		// function is called
		void splitChild(int i, node *y);
	 
		// A wrapper function to remove the key k in subtree rooted with
		// this node.
		void remove(T k);
	 
		// A function to remove the key present in idx-th position in
		// this node which is a leaf
		void removeFromLeaf(int idx);
	 
		// A function to remove the key present in idx-th position in
		// this node which is a non-leaf node
		void removeFromNonLeaf(int idx);
	 
		// A function to get the predecessor of the key- where the key
		// is present in the idx-th position in the node
		int getPred(int idx);
	 
		// A function to get the successor of the key- where the key
		// is present in the idx-th position in the node
		int getSucc(int idx);
	 
		// A function to fill up the child node present in the idx-th
		// position in the children[] array if that child has less than degree-1 keys
		void fill(int idx);
	 
		// A function to borrow a key from the children[idx-1]-th node and place
		// it in children[idx]th node
		void borrowFromPrev(int idx);
	 
		// A function to borrow a key from the children[idx+1]-th node and place it
		// in children[idx]th node
		void borrowFromNext(int idx);
	 
		// A function to merge idx-th child of the node with (idx+1)th child of
		// the node
		void merge(int idx);
	 
		// Make BTree friend of this so that we can access private members of
		// this class in btree functions
};

#include "node.cpp"
#endif
