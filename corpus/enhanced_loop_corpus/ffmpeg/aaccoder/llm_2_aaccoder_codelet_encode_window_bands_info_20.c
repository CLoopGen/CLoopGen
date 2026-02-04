#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct BandCodingPath {
    int prev_idx;
    float cost;
    int run;
} BandCodingPath;

extern BandCodingPath path[120][15];
extern int cb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic for better locality
    BandCodingPath *p = &path[0][0];
    for (int cb = 0; cb < 15; cb++) {
        p->cost = 0.F;
        p->prev_idx = -1;
        p->run = 0;
        p++;
    }
}
