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
if (rlen > (STRLEN)j) {
    for (i = 0; i < (I32)rlen - j; i += 2) {
        tbl[257 + i] = r[j + i];
        if (i + 1 < (I32)(rlen - j)) {
            tbl[257 + i + 1] = r[j + i + 1];
        }
    }
}
}
