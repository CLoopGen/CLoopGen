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

extern uint64_t *step;
extern philox_state *state;
extern int i;
extern int carry;
extern uint64_t v_orig;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        if (carry == 1) {
            state->ctr->v[i]++;
            carry = state->ctr->v[i] == 0 ? 1 : 0;
        }
        v_orig = state->ctr->v[i];
        state->ctr->v[i] += step[i];
        if (state->ctr->v[i] < v_orig && carry == 0) {
            carry = 1;
        }
    }
    for (i = 2; i < 4; i++) {
        if (carry == 1) {
            state->ctr->v[i]++;
            carry = state->ctr->v[i] == 0 ? 1 : 0;
        }
        v_orig = state->ctr->v[i];
        state->ctr->v[i] += step[i];
        if (state->ctr->v[i] < v_orig && carry == 0) {
            carry = 1;
        }
    }
}
