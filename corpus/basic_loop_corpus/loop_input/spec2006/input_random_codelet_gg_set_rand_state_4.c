#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct gg_rand_state {
    unsigned int x[25];
    int k;
};

unsigned int x[25];
struct gg_rand_state *state;
int i;

void init_vars() {
    state = malloc(sizeof(struct gg_rand_state));
    for (i = 0; i < 25; i++) {
        x[i] = i * 17;
        state->x[i] = i * 31;
    }
    state->k = 42;
}