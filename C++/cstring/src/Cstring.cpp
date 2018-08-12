//============================================================================
// Name        : Cstring.cpp
// Author      : leo
// Version     :
// Copyright   : This is my coding world
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <assert.h>
#include <stdlib.h>
using namespace std;


class string
{
public:
	char *str;
	string(char *str = NULL);
	~string();
	string(const string& other);  //拷贝构造函数
	string& operator = (string &other);
private:
	char *m_data;
};

string& string::operator =(string &other) //=运算符重载
{
	if(this == &other) return &this;
	delete [] m_data;
	m_data = new char(strlen(other.m_data)+1);
	assert(m_data != NULL);
	strcpy(m_data, other.m_data);
	return *this;
}

string::string(char *p = NULL)
{
	if(p == NULL)
	{
		m_data = new char;
		assert(m_data != NULL);
		*m_data = '\0';
	}
	else
	{
		int len = strlen(p) + 1;
		str = new char[len];
		assert(str != NULL);
		strcpy(m_data, p);
	}

}
string::~string()
{
	delete[] str;
}

string::string(const string& other)
{
	int len = strlen(other.m_data) + 1;
	m_data = new char[len];
	assert(m_data != NULL);
	strcpy(m_data, source.m_data);
}



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
