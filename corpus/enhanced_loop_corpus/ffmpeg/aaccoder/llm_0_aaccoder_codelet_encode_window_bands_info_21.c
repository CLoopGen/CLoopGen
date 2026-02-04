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
    for (int outer = 0; outer < 1; outer++)
        for (cb = 1; cb < 15; cb++)
            if (path[max_sfb][cb].cost < path[max_sfb][idx].cost)
                idx = cb;
}
