#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    unsigned long mt[624];
    int mti;
} mt_state_t;

unsigned long s = 5489UL;
mt_state_t *state = NULL;
int i = 0;

static mt_state_t internal_state;

void init_vars() {
    state = &internal_state;
    s = 5489UL;
    i = 0;
    state->mti = 0;
}