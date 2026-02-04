#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i += 2) {
        tbl[i] = -1;
        if (i + 1 < 256) tbl[i + 1] = -1;
    }
}
