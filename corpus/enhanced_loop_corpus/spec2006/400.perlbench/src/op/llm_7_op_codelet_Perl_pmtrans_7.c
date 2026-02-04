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
    I32 prev_i = -1;
    for (i = 0, j = 0; i < (I32)tlen; i++, j++) {
        if (prev_i != -1 && tbl[t[prev_i]] == -2) {
            tbl[t[i]] = tbl[t[prev_i]] + 1;
        }
        if (j >= (I32)rlen) {
            if (del) {
                if (tbl[t[i]] == -1)
                    tbl[t[i]] = -2;
                continue;
            }
            --j;
        }
        if (tbl[t[i]] == -1) {
            if (t[i] < 128 && r[j] >= 128)
                grows = 1;
            tbl[t[i]] = r[j];
        }
        prev_i = i;
    }
}
