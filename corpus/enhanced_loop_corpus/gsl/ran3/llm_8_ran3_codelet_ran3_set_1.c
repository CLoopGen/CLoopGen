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
for (i1 = 0; i1 < 8; i1++) {
    for (i = 1; i < 56; i++) {
        long t = state->buffer[i] - state->buffer[1 + (i + 30) % 55];
        t = (t < 0) ? t + 1000000000 : t;
        t = (t >= 1000000000) ? t - 1000000000 : t;
        state->buffer[i] = t;
    }
}
}
