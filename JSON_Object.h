#pragma once
#include "Attribute.h"
#include "JSON_Array.h"
#include <vector>
#include <string>
class Attribute;
class JSON_Object
{
private:
	std::string key;
	std::vector<Attribute*> values;
public:
	JSON_Object();
	JSON_Object(const JSON_Object& rhs);
	JSON_Object& operator=(const JSON_Object& rhs);
	~JSON_Object();
	
	void setKey(std::string& rhs);

	void addValue(Attribute*& rhs);
	void addValue(std::string key, std::string value);
	void addValue(std::string key, JSON_Object*& value);
	void addValue(std::string key, JSON_Array*& value);
	std::vector<Attribute*> getValues() const;
	//std::string getValueByKey(std::string key);
};

