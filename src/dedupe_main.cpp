#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "dedupe_util.h"


int main(int argc, char *argv[])
{
	std::cout << "Initiating the dedupe operation " << std::endl;
	FILE *input_file = NULL;
	if(argc < 2)
	{
		std::cerr << USAGE.c_str();
		return 1;
	}

	std::cout << "Opening the input file... ";
	input_file = fopen(argv[1],"rb");
	if(!input_file)
	{
		std::cerr << FILE_OPEN_ERR.c_str();
		return 1;
	}

	// File opened successfully 	
}

