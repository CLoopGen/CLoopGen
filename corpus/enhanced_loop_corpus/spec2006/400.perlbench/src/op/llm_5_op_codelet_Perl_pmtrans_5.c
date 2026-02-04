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
    for (i = 0; i < (I32)rlen - j; i++) {
        if (r[j + i] == 0) {
            continue;
        }
        tbl[257 + i] = r[j + i];
    }
}
