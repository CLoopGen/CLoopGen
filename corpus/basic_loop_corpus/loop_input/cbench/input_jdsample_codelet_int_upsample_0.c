#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;

JSAMPROW outptr;
JSAMPLE invalue;
int h;
int h_expand;
JSAMPLE *outptr_buffer;

void init_vars() {
    h_expand = 131072;
    invalue = 42;
    outptr_buffer = (JSAMPLE *)calloc(h_expand, sizeof(JSAMPLE));
    outptr = outptr_buffer;
}