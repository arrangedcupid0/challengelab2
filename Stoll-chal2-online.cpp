#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

char traducir(string);

int main()
{
	ifstream Morse;
	Morse.open("morse.txt");

	char translated;
	string line;
	string tmp = "";
	queue<char> word;
	string tline = "";
	queue<char> chr;
	bool eow = false;

	while(getline(Morse, line))
	{
		for(int i = 0; i < line.size(); i++)
		{
			if(line[i] == '.' || line[i] == '-')
			{
					chr.push(line[i]);
			} else if(line[i] == ' ' && line[i+1] == ' ' && line[i+2] == ' ') {
				{
					i += 3;
					int how = word.size();
					for(int k = 0; k < how; k++)
					{
						tline += word.front();
						word.pop();
					}
					tline += " ";

				}
			} else {
			
				int howfar = chr.size();
				for(int j = 0; j < howfar; j++)
				{
					tmp += chr.front();
					chr.pop();
				}
//			cout << tmp << endl;
				translated = traducir(tmp);
				tmp = "";
				if(translated != '0')
				{
					word.push(translated);
				}
			}

		}
		cout << tline << endl;
		tline = "";
	}
}
char traducir(string test)
{
	if(test == ".-"){
		return 'a';
	} else if(test == "-..."){
		return 'b';
	} else if(test == "-.-."){
		return 'c';
	} else if(test == "-.."){
		return 'd';
	} else if(test.compare(".") == 0){
		return 'e';
	} else if(test.compare("..-.") == 0){
		return 'f';
	} else if(test.compare("--.") == 0){
		return 'g';
	} else if(test.compare("....") == 0){
		return 'h';
	} else if(test.compare("..") == 0){
		return 'i';
	} else if(test.compare(".---") == 0){
		return 'j';
	} else if(test.compare("-.-") == 0){
		return 'k';
	} else if(test.compare(".-..") == 0){
		return 'l';
	} else if(test.compare("--") == 0){
		return 'm';
	} else if(test.compare("-.") == 0){
		return 'n';
	} else if(test.compare("---") == 0){
		return 'o';
	} else if(test.compare(".--.") == 0){
		return 'p';
	} else if(test.compare("--.-") == 0){
		return 'q';
	} else if(test.compare(".-.") == 0){
		return 'r';
	} else if(test.compare("...") == 0){
		return 's';
	} else if(test.compare("-") == 0){
		return 't';
	} else if(test.compare("..-") == 0){
		return 'u';
	} else if(test.compare("...-") == 0){
		return 'v';
	} else if(test.compare(".--") == 0){
		return 'w';
	} else if(test.compare("-..-") == 0){
		return 'x';
	} else if(test.compare("-.--") == 0){
		return 'y';
	} else if(test.compare("--..") == 0){
		return 'z';
	} else {
		return '0';
	}
}
