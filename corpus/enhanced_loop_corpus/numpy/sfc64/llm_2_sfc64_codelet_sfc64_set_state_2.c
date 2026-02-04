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
    // Variant 1: Strided memory access with reverse order and stride of 1 (effectively still sequential but traversed backwards)
    for (i = 3; i >= 0; i--) {
        state->s[i] = state_arr[i];
    }
}
