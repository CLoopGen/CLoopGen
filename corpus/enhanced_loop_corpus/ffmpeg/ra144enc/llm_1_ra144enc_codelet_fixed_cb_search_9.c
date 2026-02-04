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
    for (i = 0; i < 40; i += 4) {
        vect[i]     = ff_cb1_vects[*cb1_idx][i];
        if (i + 1 < 40) vect[i + 1] = ff_cb1_vects[*cb1_idx][i + 1];
        if (i + 2 < 40) vect[i + 2] = ff_cb1_vects[*cb1_idx][i + 2];
        if (i + 3 < 40) vect[i + 3] = ff_cb1_vects[*cb1_idx][i + 3];
    }
}
