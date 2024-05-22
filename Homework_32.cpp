#include <iostream>
#include <fstream>
#include <string>


union Data
{
	std::string* str;
	int integer;
	double nointegers;
	Data() {}
	~Data() {}
};
enum DataType
{
	INT,
	DOUBLE,
	STRING,
	NONE
};
struct DataHolder
{
	Data data;
	DataType type;

	DataHolder() : type(NONE) {}
};

DataType typeIdentifier(std::string str);
int intMaker(std::string str);
double doubleMaker(std::string str);



int main()
{
	std::ifstream inputFile;
	std::string pathname = R"(C:\Users\HP\Desktop\input.txt)";

	inputFile.open(pathname);
	if (!inputFile.is_open()) {
		std::cerr << "Error, can't open the file" << std::endl;
		return 0;
	}
	//counting the lines
	int lineCount = 0;
	std::string mine;
	while (std::getline(inputFile, mine)) {
		++lineCount;
	}
	std::cout << "lines count = " << lineCount << std::endl;
	inputFile.close();




	DataHolder* ptr = new DataHolder[lineCount];
	int i = 0;
	//reopening file, for sorting it
	inputFile.open(pathname);
	std::string line;
	while (std::getline(inputFile, line)) {
		std::cout << line << std::endl;
		DataType typeDecide = typeIdentifier(line);
		ptr[i].type = typeDecide;
		if (typeDecide == INT) {
			ptr[i].data.integer = intMaker(line);
		}
		else if (typeDecide == DOUBLE) {
			ptr[i].data.nointegers = doubleMaker(line);
		}
		else {
			ptr[i].data.str = new std::string(line);
		}
		++i;
	}


	for (int i = 0; i < lineCount; ++i) {
		if (ptr[i].type == INT) {
			std::cout << i << " - th line is integer: " << ptr[i].data.integer << std::endl;
		}
		else if (ptr[i].type == DOUBLE) {
			std::cout << i << " - th line is double: " << ptr[i].data.nointegers << std::endl;
		}
		else if (ptr[i].type == STRING) {
			std::cout << i << " - th line is string: " << *(ptr[i].data.str) << std::endl;
		}
	}




	for (int i = 0; i < lineCount; ++i) {
		if (ptr[i].type == STRING)
			delete ptr[i].data.str;
	}
	delete[] ptr;

	inputFile.close();
}


DataType typeIdentifier(std::string str)
{
	int commaCount = 0;
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ',') {
			return STRING;
		}
		else if (str[i] == ',')
			++commaCount;
	}
	if (commaCount == 1)
		return DOUBLE;
	else if (commaCount > 1)
		return STRING;
	else
		return INT;
}

int intMaker(std::string str)
{
	int a = 0;
	int b;
	for (int i = 0; i < str.size(); i++)
	{
		b = str[i] - '0';
		a = a * 10 + b;
	}

	return a;
}

double doubleMaker(std::string str)
{
	double a = 0;
	double b;
	double afterComma = 0;
	double x = 1;
	int i = 0;
	while (str[i] != ',')
	{
		b = str[i] - '0';
		a = a * 10 + b;

		++i;
	}
	++i;
	for (; i < str.size(); ++i)
	{
		b = str[i] - '0';
		afterComma = afterComma * 10 + b;
		x *= 10;
	}

	a = a + (afterComma / x);
	return a;
}