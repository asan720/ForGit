#include <iostream>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

void InsertProduct(std::string category, std::string underCategory, std::string name, int cost)
{
	std::ifstream file("base.json");
	json jsonData;
	if (!file.is_open())
	{
		std::cout << "error file";
	}
	else if (file.peek() != std::ifstream::traits_type::eof()) 
	{
		file >> jsonData;
	}
	
	
	
	
	
	jsonData[category][underCategory]["name"] = name;
	jsonData[category][underCategory]["cost"] = cost;

	
	std::ofstream fileS("base.json");
	fileS << jsonData << '\n';
}

int main()
{
	std::cout << R"#(1 insert 2 show)#";
	InsertProduct("home", "kitchen", "krujka", 13);
	
}