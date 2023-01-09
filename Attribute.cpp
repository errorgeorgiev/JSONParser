#include "Attribute.h"
#include <iostream>
Attribute::Attribute():objectValue(nullptr),arrayValue(nullptr)
{
}

Attribute::Attribute(const Attribute& rhs)
{
	this->key = rhs.key;
	this->value = rhs.value;
	this->objectValue = objectValue;
	this->arrayValue = arrayValue;
}


Attribute::Attribute(std::string key, std::string value) :objectValue(nullptr), arrayValue(nullptr)
{
	this->key = key;
	this->value = value;
}
Attribute::Attribute(std::string key, JSON_Object* objectValue) : arrayValue(nullptr)
{
	this->key = key;
	this->objectValue = objectValue;
}
Attribute::Attribute(std::string key, JSON_Array* arrayValue) : objectValue(nullptr)
{
	this->key = key;
	this->arrayValue = arrayValue;
}
Attribute& Attribute::operator=(const Attribute& rhs)
{
	if (this != &rhs) {
		this->key = rhs.key;
		this->value = rhs.value;
		this->objectValue = rhs.objectValue;
		this->arrayValue = rhs.arrayValue;
	}
	return *this;
}

Attribute::~Attribute()
{
	
}

void Attribute::setKey(const std::string rhs)
{
	this->key = rhs;
}

void Attribute::setValue(const std::string& rhs)
{
	this->value = rhs;
}

void Attribute::setObjectValue(JSON_Object*& rhs)
{
	this->objectValue = rhs;
}

void Attribute::setArrayValue(JSON_Array*& rhs)
{
	this->arrayValue = rhs;
}

bool Attribute::objectIsEmpty()
{
	if(objectValue == nullptr)
		return true;
	return false;
}

bool Attribute::arrayIsEmpty()
{
	if (arrayValue == nullptr)
		return true;
	return false;
}

std::string Attribute::getKey() const
{
	return key;
}


std::string Attribute::getValue() const
{
	return value;
}

JSON_Object* Attribute::getObjectValue()
{
	return objectValue;
}

JSON_Array* Attribute::getArrayValue()
{
	return arrayValue;
}

std::ostream& operator<<(std::ostream& out, const Attribute*& rhs)
{
	out << rhs->getKey() << " " << rhs->getValue();
	return out;
}
