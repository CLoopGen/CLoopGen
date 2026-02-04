#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned int i;
    unsigned long aa[2009];
    unsigned long ran_x[100];
} ran_state_t;

extern ran_state_t *state;
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 37; j += 3) {
        state->ran_x[j + 100 - 37] = x[j];
        if (j + 1 < 37) state->ran_x[j + 1 + 100 - 37] = x[j + 1];
        if (j + 2 < 37) state->ran_x[j + 2 + 100 - 37] = x[j + 2];
    }
}
