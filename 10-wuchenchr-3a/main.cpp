#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "dictionary.h"

using namespace std;


int main() {
	try {
		dictionary newdic;
		newdic.readWords("C:\\Dictionary.txt");
		cout << newdic.returnIndex(0) << endl;
		newdic.sortWords();
		cout << newdic.returnIndex(0) << endl;
		cout << newdic.binarySearch("Birthdate") << " " << newdic.binarySearch("apple") << " " << newdic.binarySearch("kjadflkajdsflkajsdflkasdjflkasdjf");
		cout << newdic;
		return 0;
	}
	catch (invalid_argument e) {
		cout << e.what();
	}
}