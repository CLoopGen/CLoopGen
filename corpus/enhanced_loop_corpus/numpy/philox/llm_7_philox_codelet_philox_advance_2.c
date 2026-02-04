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



void loop() {
    uint64_t prev_v;
    carry = 0;
    for (i = 0; i < 4; i++) {
        prev_v = state->ctr->v[i];
        state->ctr->v[i] += step[i];
        if (state->ctr->v[i] < prev_v) {
            carry = 1;
        }
        if (carry == 1) {
            uint64_t incremented = prev_v + 1;
            if (incremented == 0) {
                carry = 1;
            } else {
                carry = 0;
            }
            state->ctr->v[i] = incremented + step[i] - (prev_v != 0 ? 0 : 1);
        }
    }
}
