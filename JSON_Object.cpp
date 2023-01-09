#include "JSON_Object.h"
#include<iostream>
JSON_Object::JSON_Object()
{
}

JSON_Object::JSON_Object(const JSON_Object& rhs)
{
	this->key = rhs.key;
	this->values = rhs.values;

}

JSON_Object& JSON_Object::operator=(const JSON_Object& rhs)
{
	if (this != &rhs) {
		this->key = rhs.key;
		this->values = rhs.values;
	}
	return *this;
	// TODO: insert return statement here
}

JSON_Object::~JSON_Object()
{
}

void JSON_Object::setKey(std::string& rhs)
{
	this->key = rhs;
}

void JSON_Object::addValue(Attribute*& rhs)
{
	values.push_back(rhs);
}

void JSON_Object::addValue(std::string key, std::string value)
{
	Attribute* att = new Attribute(key, value);
	values.push_back(att);
}

void JSON_Object::addValue(std::string key, JSON_Object*& value)
{
	Attribute *att = new Attribute(key, value);
	std::cout << att->objectIsEmpty() << std::endl;
	values.push_back(att);
}
void JSON_Object::addValue(std::string key, JSON_Array*& value)
{
	Attribute* att = new Attribute(key, value);
	values.push_back(att);
}
std::vector<Attribute*> JSON_Object::getValues() const
{
	return values;
}
