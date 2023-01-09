#pragma once
#include <string>
#include "JSON_Object.h"
class File
{
private:
	std::string fileText;
	std::string fileName;
	JSON_Object* mainObject;
	bool validateScope(std::string& fileText);
	bool validateSquareBrackets(std::string& fileText);
	bool validateCommas(std::string& fileText);
	bool validateColumns(std::string& fileText);
	void toObject(int& i, JSON_Object*& object, std::string& fileText);
	void toArray(int& i, JSON_Array*& array, std::string& fileText);
	void toJSON(std::string& fileText, JSON_Object*& object, int n = 1 );
	void deepArraySearch(JSON_Array*& array, std::vector<Attribute*>& values, std::string& key);
	void deepObjectSearch(JSON_Object*& object, std::vector<Attribute*>& values, std::string& key);
	bool validateString(std::string& stringText);
	std::vector<std::string> pathToWords(std::string& path);
public:
	File();
	File(std::string rhs);
	File(const File& rhs);
	File& operator = (const File& rhs);
	~File();
	
	void openFile(std::string rhs);
	void save();
	std::string getAllText(std::fstream&);
	std::string getText()const;
	bool validate();
	void closeFile();
	void print();
	std::vector<Attribute*> search(std::string key);
	void set(std::string& path, std::string& string);
};
std::ostream& operator<<(std::ostream& out, const std::vector<Attribute*>& values);