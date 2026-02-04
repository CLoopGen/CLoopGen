#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    unsigned int i;
    unsigned long aa[2009];
    unsigned long ran_x[100];
} ran_state_t;

ran_state_t *state;
long x[199];
int j;

void init_vars() {
    state = (ran_state_t*)malloc(sizeof(ran_state_t));
    if (!state) exit(1);

    for (int i = 0; i < 2009; i++) {
        state->aa[i] = 0xdeadbeefUL + i;
    }
    for (int i = 0; i < 100; i++) {
        state->ran_x[i] = 0xcafebabeUL + i;
    }
    state->i = 0;

    for (int i = 0; i < 199; i++) {
        x[i] = 0x12345678L + i;
    }

    j = 0;
}