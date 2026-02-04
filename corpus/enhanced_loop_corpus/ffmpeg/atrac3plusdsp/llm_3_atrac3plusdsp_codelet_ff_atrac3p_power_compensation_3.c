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
    int stride = 2;
    int limit = (g1->num_points + stride - 1) / stride;
    for (i = 0; i < limit; i++) {
        int idx = i * stride;
        if (idx < g1->num_points) {
            gcv = (gcv > 6 - g1->lev_code[idx]) ? gcv : 6 - g1->lev_code[idx];
        }
    }
}
