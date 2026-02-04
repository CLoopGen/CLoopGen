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
    int limit = (ref->num_points < dst->num_points) ? ref->num_points : dst->num_points;
    for (i = 0; i < limit; i++)
        dst->lev_code[i] = ref->lev_code[i];
    for (; i < dst->num_points; i++)
        dst->lev_code[i] = 7;
}
