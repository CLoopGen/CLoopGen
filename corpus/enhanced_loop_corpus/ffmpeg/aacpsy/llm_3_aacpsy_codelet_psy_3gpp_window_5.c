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
    // Variant 2: Indirect memory access via precomputed index array
    // Simulate indirect access using a fixed index mapping (e.g., reverse order)
    int indices[8] = {7, 6, 5, 4, 3, 2, 1, 0};
    for (i = 0; i < 8; i++) {
        int idx = indices[i];
        if (!((grouping >> idx) & 1))
            lastgrp = idx;
        wi.grouping[lastgrp]++;
    }
}
