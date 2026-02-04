#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 rm[256];
extern uint16 gm[256];
extern uint16 bm[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 256; ++i) {
    if (rm[i] == 0 && gm[i] == 0 && bm[i] == 0) {
        continue;
    }
    rm[i] = (((rm[i]) * ((1L << 16) - 1)) / 255);
    gm[i] = (((gm[i]) * ((1L << 16) - 1)) / 255);
    bm[i] = (((bm[i]) * ((1L << 16) - 1)) / 255);
}
}
