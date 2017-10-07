#include "dedupe_util.h"
#include <iostream>

#define SEGMENT_SIZE 10 // We will be using segment size 10 bytes 


int DedupeOperation::process_input_file()
{
	if(!this->input_file)
	{
		std::cerr << "System Error: Input File NULL \n";
		return 1;		
	}

	unsigned char *read_buffer = new unsigned char[SEGMENT_SIZE];
	if(!read_buffer)
	{
		std::cerr << MEMALLOC_FAIL.c_str();
		return 1;
	}

	// start reading the file in binary mode 
	size_t bytes_read;
	unsigned int sequence_index = 0;
	static unsigned int global_id = 0;
	SegmentObject *segment_object = NULL;

	while(!feof(this->input_file) || !ferror(this->input_file))
	{
		bytes_read = fread(read_buffer,SEGMENT_SIZE, 1, this->input_file);
		segment_object = new SegmentObject;
		if(!segment_object)
		{
			std::cerr << MEMALLOC_FAIL.c_str();
			return 1;
		}	
		
		segment_object->contents = new unsigned char[bytes_read];
		if(!segment_object->contents)
		{
			std::cerr << MEMALLOC_FAIL.c_str();
			return 1;
		}

		memcpy(segment_object->contents, read_buffer, bytes_read);
		segment_object->content_length = bytes_read;	
		segment_object->sequence_index = sequence_index++;

	}

	

}
