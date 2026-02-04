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
    float temp1[40];
    float temp2[40];
    for (i = 0; i < 40; i++) {
        temp1[i] = ff_cb1_vects[cb1_idx][i];
        temp2[i] = ff_cb2_vects[cb2_idx][i];
    }
    for (i = 0; i < 40; i++) {
        cb1[i] = temp1[i];
        cb2[i] = temp2[i];
    }
}
