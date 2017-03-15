#ifndef FILE_READER_H
#define FILE_READER_H

#include <string>
#include <fstream>

using namespace std;

class FileReader{
	private:
		ifstream file;
		string filename;
		string boolToString(bool);
	public:
		FileReader(string);
		string getLine();
		bool openFile();				
		void closeFile();
		string status();
};

#endif
