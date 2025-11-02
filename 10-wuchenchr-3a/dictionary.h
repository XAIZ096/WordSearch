#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <string>


using namespace std;



class dictionary
{
private:
	vector<string> words;
public:
	void readWords(string fileName);
	void sortWords();
	int binarySearch(string target);
	string returnIndex(int index);
	friend ostream& operator<<(ostream& os, const dictionary& dict);
};
#endif
