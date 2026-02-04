#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int n;
    unsigned long x[25];
} tt_state_t;

extern tt_state_t *state;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < 25; i++) {
        unsigned long temp1 = state->x[i - 1] ^ 0xCAFEBABE;
        unsigned long temp2 = (69069 * temp1) + 123456789;
        state->x[i] = temp2 & 4294967295UL;
        state->x[i] ^= (temp2 >> 32);
    }
}
