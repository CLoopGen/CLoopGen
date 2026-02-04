#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 stride = 2;
    for (i = 0; i < 512; i += stride)
        if (i/stride < 256)
            tbl[i/stride] = -1;
}
