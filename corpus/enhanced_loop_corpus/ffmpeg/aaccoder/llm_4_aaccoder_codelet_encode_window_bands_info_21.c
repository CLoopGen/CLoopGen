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
extern  int max_sfb;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cb = 1; cb < 15; cb++) {
        float current_cost = path[max_sfb][cb].cost;
        float best_cost = path[max_sfb][idx].cost;
        if (current_cost < best_cost)
            idx = cb;
    }
}
