#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

extern JSAMPROW outptr;
extern JSAMPLE invalue;
extern int h;
extern int h_expand;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPROW local_outptr = outptr;
    JSAMPLE local_invalue = invalue;
    int local_h = h_expand;
    for (h = local_h; h > 0; h--) {
        *local_outptr++ = local_invalue;
    }
    outptr = local_outptr;
}
