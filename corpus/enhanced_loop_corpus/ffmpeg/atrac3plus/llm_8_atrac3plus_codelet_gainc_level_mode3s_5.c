#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

extern AtracGainInfo *dst;
extern AtracGainInfo *ref;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = dst->num_points;
    for (i = 0; i < limit; i += 2) {
        int idx = i;
        if (idx < dst->num_points) {
            dst->lev_code[idx] = (idx >= ref->num_points) ? 7 : ref->lev_code[idx];
        }
        if (i + 1 < dst->num_points) {
            dst->lev_code[i + 1] = ((i + 1) >= ref->num_points) ? 7 : ref->lev_code[i + 1];
        }
    }
}
