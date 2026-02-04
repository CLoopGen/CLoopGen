#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int8_t ff_cb1_vects[128][40];
extern int *cb1_idx;
extern int i;
extern float vect[40];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access — traverse the array from last to first
    // This changes the memory access pattern from forward to backward
    int i;
    for (i = 39; i >= 0; i--) {
        vect[i] = ff_cb1_vects[*cb1_idx][i];
    }
}
