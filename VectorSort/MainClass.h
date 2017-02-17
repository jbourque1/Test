#pragma once
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
class MainClass
{
public:
	MainClass();
	~MainClass();
};

void spaceRemoval(string *str);
void extraWords(string *str);
int wordSearch(string *str, string sub, int start);
void seperate(string *str);

