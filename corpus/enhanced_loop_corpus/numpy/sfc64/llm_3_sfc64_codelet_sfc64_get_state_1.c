#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct s_sfc64_state {
    uint64_t s[4];
    int has_uint32;
    uint32_t uinteger;
} sfc64_state;

extern sfc64_state *state;
extern uint64_t *state_arr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2, unrolled pattern to ensure all elements are covered)
    for (i = 0; i < 4; i += 2) {
        state_arr[i] = state->s[i];
        if (i + 1 < 4) {
            state_arr[i + 1] = state->s[i + 1];
        }
    }
}
