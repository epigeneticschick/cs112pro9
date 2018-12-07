/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Lorrayya Williams
 * Date: November 20, 2018
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
using namespace std;

template <class Item>

class BST {
public:

	virtual ~BST();
	BST();
	bool isEmpty() const;
	unsigned getNumItems() const;

	void traverseInorder();
	void traversePreorder();
	void traversePostorder();
	void insert(const Item& it);
	bool contains(const Item& item) const;
	unsigned getHeight();

private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();

            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
            void insert(const Item& it);
            bool contains(const Item& item) const;
            unsigned getHeight();
		
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};
template <class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

template <class Item>
BST<Item>::BST(){
	myRoot = NULL;
	myNumItems = 0;
}

template <class Item>
BST<Item>::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

template <class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

template <class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

template <class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

//processes the binary search tree before going through either side
template <class Item>
void BST<Item>::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

template <class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

template <class Item>
void BST<Item>::Node::processItem() {
		cout << ' ' << myItem;
}

//Processes Binary Search tree after going through both the left and right side.
template <class Item>
void BST<Item>::traversePostorder(){
	if(!isEmpty()){
		myRoot->traversePostorder();
	}

}

template <class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

//Processes the Binary Search Tree after going through the left side
template <class Item>
void BST<Item>::traverseInorder(){
	if(!isEmpty()){
		myRoot->traverseInorder();
	}
}

template <class Item>
void BST<Item>::Node::traverseInorder(){
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}

//Adds item to the Binary Search Tree
template <class Item>
void BST<Item>::insert(const Item& it){
	if (isEmpty()){
		myRoot = new Node(it);
	}
	else{
		try {
			myRoot->insert(it);
		}
		catch (const Exception& e){
			throw Exception("Node::insert(it)", "Insertion Failed!");
		}
	}
	myNumItems++;
}

template <class Item>
void BST<Item>::Node::insert(const Item& it){
	if( it < myItem){
		if(myLeft == NULL){
			myLeft = new Node(it);
		}
		else{
			myLeft->insert(it);
		}
	}
	else if(it > myItem){
		if(myRight == NULL){
			myRight = new Node(it);
		}
		else{
			myRight->insert(it);
		}
	}
	else{
		throw Exception("Node::insert(it)", "The item is already in the list!");
	}
}

//Checks if search tree has an item
template <class Item>
bool BST<Item>::contains(const Item& item) const{
	if(isEmpty()){
		return false;
	}
	else{
		myRoot->contains(item);
	}

}

template <class Item>
bool BST<Item>::Node::contains(const Item& item) const{
	if(item < myItem){
		if(myLeft == NULL){
			return false;
		}
		else{
			myLeft->contains(item);
		}
	}
	else if(item > myItem){
		if(myRight == NULL){
			return false;
		}
		else{
			myRight->contains(item);
		}
	}
	else{
		return true;
	}

}

template <class Item>
unsigned BST<Item>::getHeight(){
	//intializes the height
	unsigned height = 0;
	if (isEmpty()){
		return height;
	}
	else{
		myRoot->getHeight();
	}
}

template <class Item>
unsigned BST<Item>::Node::getHeight(){

	unsigned left_side = 0;
	unsigned right_side =0 ;
	if (myLeft != NULL) {
		left_side = myLeft->getHeight();
	}
	if (myRight != NULL) {
		right_side= myRight->getHeight();
	}

	return max(left_side, right_side) +1;
}


#endif /*BST_H_*/

