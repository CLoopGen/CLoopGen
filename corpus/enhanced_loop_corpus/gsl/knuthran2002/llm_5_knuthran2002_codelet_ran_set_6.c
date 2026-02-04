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
    for (; j < 100; j++) {
        long val = x[j];
        if ((j - 37) >= 0 && (j - 37) < 100) {
            state->ran_x[j - 37] = val;
        }
    }
}
