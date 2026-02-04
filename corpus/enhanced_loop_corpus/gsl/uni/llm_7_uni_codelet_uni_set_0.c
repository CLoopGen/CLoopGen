#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    int i;
    int j;
    unsigned long m[17];
} uni_state_t;

extern  unsigned int m2;
extern unsigned int i;
extern unsigned int seed;
extern unsigned int k0;
extern unsigned int k1;
extern unsigned int _usr_j0;
extern unsigned int _usr_j1;
extern uni_state_t *state;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0
#define j1 _usr_j1



void loop(){
    unsigned long local_m[17];
    unsigned int local_j0 = j0, local_j1 = j1;
    for (i = 0; i < 17; ++i) {
        seed = local_j0 * k0;
        local_j1 = (seed / m2 + local_j0 * k1 + local_j1 * k0) % (m2 / 2);
        local_j0 = seed % m2;
        local_m[i] = local_j0 + m2 * local_j1;
    }
    // Store results back to state after loop to eliminate loop-carried store dependency
    for (i = 0; i < 17; ++i) {
        state->m[i] = local_m[i];
    }
    j0 = local_j0;
    j1 = local_j1;
}
