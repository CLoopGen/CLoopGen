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
    I32 temp_j;
    for (i = 0, j = 0; i < (I32)tlen; i++) {
        temp_j = j;
        if (temp_j >= (I32)rlen) {
            if (del) {
                if (tbl[t[i]] == -1)
                    tbl[t[i]] = -2;
                continue;
            }
        } else {
            if (tbl[t[i]] == -1) {
                if (t[i] < 128 && r[temp_j] >= 128)
                    grows = 1;
                tbl[t[i]] = r[temp_j];
            }
            j++;
        }
    }
}
