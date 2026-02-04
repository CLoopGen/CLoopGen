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
    uint64_t temp[4];
    for (i = 0; i < 4; i++) {
        temp[i] = state_arr[i];
    }
    for (i = 0; i < 4; i++) {
        state->s[i] = temp[i];
    }
}
