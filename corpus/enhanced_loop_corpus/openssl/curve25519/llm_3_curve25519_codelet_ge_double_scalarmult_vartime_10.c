#include <stdio.h>

#include <inttypes.h>

extern signed char aslide[256];
extern signed char bslide[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via pointer arithmetic with reverse traversal
    signed char *aptr = aslide + 255;
    signed char *bptr = bslide + 255;
    for (i = 255; i >= 0; --i, --aptr, --bptr) {
        if (*aptr || *bptr) {
            break;
        }
    }
}
