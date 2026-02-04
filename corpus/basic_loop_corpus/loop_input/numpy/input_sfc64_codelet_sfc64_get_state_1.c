#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct s_sfc64_state {
    uint64_t s[4];
    int has_uint32;
    uint32_t uinteger;
} sfc64_state;

sfc64_state *state;
uint64_t *state_arr;
int i;

void init_vars() {
    state = (sfc64_state *)malloc(sizeof(sfc64_state));
    if (!state) {
        exit(1);
    }
    state_arr = (uint64_t *)malloc(4 * sizeof(uint64_t));
    if (!state_arr) {
        exit(1);
    }
    for (int j = 0; j < 4; j++) {
        state->s[j] = 0xdeadbeefdeadbeefULL ^ (j + 1);
    }
    i = 0;
}