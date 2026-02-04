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
    if (tlen > 0) {
        for (i = 0; i < (I32)tlen; i++) {
            tbl[t[i]] = -1;
        }
    }
}
