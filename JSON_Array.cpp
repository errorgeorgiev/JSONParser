#include "JSON_Array.h"

JSON_Array::JSON_Array()
{
}

JSON_Array::JSON_Array(const JSON_Array& rhs)
{
	this->key = rhs.key;
	this->objects = rhs.objects;
}

JSON_Array& JSON_Array::operator=(const JSON_Array& rhs)
{
	if (this != &rhs) {
		this->key = rhs.key;
		this->objects = rhs.objects;
	}
	return *this;
	// TODO: insert return statement here
}

JSON_Array::~JSON_Array()
{
}

void JSON_Array::setKey(std::string& rhs)
{
	this->key = rhs;
}

void JSON_Array::addObject(JSON_Object*& rhs)
{
	this->objects.push_back(rhs);
}

std::vector<JSON_Object*> JSON_Array::getObjectValues()
{
	return objects;
}
