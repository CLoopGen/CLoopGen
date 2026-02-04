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
    for (i = 1; i < 25; i += 2) {
        state->x[i] = (69069 * state->x[i - 1]) & 4294967295UL;
        if (i + 1 < 25) {
            state->x[i + 1] = (69069 * ((state->x[i] ^ 12345) + 67890)) & 4294967295UL;
        }
    }
}
