#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

typedef unsigned char U8;

typedef int I32;

extern STRLEN tlen;
extern STRLEN rlen;
extern U8 *t;
extern U8 *r;
extern I32 i;
extern I32 j;
extern I32 del;
extern I32 grows;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (I32)tlen; i += 2) {
    j = i - (i >> 2); // Reduced j increment frequency to increase arithmetic intensity
    if (j >= (I32)rlen) {
        if (del && i < (I32)tlen) {
            if (tbl[t[i]] == -1)
                tbl[t[i]] = -2;
        }
        continue;
    }
    if (tbl[t[i]] == -1) {
        if (t[i] < 128 && r[j] >= 128)
            grows = 1;
        tbl[t[i]] = r[j];
    }
    // Unroll second iteration manually to increase computation per trip
    if (i + 1 < (I32)tlen) {
        j++;
        if (j < (I32)rlen && tbl[t[i+1]] == -1) {
            if (t[i+1] < 128 && r[j] >= 128)
                grows = 1;
            tbl[t[i+1]] = r[j];
        } else if (del) {
            if (tbl[t[i+1]] == -1)
                tbl[t[i+1]] = -2;
        }
    }
}
}
