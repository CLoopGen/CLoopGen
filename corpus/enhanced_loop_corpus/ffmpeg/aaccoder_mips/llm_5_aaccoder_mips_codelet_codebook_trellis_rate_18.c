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
extern  int max_sfb;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    idx = 1;
    for (cb = 2; cb < 15; cb++) {
        if (!(path[max_sfb][cb].cost >= path[max_sfb][idx].cost)) {
            idx = cb;
        }
    }
}
