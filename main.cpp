/**
*	@file main.cpp
*	@author Tyler
*	@date 11/10/2016
*	@brief builds the script to set port descriptions to cdp nei
*/

#include <iostream>
#include <string>
#include <fstream>


int main(int argc, char *argv[])
{
  std::string outputFile;
	int numberType, minX, maxX, minY, maxY, minZ, maxZ;
	std::cout << "Please enter the output file name. ex. file.txt";
	std::cout << "\nFile name: ";
	std::cin >> outputFile;
	std::ofstream fin(outputFile);
  		if(fin.fail())
    		{
        		std::cout << "ERROR. Could not locate the file.\n\n";
        		exit(1);
    		}
	std::cout << "what type of interfaces to do you want to list?\n";
	std::cout << "1) x/y \n2) x/y/z \n";
	std::cout << "choice: ";
	std::cin >> numberType;
	if(numberType == 1)
	{
		std::cout << "Please choose a min and max X, seperated by spaces: ";
		std::cin >> minX >> maxX;
		std::cout << "Please choose a min and max Y, seperated by spaces: ";
		std::cin >> minY >> maxY;
		fin << "conf t\n";
		for(int i = minX ; i <= maxX ; i++)
		{
			for(int j = minY ; j <= maxY ; j++)
			{
				fin << "int gi " << i << "/" << j << "\n";
				fin << "des HOSTNAME\nexit\n";
			}
		}
	}
	else
	{
		std::cout << "Please choose a min and max X, seperated by spaces: ";
		std::cin >> minX >> maxX;
		std::cout << "Please choose a min and max Y, seperated by spaces: ";
		std::cin >> minY >> maxY;
		std::cout << "Please choose a min and max Z, seperated by spaces: ";
		std::cin >> minZ >> maxZ;
		fin << "conf t\n";
		for(int i = minX ; i <= maxX ; i++)
		{
			for(int j = minY ; j <= maxY ; j++)
			{
				for(int k = minZ ; k <= maxZ ; k++)
				{
					fin << "int gi " << i << "/" << j << "/" << k << "\n";
					fin << "des HOSTNAME\nexit\n";
				}

			}
		}
	}
	fin << "end\nwr";

  	return 0;
}
