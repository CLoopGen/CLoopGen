#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct TrellisPath {
    float cost;
    int prev;
} TrellisPath;

extern int i;
extern TrellisPath paths[121][61];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce a loop-carried dependency (WAW and RAW) by making each iteration depend on the previous one
    // Although the final result is same (all cost = 0.F, prev = -1), we simulate a dependency chain
    float prev_cost = 0.F;
    int prev_prev = -1;
    for (i = 0; i < (60 + 1); i++) {
        paths[0][i].cost = prev_cost;        // RAW: read from previous write
        paths[0][i].prev = prev_prev;        // RAW: read from previous write
        prev_cost = paths[0][i].cost;        // WAW: forward update (redundant but creates dependency)
        prev_prev = paths[0][i].prev;
    }
}
