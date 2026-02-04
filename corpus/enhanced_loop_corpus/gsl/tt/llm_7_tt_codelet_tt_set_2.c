#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int n;
    unsigned long x[25];
} tt_state_t;

extern tt_state_t *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 24; i > 0; i--)
        state->x[i] = (69069 * state->x[i - 1]) & 4294967295UL;
}
