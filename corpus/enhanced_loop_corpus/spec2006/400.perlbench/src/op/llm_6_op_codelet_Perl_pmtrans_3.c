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
    for (j = 0; j < (I32)tlen; j++) {
        I32 index = t[j];
        tbl[index] = -1;
    }
}
