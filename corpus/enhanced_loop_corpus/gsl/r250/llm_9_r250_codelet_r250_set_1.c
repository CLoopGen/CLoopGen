#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int i;
    unsigned long x[250];
} r250_state_t;

extern r250_state_t *state;
extern int i;
extern unsigned long msb;
extern unsigned long mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        int base_k = 14 * i + 3;
        unsigned long temp_mask = mask;
        unsigned long temp_msb = msb;
        state->x[base_k] &= temp_mask;
        state->x[base_k] |= temp_msb;
        temp_mask >>= 1;
        temp_msb >>= 1;
        state->x[base_k + 7] &= temp_mask;
        state->x[base_k + 7] |= temp_msb;
        mask >>= 2;
        msb >>= 2;
    }
}
