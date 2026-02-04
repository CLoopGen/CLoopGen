#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

typedef unsigned char U8;

typedef int I32;

extern STRLEN rlen;
extern U8 *r;
extern I32 i;
extern I32 j;
extern I32 del;
extern I32 grows;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , j = 0; i < 256; i++) {
    I32 idx = (i * 3) % 256; // Strided access with wrap-around to create non-consecutive index
    if (!tbl[idx]) {
        if (j >= (I32)rlen) {
            if (del)
                tbl[idx] = -2;
            else if (rlen)
                tbl[idx] = r[j - 1];
            else
                tbl[idx] = (short)idx;
        } else {
            if (idx < 128 && r[j] >= 128)
                grows = 1;
            tbl[idx] = r[j++];
        }
    }
}
}
