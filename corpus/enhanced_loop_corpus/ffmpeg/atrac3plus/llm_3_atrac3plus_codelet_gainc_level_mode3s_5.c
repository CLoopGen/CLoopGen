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
    // Reverse traversal with consecutive access from the end
    for (i = dst->num_points - 1; i >= 0; i--) {
        dst->lev_code[i] = (i >= ref->num_points) ? 7 : ref->lev_code[i];
    }
} 