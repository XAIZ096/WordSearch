#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "dictionary.h"

using namespace std;


void dictionary::readWords(string fileName)
{
	ifstream inputFile(fileName);
	if (!inputFile.is_open()) {
		throw invalid_argument("ERROR: File not opened successfully.");
	}
	string currentline;
	while (getline(inputFile, currentline)) {
		words.push_back(currentline);
	}

}

void dictionary::sortWords()
{
	sort(words.begin(), words.end());
	/*int lowestIndex = 0;
	for (int i = 0; i < words.size() - 1; i++) {
		lowestIndex = i;
		for (int j = i + 1; j < words.size(); j++){ 
			if (words[j] < words[lowestIndex]) {
				lowestIndex = j;
			}
		}
		string temp = words[i];
		words[i] = words[lowestIndex];
		words[lowestIndex] = temp;
	}*/
}

int dictionary::binarySearch(string target)
{
	int lower = 0;
	int upper = words.size() - 1;
	int searchIndex;
	string thisWord;
	while (lower <= upper) {
		searchIndex = (lower + upper) / 2;
		thisWord = words[searchIndex];
		if (target < words[searchIndex]) {
			upper = searchIndex - 1;
		}
		else if (target > words[searchIndex]) {
			lower = searchIndex + 1;
		}
		else if (target == words[searchIndex]) {
			return searchIndex;
		}

	}
	return -1;
}

string dictionary::returnIndex(int index)
{
	return words[index];
}

ostream& operator<<(ostream& os, const dictionary& dict)
{
	for (int i = 0; i < dict.words.size(); i++) {
		os << dict.words[i] << endl;
	}
	return os;
}