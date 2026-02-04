#include <stdio.h>
#include <inttypes.h>

struct gg_rand_state {
    unsigned int x[25];
    int k;
};

unsigned int x[25];
struct gg_rand_state *state;
int i;

void init_vars() {
    struct gg_rand_state internal_state;
    state = &internal_state;
    for (int j = 0; j < 25; j++) {
        x[j] = j;
        internal_state.x[j] = 0;
    }
    internal_state.k = 0;
}