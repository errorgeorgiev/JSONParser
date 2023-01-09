#pragma once
#include "JSON_Object.h"
#include "JSON_Array.h"

#include <string>
class JSON_Array;
class JSON_Object;
class Attribute
{
	friend std::ostream& operator<<(std::ostream& out, const Attribute*& rhs);
private:
	std::string key;
	std::string value;
	JSON_Object* objectValue;
	JSON_Array* arrayValue;
public:
	Attribute();
	Attribute(const Attribute& rhs);
	Attribute(std::string key, std::string value);
	Attribute(std::string key, JSON_Object* objectValue);
	Attribute(std::string key, JSON_Array* arrayValue);
	Attribute& operator=(const Attribute& rhs);
	~Attribute();

	void setKey(const std::string rhs);
	void setValue(const std::string& rhs);
	void setObjectValue(JSON_Object*& rhs);
	void setArrayValue(JSON_Array*& rhs);

	bool objectIsEmpty();
	bool arrayIsEmpty();
	std::string getKey() const;
	std::string getValue() const;
	JSON_Object* getObjectValue();
	JSON_Array* getArrayValue();
};
std::ostream& operator<<(std::ostream& out, const Attribute*& rhs);
