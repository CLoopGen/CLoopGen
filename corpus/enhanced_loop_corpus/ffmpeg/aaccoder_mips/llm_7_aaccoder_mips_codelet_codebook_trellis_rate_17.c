#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct TrellisBandCodingPath {
    int prev_idx;
    float cost;
    int run;
} TrellisBandCodingPath;

extern TrellisBandCodingPath path[120][15];
extern int cb;
extern  int run_bits;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cb = 14; cb >= 0; cb--) {
        path[0][cb].cost = run_bits + 4;
        path[0][cb].prev_idx = -1;
        path[0][cb].run = 0;
    }
}
