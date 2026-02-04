#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct FFPsyWindowInfo {
    int window_type[3];
    int window_shape;
    int num_windows;
    int grouping[8];
    float clipping[8];
    int *window_sizes;
} FFPsyWindowInfo;

extern int i;
extern uint8_t grouping;
extern FFPsyWindowInfo wi;
extern int lastgrp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_grouping[8] = {0};
    for (i = 0; i < 8; i++) {
        if (!((grouping >> i) & 1)) {
            lastgrp = i;
        }
        temp_grouping[lastgrp]++;
    }
    // Eliminate loop-carried dependency on wi.grouping by using a local array
    for (i = 0; i < 8; i++) {
        wi.grouping[i] += temp_grouping[i];
    }
}
