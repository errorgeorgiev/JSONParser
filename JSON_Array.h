#pragma once
#include "JSON_Object.h"
#include <vector>
#include <string>
class JSON_Object;
class JSON_Array
{
private:
	std::string key;
	std::vector<JSON_Object*> objects;
public:
	JSON_Array();
	JSON_Array(const JSON_Array& rhs);
	JSON_Array& operator=(const JSON_Array& rhs);
	~JSON_Array();

	void setKey(std::string& rhs);
	void addObject(JSON_Object*& rhs);
	std::vector<JSON_Object*> getObjectValues();
};

