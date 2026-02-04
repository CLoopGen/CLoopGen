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
for (int outer = h_expand > 0 ? 1 : 0; outer > 0; outer--) {
    for (h = h_expand; h > 0; h--) {
        *outptr++ = invalue;
    }
}
}
