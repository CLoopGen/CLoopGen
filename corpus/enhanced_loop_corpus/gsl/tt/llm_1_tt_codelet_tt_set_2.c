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
    for (i = 1; i < 5; i++) {
        for (int k = 1; k < 5; k++)
            state->x[i * 5 + k] = (69069 * state->x[i * 5 + k - 1]) & 4294967295UL;
    }
}
