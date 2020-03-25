//hw1.cpp
//Isaiah Kiefer
#include <iostream>
#include <iomanip>
#include "List.h"
#include "timer.h"
#include <string>
#include <cctype>
#include <fstream>
using std::string;
using std::setprecision;
using std::endl;
using std::cout;
using std::ifstream;
using std::ofstream;

string cleanWord(string badWord);

int main()
{
	List<string> dict;
	Timer tim;
	ifstream inDict;
	ifstream inBook;
	ofstream outFile;
	string dictBad;
	string bookBad;
	string clean;
	int skipped = 0;


	inDict.open("dict.txt");

	while (inDict >> dictBad)
	{
		clean = cleanWord(dictBad);
		dict.insert(clean);
		//dict.printNode();
	}
	//dict.sort();
	inDict.close();
	tim.Start();
	inBook.open("test.txt");
	while (inBook >> bookBad)
	{
		clean = cleanWord(bookBad);
		if (clean.size() == 0);
		else if (isdigit(clean[0]) || clean[0] == '\'')
		{
			skipped++;
		}
		else
		{
			dict.find(clean);
		}
	}
	tim.Stop();
	cout << "Dictionary size: " << dict.size << endl;
	cout << "Done checking and these are the results" << endl;
	cout << "finished in time: " << setprecision(2) << tim.Time() << endl;
	cout << "There are " << dict.spellChecked << " words found in the dictionary" << endl;
	cout << "     " << dict.foundComp << " compares. Average: " << dict.foundComp / dict.spellChecked << endl;
	cout << "There are " << dict.notSpelled << " words NOT found in the dictionary" << endl;
	cout << "     " << dict.notComp << " compares. " << " Average: " << dict.notComp / dict.notSpelled << endl;
	cout << "There are " << skipped << " words not checked." << endl;
	outFile.open("misspelled.txt");
	int mis = dict.text.size();
	for (int i = 0; i < mis; i++)
	{
		outFile << dict.text[i] << endl;
	}
	outFile.close();
}

string cleanWord(string badWord)
{
	string goodWord;
	int badSize = badWord.size();
	for (int i = 0; i < badSize; i++)
	{
		if (isalnum(badWord[i]))
		{
			if (isalpha(badWord[i]))
			{
				goodWord += tolower(badWord[i]);
			}
			else {
				goodWord += badWord[i];
			}

		}
		else if (badWord[i] == '\'')
		{
			goodWord += badWord[i];
		}
	}
	return goodWord;
}

