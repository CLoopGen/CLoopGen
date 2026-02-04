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
for (i1 = 0; i1 < 2; i1++) {
    for (i = 1; i < 56; i += 2) {
        long t1 = state->buffer[i] - state->buffer[1 + (i + 30) % 55];
        long t2 = (i + 1 < 56) ? state->buffer[i + 1] - state->buffer[1 + ((i + 1) + 30) % 55] : t1;
        if (t1 < 0) t1 += 1000000000;
        if (t2 < 0) t2 += 1000000000;
        state->buffer[i] = t1;
        if (i + 1 < 56) state->buffer[i + 1] = t2;
    }
}
}
