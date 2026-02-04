#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AtracGainInfo {
    int num_points;
    int lev_code[7];
    int loc_code[7];
} AtracGainInfo;

extern int b;
extern AtracGainInfo *gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled pattern
    for (int i = 0; i < 4; i += 2) {
        if (b + i < 4) gain[b + i].num_points = 0;
        if (b + i + 1 < 4) gain[b + i + 1].num_points = 0;
    }
}
