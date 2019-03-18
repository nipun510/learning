#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>


void ltrim(std::string & str)
{
	str.erase(str.begin(), 
		std::find_if_not(str.begin(), str.end(), 
			[](char c){ return std::isspace(c);}
			));
}

void rtrim(std::string & str)
{	
	str.erase(std::find_if_not(str.rbegin(), str.rend(), [](char c){return std::isspace(c);}).base(), 
		str.end());
}

void trim(std::string & str)
{
	ltrim(str);
	rtrim(str);
}

void replace(std::string & str, const std::string & from, const std::string & to)
{
	size_t pos = 0;
	pos = str.find(from, 0);

	while(pos != std::string::npos)
	{
		str.replace(pos, from.length(), to);
		pos = str.find(from, pos);
	}
}

std::vector<std::string> split(const std::string & str, char  del)
{
	std::vector<std::string> result;
	size_t prev = 0;
	for(size_t i = 0; i < str.length(); ++i)
	{
		if(str[i] == del)
		{
			result.emplace_back(str.substr(prev, i-prev));
			prev = i+1;
		}
	}
	result.emplace_back(str.substr(prev, str.length() -1 - prev));
	return result;
}

std::string join(const std::vector<std::string> & items, char del)
{
	if(items.size() == 0)
	{
		return std::string();
	}

	std::ostringstream oss;
	oss << items[0];
	for(size_t i = 1; i < items.size(); ++i)
	{
		oss << del << items[i];
	}
	
	return oss.str();
}


int main()
{

	std::string test_str = "i am indian;you are british;are you good";
	auto ans = split(test_str, ';');
	for(auto item : ans)
	{
		std::cout << item << "\n";
	}
	std::cout << std::endl;
	std::cout << join(ans, '-');

	std::string str = "   hello how are you            ";
	std::cout << "\n";
	trim(str);
	std::cout << str << "|" << std::endl;


	std::string str3{"hi i am kumar i am kumar nikumar"};

	//reverses the source string
	std::reverse(str3.begin(), str3.end());

	replace(str, "how", "ppos");
	std::cout << str << std::endl;
}

