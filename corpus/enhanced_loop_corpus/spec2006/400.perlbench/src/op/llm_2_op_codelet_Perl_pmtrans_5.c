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
    // Variant 1: Consecutive memory access with reversed direction
    // Instead of forward indexing from j, we traverse backwards in r but store forwards in tbl
    STRLEN n = (STRLEN)rlen - j;
    for (i = 0; i < n; i++) {
        tbl[257 + i] = r[j + n - 1 - i];  // Reverse the input source, consecutive but mirrored access
    }
}
