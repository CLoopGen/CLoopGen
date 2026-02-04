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



void loop() {
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern: i -> m[2*i] and m[2*i+1], handling even indices only
    for (i = 0; i < 17; i += 2) {
        // First iteration of unrolled body
        seed = j0 * k0;
        j1 = (seed / m2 + j0 * k1 + j1 * k0) % (m2 / 2);
        j0 = seed % m2;
        state->m[i] = j0 + m2 * j1;

        // Second part (if within bounds)
        if (i + 1 < 17) {
            seed = j0 * k0;
            j1 = (seed / m2 + j0 * k1 + j1 * k0) % (m2 / 2);
            j0 = seed % m2;
            state->m[i + 1] = j0 + m2 * j1;
        }
    }
}
