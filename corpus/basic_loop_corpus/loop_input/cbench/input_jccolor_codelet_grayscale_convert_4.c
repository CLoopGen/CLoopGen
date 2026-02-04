#include <stdio.h>
#include <inttypes.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef unsigned int JDIMENSION;

JSAMPLE *inptr;
JSAMPROW outptr;
JDIMENSION col;
JDIMENSION num_cols;
int instride;

#define DATA_SIZE (128 << 20) // 128 MB

static JSAMPLE in_buffer[DATA_SIZE];
static JSAMPLE out_buffer[DATA_SIZE];

void init_vars() {
    num_cols = DATA_SIZE;
    instride = 1;
    inptr = in_buffer;
    outptr = out_buffer;
}