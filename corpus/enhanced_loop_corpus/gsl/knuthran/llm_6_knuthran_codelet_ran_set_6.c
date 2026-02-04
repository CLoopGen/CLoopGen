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
    unsigned long temp[37];
    for (j = 0; j < 37; j++) {
        temp[j] = x[j];
    }
    for (j = 0; j < 37; j++) {
        state->ran_x[j + 100 - 37] = temp[j];
    }
}
