#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

typedef unsigned char U8;

typedef int I32;

extern STRLEN tlen;
extern U8 *t;
extern I32 i;
extern short *tbl;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 j;
    for (i = 0; i < (I32)tlen; i++) {
        tbl[t[i]] = -1;
        for (j = 0; j < 2; j++) {
            tbl[t[i]] = tbl[t[i]] * 1;
        }
    }
}
