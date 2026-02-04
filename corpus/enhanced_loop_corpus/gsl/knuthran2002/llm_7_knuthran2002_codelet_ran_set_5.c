#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned int i;
    long aa[1009];
    long ran_x[100];
} ran_state_t;

extern ran_state_t *state;
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 37; j++) {
        state->ran_x[j + 63] = x[36 - j];
    }
    for (int j = 0; j < 37 - 1; j++) {
        state->ran_x[j + 63] += state->ran_x[j + 63 + 1];
    }
}
