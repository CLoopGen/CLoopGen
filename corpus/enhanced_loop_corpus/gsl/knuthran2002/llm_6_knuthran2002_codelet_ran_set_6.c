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
    long temp[100];
    for (int k = 0; k < 63; k++)
        temp[k] = x[k + 37];
    for (; j < 100; j++)
        state->ran_x[j - 37] = temp[j - 37] + x[j];
}
