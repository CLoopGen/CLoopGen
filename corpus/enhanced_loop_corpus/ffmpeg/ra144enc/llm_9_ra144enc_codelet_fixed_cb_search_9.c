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
    float scale = 1.5f;
    for (i = 0; i < 80; i++) {
        int idx = i % 40;
        vect[idx] = ff_cb1_vects[*cb1_idx][idx] * scale;
    }
}
