#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int i;
    unsigned long x[250];
} r250_state_t;

r250_state_t *state;
int i;
unsigned long msb;
unsigned long mask;

void init_vars() {
    state = (r250_state_t *)aligned_alloc(64, sizeof(r250_state_t));
    if (!state) {
        exit(1);
    }
    state->i = 0;
    for (int j = 0; j < 250; j++) {
        state->x[j] = 0xDEADBEEFDEADBEEFULL;
    }
    msb = 0x80000000UL;
    mask = 0xFFFFFFFFUL;
}