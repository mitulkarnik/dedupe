#ifndef 
#define _DEDUPE_UTIL_H_

#include <cstring>
#include <string>

static string USAGE = "Usage: ./dedupe_main <input_file> \n";
static string FILE_OPEN_ERR  = "Error opening the input file \n";
static string MEMALLOC_FAIL = "System Error: Cannot allocate memory for specified operation \n";

typedef struct SegmentObject SegmentObject;


class DedupeOPeration
{
	public:
		/**
		 *@brief This will read the data in fixed segment length 
		 *       and will populate the Segment Object structure
		 *       post that will, pass the same for identity processing
		 *
		 **/
		int process_input_file();
		int generate_segment_identity(struct SegmentObject *);

	private:
		FILE *input_file;

};

struct SegmentObject
{
	unsigned char *contents;
	size_t content_length;
	unsigned char *fingerprint;
};


struct MetaDetaStruct
{
	// path object id 
};

#endif
