#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int i;
    int j;
    unsigned long m[17];
} uni32_state_t;

unsigned long m2 = 4294967296UL; // 2^32
long seed = 123456789L;
long k0 = 987654321L;
long k1 = 101010101L;
long _usr_j0 = 1122334455L;
long _usr_j1 = 5566778899L;
int i;

uni32_state_t *state;

void init_vars() {
    state = (uni32_state_t*)aligned_alloc(32, sizeof(uni32_state_t));
    if (!state) {
        exit(1);
    }
    state->i = 0;
    state->j = 0;
    for (int idx = 0; idx < 17; idx++) {
        state->m[idx] = 0UL;
    }
}