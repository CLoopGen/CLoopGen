#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int i;
    int j;
    unsigned long m[17];
} uni32_state_t;

extern  unsigned long m2;
extern long seed;
extern long k0;
extern long k1;
extern long _usr_j0;
extern long _usr_j1;
extern int i;
extern uni32_state_t *state;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0
#define j1 _usr_j1



void loop(){
    for (i = 0; i < 8; i++) {
        seed = ((j0 * k0) >> 1) + ((j0 * k1) & (m2 - 1));
        j1 = (seed / m2 + (j0 * k1) + (j1 * k0)) % (m2 / 2);
        j0 = (seed + j1) % m2;
        state->m[i] = j0 * m2 + j1;
        state->m[16 - i] = (j0 + 1) * m2 + (j1 + 1);
    }
}
