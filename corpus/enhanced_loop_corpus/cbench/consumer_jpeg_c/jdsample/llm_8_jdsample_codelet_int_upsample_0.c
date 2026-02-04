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
    int stride = h_expand / 4;
    for (h = stride; h > 0; h--) {
        *outptr++ = invalue;
        *outptr++ = invalue;
        *outptr++ = invalue;
        *outptr++ = invalue;
    }
    // Handle remainder
    for (; h < (h_expand % 4); h++) {
        *outptr++ = invalue;
    }
}
