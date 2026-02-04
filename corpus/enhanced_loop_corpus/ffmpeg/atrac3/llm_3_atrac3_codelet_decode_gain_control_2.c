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
    // Variant 2: Indirect memory access using an index array to simulate non-sequential access
    int indices[4];
    for (int i = 0; i < 4; ++i) {
        indices[i] = b + i;
    }
    for (int i = 0; i < 4; ++i) {
        gain[indices[i]].num_points = 0;
    }
}
