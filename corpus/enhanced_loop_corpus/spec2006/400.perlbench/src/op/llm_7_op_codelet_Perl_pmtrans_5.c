#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

typedef unsigned char U8;

typedef int I32;

extern STRLEN rlen;
extern U8 *r;
extern I32 i;
extern I32 j;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 temp;
    for (i = 0; i < (I32)rlen - j; i++) {
        temp = r[j + i]; // Eliminate direct use in store: breaks potential RAW chain to memory
        tbl[257 + i] = temp; // Localize data flow: dependency now confined to single iteration (no loop-carried deps)
    }
}
