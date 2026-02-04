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
        long temp_buffer[55];
        for (i = 1; i < 56; i++) {
            long t = state->buffer[i] - state->buffer[1 + (i + 30) % 55];
            if (t < 0)
                t += 1000000000;
            temp_buffer[i - 1] = t;
        }
        for (i = 1; i < 56; i++) {
            state->buffer[i] = temp_buffer[i - 1];
        }
    }
}
