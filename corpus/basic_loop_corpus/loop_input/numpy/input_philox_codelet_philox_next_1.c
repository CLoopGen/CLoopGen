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

philox4x64_ctr_t ct = {{0x1111111111111111, 0x2222222222222222, 0x3333333333333333, 0x4444444444444444}};
philox4x64_key_t key = {{0x5555555555555555, 0x6666666666666666}};
philox4x64_ctr_t ctr = {{0x7777777777777777, 0x8888888888888888, 0x9999999999999999, 0xaaaaaaaaaaaaaaaa}};

philox_state *state;

int i;

void init_vars() {
    state = (philox_state*)malloc(sizeof(philox_state));
    if (!state) exit(1);
    state->ctr = &ctr;
    state->key = &key;
    state->buffer_pos = 0;
    state->has_uint32 = 0;
    state->uinteger = 0;
}