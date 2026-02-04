#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    unsigned int i;
    long aa[1009];
    long ran_x[100];
} ran_state_t;

ran_state_t *state;
long x[199];
int j;

void init_vars() {
    state = (ran_state_t*)malloc(sizeof(ran_state_t));
    if (!state) exit(1);

    state->i = 0;
    for (int i = 0; i < 1009; i++) {
        state->aa[i] = (long)(i * 37);
    }
    for (int i = 0; i < 100; i++) {
        state->ran_x[i] = 0; // will be overwritten by loop, but initialize anyway
    }
    for (int i = 0; i < 199; i++) {
        x[i] = (long)(i * 1007);
    }

    j = 37; // ensures j-37 starts at 0; loop runs from j=37 to j=99 (63 iterations)
}