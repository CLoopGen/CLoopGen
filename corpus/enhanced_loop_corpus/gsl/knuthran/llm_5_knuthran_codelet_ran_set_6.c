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
    for (j = 0; j < 37; j++) {
        state->ran_x[j + 63] = (x[j] > 1000) ? x[j] : state->ran_x[j + 63];
    }
}
