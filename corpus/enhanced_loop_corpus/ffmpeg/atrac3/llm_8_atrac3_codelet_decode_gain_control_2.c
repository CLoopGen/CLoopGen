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
    for (; b < 4; b++) {
        gain[b].num_points = 0;
        for (int i = 0; i < 3; i++) {
            gain[b].lev_code[i] = i * b + 1;
            gain[b].loc_code[i] = (i + 1) * (b + 2);
        }
    }
}
