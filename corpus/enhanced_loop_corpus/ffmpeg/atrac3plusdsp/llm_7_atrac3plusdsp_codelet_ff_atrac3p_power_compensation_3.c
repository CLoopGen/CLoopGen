#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

extern AtracGainInfo *g1;
extern int i;
extern int gcv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_max = 0;
    for (i = 0; i < g1->num_points; i++) {
        int candidate = 6 - g1->lev_code[i];
        if (candidate > local_max) {
            local_max = candidate;
        }
    }
    if (local_max > gcv) {
        gcv = local_max;
    }
}
