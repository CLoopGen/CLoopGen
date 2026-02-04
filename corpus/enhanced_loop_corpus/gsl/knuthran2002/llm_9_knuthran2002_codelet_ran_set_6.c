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
    for (; j < 50; j++) {
        long temp = x[j] + 1;
        state->ran_x[j - 37] = temp;
        state->ran_x[63 - j] = temp * temp;
    }
}
