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
if (h_expand > 0) {
    for (h = h_expand; h > 0; h--) {
        for (int inner = 1; inner > 0; inner--) {
            *outptr++ = invalue;
        }
    }
}
}
