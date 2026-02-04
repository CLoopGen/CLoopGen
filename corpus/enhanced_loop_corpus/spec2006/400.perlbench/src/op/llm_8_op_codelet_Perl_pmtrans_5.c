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
    I32 limit = (I32)rlen - j;
    for (i = 0; i < limit; i += 2) {
        tbl[257 + i] = r[j + i];
        if (i + 1 < limit)
            tbl[258 + i] = r[j + i + 1];
    }
}
