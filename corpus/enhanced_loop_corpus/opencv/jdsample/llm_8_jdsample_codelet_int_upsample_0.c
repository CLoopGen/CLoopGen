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
    int step = h_expand / 4;
    for (h = step; h > 0; h--) {
        *outptr++ = invalue;
        *outptr++ = invalue;
        *outptr++ = invalue;
        *outptr++ = invalue;
    }
    // Handle remaining elements if h_expand is not divisible by 4
    for (int r = h_expand % 4; r > 0; r--) {
        *outptr++ = invalue;
    }
}
