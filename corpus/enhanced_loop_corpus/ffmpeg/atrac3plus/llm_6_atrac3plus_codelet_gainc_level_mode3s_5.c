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
    int temp[7];
    for (i = 0; i < dst->num_points; i++) {
        if (i >= ref->num_points) {
            temp[i] = 7;
        } else {
            temp[i] = ref->lev_code[i];
        }
    }
    for (i = 0; i < dst->num_points; i++) {
        dst->lev_code[i] = temp[i];
    }
}
