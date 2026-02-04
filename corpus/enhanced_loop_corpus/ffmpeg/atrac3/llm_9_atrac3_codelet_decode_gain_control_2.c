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
    for (; b < 8; b += 2) {
        gain[b % 4].num_points = 0;
        gain[b % 4].lev_code[0] = b * 2;
        gain[b % 4].loc_code[0] = b * 3 + 1;
    }
}
