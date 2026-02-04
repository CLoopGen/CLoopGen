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
for (int outer = 0; outer < 2; outer++)
    for (int inner = 0; inner < 2; inner++)
        gain[outer * 2 + inner].num_points = 0;
}
