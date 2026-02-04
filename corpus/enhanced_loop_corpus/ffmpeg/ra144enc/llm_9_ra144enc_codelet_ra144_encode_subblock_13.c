#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const int8_t ff_cb1_vects[128][40];
extern const int8_t ff_cb2_vects[128][40];
extern float cb1[40];
extern float cb2[40];
extern int cb1_idx;
extern int cb2_idx;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified access and increased trip count via unrolling and stride
    for (i = 0; i < 80; i += 2) {
        int idx = i / 2;
        cb1[idx] = (float)ff_cb1_vects[cb1_idx][idx];
        cb2[idx] = (float)ff_cb2_vects[cb2_idx][idx];
    }
}
