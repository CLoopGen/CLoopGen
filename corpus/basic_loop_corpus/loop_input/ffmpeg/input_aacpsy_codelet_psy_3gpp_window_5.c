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

int i;
uint8_t grouping;
FFPsyWindowInfo wi;
int lastgrp;

void init_vars() {
    // Initialize scalar variables
    i = 0;
    grouping = 0xFF; // All bits set so that condition ((grouping >> i) & 1) is always true
    lastgrp = 0;

    // Initialize struct fields
    wi.window_type[0] = 1;
    wi.window_type[1] = 2;
    wi.window_type[2] = 3;
    wi.window_shape = 1;
    wi.num_windows = 8;
    
    // Initialize grouping array to zero to allow incrementing
    for (int j = 0; j < 8; j++) {
        wi.grouping[j] = 0;
        wi.clipping[j] = 0.0f;
    }

    // Allocate window_sizes to avoid null pointer dereference (though not accessed in loop)
    wi.window_sizes = (int*)calloc(8, sizeof(int));
    if (!wi.window_sizes) {
        exit(1);
    }
}