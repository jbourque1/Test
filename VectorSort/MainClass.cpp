#include "MainClass.h" //hi

vector<string> vec;
string inp;
int num = 0;

MainClass::MainClass()
{
}


MainClass::~MainClass()
{
}

int main()
{

	cout << "String: ";
	getline(cin, inp);
	spaceRemoval(&inp);
	extraWords(&inp);
	seperate(&inp);
	for (size_t i = vec.size() - 1; i >= 0; i--)
	{
		cout << vec[i] << " " << endl;
	}
	system("pause");
	return 0;
}

void spaceRemoval(string *str)
{
	string temp = *str;
	int size = temp.size();
	
	for (int i = 0; i < size; i++)
	{
		if(temp.at(i) == ' ')
		{
			for(int j = i + 1; j < size; j++)
			{
				if (temp.at(j) == ' ')
				{
					temp.erase(j, 1);
					size--;
					j--;
				}
				else
				{
					break;
				}
			}
		}
	}

	*str = temp;
	
}

void extraWords(string *str)
{
	string temp = *str;
	int size = temp.size();
	int start, end;

	for (int i = 0; i < size; i++)
	{
		if (temp.at(i) != ' ')
		{
			start = i;
			for (int j = i + 1; j < size; j++)
			{
				if (temp.at(j) == ' ')
				{
					end = j;
					i = j;
					break;
				}
			}

			if (end != size - 1)
			{
				size -= (temp.substr(start, end).size()) * wordSearch(&temp, temp.substr(start, end), end + 1);
			}
		}

		*str = temp;
	}
}

int wordSearch(string *str, string sub, int start)
{
	string temp = *str;
	if (temp.find(sub, start) != string::npos)
	{
		int start2 = temp.find(sub, start);
		int end2 = start2 + (sub.size());
		temp.erase(start2, sub.size() + 1);
		*str = temp;
		num++;
		wordSearch(str, sub, start);
	}

	return num;
}

void seperate(string *str)
{
	string temp = *str;
	int size = temp.size();
	int start, end;

	for (int i = 0; i < size; i++)
	{
		if (temp.at(i) != ' ')
		{
			start = i;
			for (int j = i + 1; j < size; j++)
			{
				if (temp.at(j) == ' ')
				{
					end = j;
					i = j + 1;
				}
			}
			vec.push_back(temp.substr(start, end));
		}
	}
}
