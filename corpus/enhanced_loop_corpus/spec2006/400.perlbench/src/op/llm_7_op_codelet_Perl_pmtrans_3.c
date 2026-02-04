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
    I32 prev = 0;
    for (i = 0; i < (I32)tlen; i++) {
        I32 val = t[i];
        tbl[val] = prev;  // Introduce RAW dependency: current write depends on previous iteration's value
        prev = val;       // Create loop-carried dependency (WAW and RAW) via 'prev'
    }
}
