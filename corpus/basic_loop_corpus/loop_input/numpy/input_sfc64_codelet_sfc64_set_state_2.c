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
    state_arr = (uint64_t*)aligned_alloc(64, 4 * sizeof(uint64_t));
    for (int j = 0; j < 4; j++) {
        state_arr[j] = 0xDEADBEEFDEADBEEFULL ^ (j * 0x12345678);
    }

    state = (sfc64_state*)aligned_alloc(64, sizeof(sfc64_state));
    state->has_uint32 = 0;
    state->uinteger = 0;
    for (int j = 0; j < 4; j++) {
        state->s[j] = 0;
    }

    i = 0;
}