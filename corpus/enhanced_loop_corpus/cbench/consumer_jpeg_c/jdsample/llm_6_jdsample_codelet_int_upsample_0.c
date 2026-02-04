#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

extern JSAMPROW outptr;
extern JSAMPLE invalue;
extern int h;
extern int h_expand;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW local_outptr = outptr;
    JSAMPLE local_value = invalue;
    int counter = h_expand;
    for (h = counter; h > 0; h--) {
        local_outptr[h - 1] = local_value;
    }
    outptr += counter;
}
