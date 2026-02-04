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
    uint64_t temp[4];
    carry = 0;
    for (i = 0; i < 4; i++) {
        temp[i] = state->ctr->v[i];
        v_orig = temp[i];
        temp[i] += step[i];
        if (temp[i] < v_orig) {
            carry = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (carry == 1) {
            temp[i]++;
            carry = temp[i] == 0 ? 1 : 0;
        }
        state->ctr->v[i] = temp[i];
    }
}
