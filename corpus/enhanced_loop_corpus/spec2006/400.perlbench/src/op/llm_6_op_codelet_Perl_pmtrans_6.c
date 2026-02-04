#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 j;
    for (j = 0; j < 256; j += 2) {
        tbl[j] = -1;
        if (j + 1 < 256) {
            tbl[j + 1] = -1;
        }
    }
}
