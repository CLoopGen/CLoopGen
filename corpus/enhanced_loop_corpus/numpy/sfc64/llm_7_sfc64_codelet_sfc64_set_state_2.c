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
    state->s[0] = state_arr[0];
    state->s[1] = state_arr[1] + state_arr[0];
    state->s[2] = state_arr[2] + state->s[1];
    state->s[3] = state_arr[3] + state->s[2];
}
