
//#include "stdafx.h"

#include<sstream>

#include<iostream>

#include<fstream>

#include<vector>

#include <list>

//#include<conio.h>

#include<cstring>

#include <unordered_set>


using namespace std;


unordered_set<std::string> myset = {"" };



void hashtab() {

	std::fstream readDict("./dictionary.txt");	//using unordered set to increase efficiency 

	string word;

	std::cout << "Loading Dictionary to Unordered set"<<endl;

	if (readDict.is_open()) {

		while (!readDict.eof()) {

			std::getline(readDict, word);
           
			myset.insert(word);

		

		}

	}



}



bool check_unknown(string lineinput)	//to check if line contains any unknown words

{

	string buf;

	stringstream ss(lineinput);

	vector<string> tokens;

	while (ss >> buf)

	{

		tokens.push_back(buf);

		buf.erase(buf.find_last_not_of(",.':-") + 1);



		std::unordered_set<string>::const_iterator it = myset.find(buf);

		if (it != myset.end()) {

			std::cout << "true" << endl;

			continue;

		}

		else {

			std::cout << "line eliminated" << endl;

			return 0;

		}



	}

	return 1;



}



int main()

{

	hashtab();

	std::fstream readfile("./Text.txt");

	//std::ofstream outputfile;
	//outputfile.open("./Result..txt");




	if (readfile.is_open()) {

		std::cout << "file is open" << std::endl;

		std::string  line;

		std::string input;





	label:	while (!readfile.eof()) {



		while (std::getline(readfile, line)) {

			if (line.empty())

				break;

			else

				input = line;

			std::cout << "new Line Fetched ==================" << endl;

		

			if (check_unknown(input) == 1)

			{

				//Writing output file here

				std::cout << "matter to write " << input << endl;

			//	outputfile << input<<endl ;



			}

			else

			{

				goto label;

			}



		}





	}

			std::ofstream ofs;

		//	ofs.open("./Texxt.txt", std::ofstream::out | std::ofstream::trunc);

		//	ofs.close();



		//	std::ifstream fin("./Result.txt");

		//	std::ofstream fout("~/Texxt.txt");		//finally obtaining desired result in the original Text.txt file

		//	std::string line1;

		//	while (std::getline(fin, line1, '.'))

		//		fout << line1 << '\n';

			readfile.close();

	}



	//_getch();

	return 1;

}



