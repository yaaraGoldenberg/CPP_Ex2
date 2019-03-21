#include <iostream>
#include <cstdlib>
#include "Tree.hpp"
#include <stdexcept>
using namespace std;
using namespace ariel;

Tree::Tree() {
	Root = NULL;
}


Tree::node* Tree::createLeaf(int i) {
	node* n = new node;
	n->key = i;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void Tree::insert(int i) {
	insert_node(i, Root);
}

void Tree::insert_node(int i, node* n) {
	if (Root == NULL) {
		Root = createLeaf(i);
	}
	else if (i < n->key) {
		if (n->left != NULL) {
			insert_node(i, n->left);
		}
		else {
			n->left = createLeaf(i);
		}
	}
	else if (i > n->key) {
		if (n->right != NULL) {
			insert_node(i, n->right);
		}
		else {
			n->right = createLeaf(i);
		}
	}
	else {
		throw std::invalid_argument("The data is already in the tree\n");
	}
}

void Tree::print() {
	printInOrder(Root);
	cout << "\n";
}

void Tree::printInOrder(node* n) {
	if (Root != NULL) {
		if (n->left != NULL) {
			printInOrder(n->left);
		}
		cout << n->key <<" ";
		if (n->right != NULL) {
			printInOrder(n->right);
		}
	}
	else {
		throw std::invalid_argument("The tree is empty\n");
	}
}

Tree::node* Tree::returnNode(int i) {
	return returnNodePrivate(i, Root);
}

Tree::node* Tree::returnNodePrivate(int i, node* n) {
	if (n != NULL) {
		if (n->key == i) {
			return n;
		}
		else {
			if (i < n->key) {
				return returnNodePrivate(i, n->left);
			}
			else {
				return returnNodePrivate(i, n->right);
			}
		}
	}
	return NULL;
}
int Tree::findSmallest() {
	return findSmallestPrivate(Root);
}

int Tree::findSmallestPrivate(node* n) {
	if (Root == NULL) {
		return -1;
	}
	else {
		if (n->left != NULL) {
			return findSmallestPrivate(n->left);
		}
		else {
			return n->key;
		}
	}
}
bool Tree::contains(int i) {
	return containsNode(i, Root);
}
bool Tree::containsNode(int i, node* n) {
	if (n != NULL) {
		if (n->key == i) {
			return true;
		}
		else {
			if (i < n->key) {
				return returnNodePrivate(i, n->left);
			}
			else {
				return returnNodePrivate(i, n->right);
			}
		}
	}
	return false;
}

int Tree::size() {
	return treeSize(Root);
}

int Tree::treeSize(node* n) {
	if (n == NULL) {
		return 0;
	}
	return (treeSize(n->left) + 1 + treeSize(n->right));
}


void Tree::remove(int i) {
	removeNode(i, Root);
}

void Tree::removeNode(int i, node* parent) {
	if (Root != NULL) {
		if (Root->key == i) {
			removeRoot();
		}
		else {
			if (i < parent->key & parent->left != NULL) {
				parent->left->key == i ?
					removeMatch(parent, parent->left, true) :
					removeNode(i, parent->left);
			}
			else if (i > parent->key & parent->right != NULL) {
				parent->right->key == i ?
					removeMatch(parent, parent->right, false) :
					removeNode(i, parent->right);
			}
			else {
				throw std::invalid_argument("The data was not found in the tree\n");
			}
		}
	}
	else {
		throw std::invalid_argument("The tree is empty\n");
	}
}

int Tree::root() {
	if (Root == NULL) {
		return -1;
	}
	else {
		return Root->key;
	}
}

int Tree::parent(int i) {
	return findParent(i, Root);
}

int Tree::findParent(int i, node* n) {
	if (Root != NULL && contains(i)) {
		if (Root->key != i) {
			if (i < n->key) {
				if (n->left->key == i) {
					return n->key;
				}
				else {
					return findParent(i, n->left);
				}
			}
			else if (n->right->key == i) {
				return n->key;
			}
			else {
				return findParent(i, n->right);
			}
		}
		else {
			throw std::invalid_argument("The data belong to the root\n");
			return -1;
		}
	}
	else{
		throw std::invalid_argument("The data was not found in the tree\n");
		return -1;
	}
}

int Tree::left(int i) {
	node* n = returnNode(i);
	if (n != NULL) {
		if (n->left == NULL) {
			return -1;
		}
		else {
			return n->left->key;
		}
	}
	else {
		throw std::invalid_argument("The data is not in the tree\n");
		return -1;
	}
}

int Tree::right(int i) {
	node* n = returnNode(i);
	if (n != NULL) {
		if (n->right == NULL) {
			return -1;
		}
		else {
			return n->right->key;
		}
	}
	else {
		throw std::invalid_argument("The data is not in the tree\n");
		return -1;
	}
}

void Tree::removeRoot() {
	if (Root != NULL) {
		node* delNode = Root;
		int rootKey = Root->key;
		int smallestInRight;

		//non children
		if (Root->left == NULL && Root->right == NULL) {
			Root = NULL;
			delete delNode;
		}
		//only one child
		else if (Root->left == NULL && Root->right != NULL) {
			Root = Root->right;
			delNode->right = NULL;
			delete delNode;
		}
		else if (Root->left != NULL && Root->right == NULL) {
			Root = Root->left;
			delNode->left = NULL;
			delete delNode;
		}
	//two children
	else {
		smallestInRight = findSmallestPrivate(Root->right);
		removeNode(smallestInRight, Root);
		Root->key = smallestInRight;
	  }
	}
	else {
		throw std::invalid_argument("The tree is empty\n");
	}
}
void Tree::removeMatch(node* parent, node* match, bool left) {
	if (Root != NULL) {
		node* delNode;
		int matchKey = matchKey = match->key;
		int smallestInRirht;
		//non children
		if (match->left == NULL && match->right == NULL) {
			delNode = match;
			left == true ? parent->left = NULL : parent->right = NULL;
			delete delNode;
		}
		//only one child
		else if (match->left == NULL && match->right != NULL) {
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			delNode = match;
			delete delNode;
		}
		else if (match->left != NULL && match->right == NULL) {
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = NULL;
			delNode = match;
			delete delNode;
		}
		//two children
		else {
			smallestInRirht = findSmallestPrivate(match->right);
			removeNode(smallestInRirht, match);
			match->key = smallestInRirht;
		}
	}
	else {
		throw std::invalid_argument("The tree is empty\n");
	}
}




