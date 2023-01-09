#include "File.h"
#include <fstream>
#include "Stack.h"
bool File::validateScope(std::string& fileText)
{
	Stack stack;
	
	for (int i = 0; i < fileText.length(); i++)
	{
		if (fileText[i] == '{') {
			stack.push('{');
		}
		else if (fileText[i] == '}') {
			if(!stack.isEmpty())
				stack.pop();
			else {
				std::cout << "Curly brackets are invalid" << std::endl;
				return false;
			}
		}
	}
	if (stack.isEmpty()) {
		std::cout << "Curly brackets are valid" << std::endl;
		return true;
	}
	else std::cout << "Curly brackets are invalid. Check them!" << std::endl;
	return false;
}
bool File::validateSquareBrackets(std::string& fileText)
{
	Stack stack;
	for (int i = 0; i < fileText.length(); i++)
	{
		if (fileText[i] == '[') {
			stack.push('[');
		}
		else if (fileText[i] == ']') {
			if (!stack.isEmpty())
				stack.pop();
			else {
				std::cout << "Square brackets are invalid" << std::endl;
				return false;
			}
		}
	}
	if (stack.isEmpty()) {
		std::cout << "Square brackets are valid" << std::endl;
		return true;
	}
	else std::cout << "Square brackets are invalid. Check them!" << std::endl;
	return false;
}
bool File::validateCommas(std::string& fileText)
{
	bool flag = true;
	for (int i = 0; i < fileText.length(); i++)
	{
		if (fileText[i] == ',')
		{
			if (fileText[i + 1] != '\"') {
				if (fileText[i + 1] != '{') {
					if (fileText[i + 1] != '[') {
						std::cout << "Commas are invalid!" << std::endl;
						flag = false;
						return false;
					}
				}
				
			}
		}
	}
	if (flag) {
		std::cout << "Commas are valid!" << std::endl;
		return true;
	}
}
bool File::validateColumns(std::string& fileText)
{
	int count = 0;
	bool flag = true;
	for (int i = 0; i < fileText.length(); i++)
	{
		if (fileText[i] == '\"') count++;
		else if (fileText[i] == ':' && count%2==1) {
			std::cout << "Columns are invalid!" << std::endl;
			flag = false;
			return false;
		}
	}
	if (flag) {
		std::cout << "Columns are valid!" << std::endl;
		return true;
	}
}
void File::print()
{
    int counter = 0;
	for(int i = 0; i < fileText.length(); i++) {
        if(fileText[i] == '{' || fileText[i] == '[') {
            counter++;
			std::cout << fileText[i] << std::endl;
			for(int j = 0; j < counter*3; j++) {
                std::cout << " ";
            }
        }
		else if (fileText[i] == '}' && fileText[i + 1] == ',') {
			std::cout << std::endl;
			counter--;
			for (int j = 0; j < counter * 3; j++) {
				std::cout << " ";
			}
			std::cout << fileText[i];
		}
		else
        if(fileText[i] == '}' || fileText[i] == ']') {
            counter--;
			std::cout << std::endl;
			for (int j = 0; j < counter * 3; j++) {
				std::cout << " ";
			}
			std::cout << fileText[i] << std::endl;
        }
		
		else
        if(fileText[i] == ',') {
			std::cout << fileText[i] << std::endl;
            for(int j = 0; j < counter*3; j++) {
                std::cout << " ";
            }
			
        }
		else {
			std::cout << fileText[i];
			
		}
		
    }


}
void File::toObject(int& i, JSON_Object*& object, std::string& fileText)
{
	for (; i < fileText.length(); i++) {
		std::string _key = "";
		std::string _value = "";

		if (fileText[i] == '\"') {
			_key = "";
			i++;
			while (fileText[i] != '\"') {
				_key += fileText[i];
				i++;
			}
			i++;
		}
		if (fileText[i] == ':') {
			i += 2;
			if (fileText[i] == '{') {
				i++;
				JSON_Object* newObject = new JSON_Object();
				toObject(i, newObject,fileText);
				object->addValue(_key, newObject);
				i++;
			}
			if (fileText[i] == '[') {
				JSON_Array* newArray = new JSON_Array();
				i++;
				toArray(i, newArray, fileText);
				object->addValue(_key, newArray);
			}
			else {
				_value = "";
				while (true) {
					if (fileText[i] == ',' || fileText[i] == '}') {
						break;
					}
					_value += fileText[i];
					i++;
				}
			}
		}
		if (_key != "" && _value != "") {
			object->addValue(_key, _value);
			_key = "";
			_value = "";
			
		}
		if (fileText[i] == '}')
			return;
	}
}
void File::toArray(int& i, JSON_Array*& _array, std::string& fileText)
{
	for (; i < fileText.length(); i++) {
		if (fileText[i] == '{') {
			i++;
			JSON_Object* newObject = new JSON_Object();
			toObject(i, newObject, fileText);
			_array->addObject(newObject);
		}
		if (fileText[i] == ']') 
			return;
	}
}
	
void File::toJSON(std::string& fileText, JSON_Object*& object, int n)
{
	
	toObject(n, object, fileText);
	
	for (int i = 0; i < mainObject->getValues().size(); i++)
	{
		std::cout << mainObject->getValues()[i]->getKey() << " ";
		std::cout << mainObject->getValues()[i]->getValue() << std::endl;
	}
}

File::File()
{
	mainObject = new JSON_Object();
}
File::File(std::string rhs)
{
	mainObject = new JSON_Object();
	this->fileText = rhs;
}
File::File(const File& rhs)
{
	mainObject = rhs.mainObject;
	this->fileText = rhs.fileText;
}
File& File::operator=(const File& rhs)
{
	if (this != &rhs) {
		mainObject = rhs.mainObject;
		this->fileText = rhs.fileText;
	}
	return *this;
}
File::~File()
{
}
void File::openFile(std::string rhs)
{
	std::fstream file;
	fileName = rhs;
	file.open(rhs);
	fileText = getAllText(file);
	file.close();
}

void File::save()
{
	std::ofstream file;
	file.open(fileName);
	file << fileText;
	file.close();
}

std::string File::getAllText(std::fstream& file)
{
	
	std::string fullText = "";
	char line;
	int count = 0;
	bool flag = true;
	while (file.get(line)) {
		if (flag) {
			if (line != '\n') {
				fullText += line;
			}
			else {
				flag = false;
			}
		}
		else if(line!=' '){
			flag = true;
			fullText += line;
		}
	}
	std::cout << count <<std:: endl;
	return fullText;
}

std::string File::getText() const
{
	return this->fileText;
}

bool File::validate()
{
	bool scope = validateScope(this->fileText);
	bool brackets = validateSquareBrackets(this->fileText);
	bool commas = validateCommas(this->fileText);
	bool columns = validateColumns(this->fileText);
	if (scope && brackets && commas && columns) {
		toJSON(this->fileText,mainObject);
		return true;
	}
	return false;
}

void File::closeFile()
{
	fileText = "";
	mainObject = nullptr;
	std::cout << "File closed!" << std::endl;
}
void File::deepArraySearch(JSON_Array*& _array, std::vector<Attribute*>& values, std::string& key)
{
	for (int i = 0; i < _array->getObjectValues().size(); i++)
	{
		deepObjectSearch(_array->getObjectValues()[i], values, key);
	}
}
void File::deepObjectSearch(JSON_Object*& object, std::vector<Attribute*>& values, std::string& key)
{
	for (int i = 0; i < object->getValues().size(); i++)
	{
		if (object->getValues()[i]->getKey() == key) {
			values.push_back(object->getValues()[i]);
		}
		if (!object->getValues()[i]->objectIsEmpty()) {
			JSON_Object* _object = object->getValues()[i]->getObjectValue();
			deepObjectSearch(_object, values, key);
		}
	}
}
bool File::validateString(std::string& stringText)
{
	int n = 0;
	if (stringText[0] == '{')n++;
	if (stringText[stringText.length() - 1] == '}')n--;
	bool scope = validateScope(stringText);
	bool brackets = validateSquareBrackets(stringText);
	bool commas = validateCommas(stringText);
	bool columns = validateColumns(stringText);
	if (scope && brackets && commas && columns && n==0) {
		return true;
	}
	return false;
}
std::vector<Attribute*> File::search(std::string key) {

	std::vector<Attribute*> vallues;
	for(int i = 0; i < mainObject->getValues().size(); i++ ) {
		if (mainObject->getValues()[i]->getKey() == key) {
			vallues.push_back(mainObject->getValues()[i]);
		}
		if (!mainObject->getValues()[i]->arrayIsEmpty()) {
			JSON_Array* _array = mainObject->getValues()[i]->getArrayValue();
			deepArraySearch(_array, vallues, key);
		}
	}
	return vallues;
}

void File::set(std::string& path, std::string& string) {
	std::vector<std::string> words = pathToWords(path);
	bool validator = validateString(string);
	for (int i = 0; i < mainObject->getValues().size(); i++)
	{
		if (mainObject->getValues()[i]->getKey() == words[0]) {
			if (mainObject->getValues()[i]->getValue() != "" && validator==false) {
				mainObject->getValues()[i]->setValue(string);
				break;
			}
			if (validator) {
				JSON_Object* object = new JSON_Object();
				toJSON(string, object);
				mainObject->getValues()[i]->setObjectValue(object);
				mainObject->getValues()[i]->setValue("");
				JSON_Array* arr = nullptr;
				mainObject->getValues()[i]->setArrayValue(arr);
			}
		}
	}
	/*if (validator) {
		JSON_Object* object = new JSON_Object();
		toJSON(string, object);
	}*/
}
std::vector<std::string> File::pathToWords(std::string& path) {
	std::vector<std::string> pathWords;
	int wordCounter = 0;
	pathWords.push_back("");
	for (int i = 0; i < path.size(); i++) {
		if (path[i] != '/') {
			pathWords[wordCounter] += path[i];
		}
		if (path[i] == '/') {
			wordCounter++;
		}
	}
	return pathWords;
}
std::ostream& operator<<(std::ostream& out, const std::vector<Attribute*>& values)
{
	for (int i = 0; i < values.size(); i++)
	{
		out << values[i] << std::endl;
	}
	return out;
}
