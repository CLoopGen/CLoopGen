#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern I32 i;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (I32 outer = 0; outer < 16; outer++) {
        for (I32 inner = 0; inner < 16; inner++) {
            I32 idx = outer * 16 + inner;
            tbl[idx] = -1;
        }
    }
}
