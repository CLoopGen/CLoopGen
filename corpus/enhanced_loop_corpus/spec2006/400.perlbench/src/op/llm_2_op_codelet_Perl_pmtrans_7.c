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
for (i = 0 , j = 0; i < (I32)tlen; i += 2 , j++) {
    STRLEN idx = i; // consecutive even indices only - strided access on t
    if (j >= (I32)rlen) {
        if (del) {
            if (idx < tlen && tbl[t[idx]] == -1)
                tbl[t[idx]] = -2;
            continue;
        }
        --j;
    }
    if (idx < tlen && tbl[t[idx]] == -1) {
        if (t[idx] < 128 && r[j] >= 128)
            grows = 1;
        tbl[t[idx]] = r[j];
    }
    // Handle odd index if within bounds
    idx = i + 1;
    if (idx < tlen && del) {
        if (tbl[t[idx]] == -1)
            tbl[t[idx]] = -2;
    }
}
}
