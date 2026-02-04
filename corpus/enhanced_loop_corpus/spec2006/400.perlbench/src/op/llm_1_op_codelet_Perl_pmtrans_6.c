#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (I32 stride = 0; stride < 256; stride += 4) {
        for (I32 offset = 0; offset < 4 && (stride + offset) < 256; offset++) {
            tbl[stride + offset] = -1;
        }
    }
}
