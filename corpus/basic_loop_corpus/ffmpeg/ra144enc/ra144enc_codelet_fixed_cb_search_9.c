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
for (i = 0; i < 40; i++)
    vect[i] = ff_cb1_vects[*cb1_idx][i];

}
