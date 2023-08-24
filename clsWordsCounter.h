#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class clsWordsCounter
{
	 string _FileName;
	 
	 struct sWordAndChar
	 {
		 int wordnum = 0;
		 int charnum = 0;
	 };

	 fstream _File;
	 vector <string> _PutFileContentToVector()
	{
		_File.open(_FileName, ios::in);
		vector <string> vString;
		if (_File.is_open())
		{
			string Line;
			while (getline(_File,Line))
			{
				vString.push_back(Line);
			}
			return vString;
		}
	}
	 sWordAndChar WordsAndCharCounter(string Line, char delim = ' ', char delim2 = ',', char delim3 = ',')
	{
		 sWordAndChar Count;
	
		int i = 0;
		while (i != Line.length() && !Line.empty())
		{

			if (Line[i] == delim || Line[i] == delim2 || Line[i] == delim3)
			{
				Count.charnum += Line.substr(0, i).length();
				Count.wordnum++;
				Line = Line.erase(0, i + 1);
				i = 0;
			}
			i++;
		}
		if(!Line.empty())
		 ++Count.wordnum;
		return Count;
		
	}

	int CalculeFileWords()
	{
		vector <string> vString = _PutFileContentToVector();
		int counter = 0;
		for (auto& i : vString)
		{
			counter += WordsAndCharCounter(i).wordnum;
		}
		return counter;
	}
	
	int CalculeFileChar()
	{
		vector <string> vString = _PutFileContentToVector();
		int counter = 0;
		for (auto& i : vString)
		{
			counter += WordsAndCharCounter(i).charnum;
		}
		return counter;
	}
	int CalculeFileSentence()
	{
		vector <string> vString = _PutFileContentToVector();

		return vString.size();
	}
	
public:
	clsWordsCounter(string filename)
	{
		_FileName = filename;
	}
	int CharNumber()
	{
		return CalculeFileChar();
	}
	int WordsNumber()
	{
		return CalculeFileWords();
	}
	int SentenceNumber()
	{
		return CalculeFileSentence();
	}
};

