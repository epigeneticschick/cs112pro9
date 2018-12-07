/* Runs an interface that allows for a experiment to be performed.
 * TreeHeight.cpp
 * Lorrayya Williams
 *  Created on: Nov 28, 2018 for CS 1122
 *      Author: llw5
 */

#include "Experiment.h"

using namespace std;

Experiment::Experiment(){

}

void Experiment::Interface(){
	//initializes variable filename
	string filename;

	//asks user to enter a filename
	cout << "Enter a filename: " << flush;

	//initializes variable to filename
	cin >> filename;

	//opens in stream for file
	ifstream in(filename.c_str());
	assert(in.is_open());

	//initializes binary search tree
	BST<long> bst;
	long linelong;

	//initializes value
	unsigned duplicatelines = 0;
	while(in >> linelong){
		//in >> linelong;
		try{
		bst.insert(linelong);
		}
		catch(const Exception& se){
			//counts duplicate lines
			duplicatelines++;
		}
	}
	//
	cout << "Height: " << bst.getHeight() <<
			" Amount of Duplicated Numbers: " << duplicatelines << endl;
}
