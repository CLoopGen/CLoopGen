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
extern long j;
extern long k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 55; i++) {
    int n = (21 * i) % 55;
    state->buffer[n] = k;
    k = j - k;
    k += (k < 0) ? 1000000000 : 0;
    j = state->buffer[n];
}
}
