#include <stdio.h>

#include <inttypes.h>

extern char *vPtr;
extern char buffer[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse indexing using a temporary pointer
    char *src = buffer + sizeof(float) - 1;
    for (i = 0; i < sizeof(float); i += 1) {
        vPtr[i] = *(src - i);
    }
}
