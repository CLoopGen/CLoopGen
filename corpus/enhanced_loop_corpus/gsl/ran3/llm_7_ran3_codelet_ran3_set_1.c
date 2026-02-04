#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned long buffer[56];
} ran3_state_t;

extern ran3_state_t *state;
extern int i;
extern int i1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i1 = 0; i1 < 4; i1++) {
        long prev_val = state->buffer[1];
        for (i = 1; i < 56; i++) {
            long idx = 1 + (i + 30) % 55;
            long current = state->buffer[i];
            long t = current - state->buffer[idx];
            if (t < 0)
                t += 1000000000;
            state->buffer[i] = t;
            if (i > 1) {
                state->buffer[i - 1] = prev_val;
            }
            prev_val = current;
        }
        state->buffer[55] = prev_val;
    }
}
