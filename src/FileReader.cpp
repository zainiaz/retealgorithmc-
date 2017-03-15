#include "FileReader.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

FileReader::FileReader(string name){
	this->filename = name;
}

string FileReader::getLine(){
	string tmp;

	if(getline(file, tmp)){
		return tmp;
	}
	else{
		return string("EOF");
	}
}

void FileReader::closeFile(){
	this->file.close();
}

bool FileReader::openFile(){
	this->file.open(filename.c_str());
	return file.is_open();
}

string FileReader::status(){
	string return_string = "FILE NAME: " + filename + "\nOPEN: " + boolToString(this->file.is_open()) + "\n";
	return return_string;
}

string FileReader::boolToString(bool value){
	return value? "true" : "false";
}
