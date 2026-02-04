#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int nd;
    unsigned long ra[16384];
} gfsr4_state_t;

gfsr4_state_t *state;
int i;
unsigned long msb;
unsigned long mask;

void init_vars() {
    state = (gfsr4_state_t*)malloc(sizeof(gfsr4_state_t));
    if (!state) {
        exit(1);
    }
    state->nd = 0;
    for (int idx = 0; idx < 16384; ++idx) {
        state->ra[idx] = 0x80000000UL + idx;
    }
    msb = 0x80000000UL;
    mask = 0x7FFFFFFFUL;
}