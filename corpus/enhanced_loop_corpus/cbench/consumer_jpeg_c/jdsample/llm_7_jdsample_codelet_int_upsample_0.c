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
    JSAMPROW temp[256];
    int i;
    for (i = 0; i < h_expand && i < 256; i++) {
        temp[i] = outptr + i;
        *(temp[i]) = invalue;
    }
    if (h_expand <= 256) {
        outptr += h_expand;
    } else {
        for (; i < h_expand; i++) {
            *outptr++ = invalue;
        }
    }
}
