#include <stdio.h>

#include <inttypes.h>

typedef unsigned short uint16;

extern uint16 rm[256];
extern uint16 gm[256];
extern uint16 bm[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; ++i) {
    for (int j = 0; j < 16; ++j) {
        int idx = i * 16 + j;
        rm[idx] = (((rm[idx]) * ((1L << 16) - 1)) / 255);
        gm[idx] = (((gm[idx]) * ((1L << 16) - 1)) / 255);
        bm[idx] = (((bm[idx]) * ((1L << 16) - 1)) / 255);
    }
}
}
