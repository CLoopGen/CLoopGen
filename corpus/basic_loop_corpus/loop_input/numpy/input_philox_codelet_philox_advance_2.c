#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct r123array4x64 {
    uint64_t v[4];
};

typedef struct r123array4x64 philox4x64_ctr_t;

struct r123array2x64 {
    uint64_t v[2];
};

typedef struct r123array2x64 philox4x64_key_t;

typedef struct s_philox_state {
    philox4x64_ctr_t *ctr;
    philox4x64_key_t *key;
    int buffer_pos;
    uint64_t buffer[4];
    int has_uint32;
    uint32_t uinteger;
} philox_state;

uint64_t *step;
philox_state *state;
int i;
int carry;
uint64_t v_orig;

static philox4x64_ctr_t ctr_data;
static philox4x64_key_t key_data;

void init_vars() {
    step = (uint64_t*)aligned_alloc(32, 4 * sizeof(uint64_t));
    state = (philox_state*)malloc(sizeof(philox_state));

    if (!step || !state) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < 4; j++) {
        step[j] = 0x9E3779B985157855ULL + j;
    }

    state->ctr = &ctr_data;
    state->key = &key_data;
    state->buffer_pos = 0;
    state->has_uint32 = 0;
    state->uinteger = 0;

    for (int j = 0; j < 4; j++) {
        state->ctr->v[j] = 0x123456789ABCDEF0ULL + j;
        state->buffer[j] = 0;
    }

    for (int j = 0; j < 2; j++) {
        state->key->v[j] = 0xFEDCBA9876543210ULL + j;
    }

    carry = 0;
    i = 0;
    v_orig = 0;
}