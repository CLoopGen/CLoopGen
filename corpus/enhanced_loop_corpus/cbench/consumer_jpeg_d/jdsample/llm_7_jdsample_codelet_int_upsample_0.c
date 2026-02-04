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
    int local_h = h_expand;
    for (int i = 0; i < local_h; i++) {
        local_outptr[i] = local_value;
    }
    outptr += local_h;
}
