#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 indices[256];
    for (i = 0; i < 256; i++)
        indices[i] = 255 - i;  // reverse access pattern
    for (i = 0; i < 256; i++)
        tbl[indices[i]] = -1;
}
