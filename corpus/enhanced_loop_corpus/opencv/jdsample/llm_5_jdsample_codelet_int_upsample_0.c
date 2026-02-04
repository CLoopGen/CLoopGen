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
    for (h = h_expand; h > 0; h--) {
        *outptr++ = invalue;
        if (h == h_expand / 2) {
            *outptr++ = invalue + 1;
            h--;
        }
    }
}
