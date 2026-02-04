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
    int stride = 4;
    int remaining = h_expand;
    for (h = remaining / stride; h > 0; h--) {
        *outptr++ = invalue;
        *outptr++ = invalue;
        *outptr++ = invalue;
        *outptr++ = invalue;
    }
    for (int r = remaining % stride; r > 0; r--) {
        *outptr++ = invalue;
    }
}
