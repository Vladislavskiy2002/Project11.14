#include "../std_lib_facilities.h"
#include <locale>
#include "windows.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string file_name = "file.txt";
	ifstream ifs{ file_name };
	if (!ifs)
	{
		cerr << "file " << file_name << " is not found" << endl;
		return 3;
	}
	string temp_str;
	int isaln_num = 0;  // counting alphanumeric characters
	int isalp_num = 0;  // counting alphabetic characters
	int isup_num = 0;	// number of capital letters
	int islow_num = 0;	// number of lowercase letters 
	int isdig_num = 0;	// numeric character counting
	int isspa_num = 0;	// whitespace counting
	int nonchar_num = 0; // counting unknown characters
	while (getline(ifs, temp_str))
	{
		for(int i = 0; i < temp_str.size(); i++)
		{
			if (isalnum(temp_str[i]))
			{
				isaln_num++;
			}
			if (isalpha(temp_str[i]))
			{
				isalp_num++;
				if (isupper(temp_str[i]))
				{
					isup_num++;
				}
				else if (islower(temp_str[i]))
				{
					islow_num++;
				}
				else
					error("Error");
			}
			else if (isdigit(temp_str[i]))
			{
				isdig_num++;
			}
			else if (isspace(temp_str[i]))
			{
				isspa_num++;
			}
			else
				nonchar_num++;
		}
	}
	ofstream ofs{"gupsy.txt"};
	if (!ofs)
	{
		cerr << "fileout ERROR" << endl;
		return 3;
	}
	ofs << "counting alphanumeric characters: " << isaln_num << endl;
	ofs << "counting alphabetic characters: " << isalp_num << endl;
	ofs << "number of capital letters: " << isup_num << endl;
	ofs << "number of lowercase letters: " << islow_num << endl;
	ofs << "numeric character counting: " << isdig_num << endl;
	ofs << "whitespace counting: " << isspa_num << endl;
	ofs << "counting unknown characters: " << nonchar_num << endl;
	cout << "bye" << endl;
	cin.get();
	cin.get();
	return 0;
}