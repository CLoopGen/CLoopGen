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
    // Variant 2: Strided memory access on input array r
    // Access every 2nd element of r starting from j, saturating to valid bounds
    STRLEN effective_len = ((rlen - j) + 1) / 2;  // Approximate number of elements under stride-2
    for (i = 0; i < (I32)effective_len; i++) {
        tbl[257 + i] = r[j + 2 * i];  // Strided access: j, j+2, j+4, ...
    }
}
