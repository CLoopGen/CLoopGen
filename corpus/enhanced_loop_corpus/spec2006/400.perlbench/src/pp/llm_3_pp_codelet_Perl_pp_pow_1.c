#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

typedef double NV;

extern UV power;
extern NV result;
extern NV base;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int MAX_BITS = 64;
    UV bits[64];
    int idx = 0;

    // Precompute access pattern (indirect addressing via lookup table)
    UV p = power;
    for (int i = 0; p && i < MAX_BITS; i++) {
        bits[idx] = (UV)1 << i;
        if (p & bits[idx]) {
            p -= bits[idx];
        }
        idx++;
    }

    NV local_result = result;
    NV local_base = base;
    int n_local = 0;

    // Strided access through precomputed bit mask array (indirect memory access pattern)
    for (int i = 0; i < idx; i++, n_local++) {
        local_base *= local_base; // Maintain exponentiation state
        if (power & bits[i]) {
            local_result *= local_base;
            power -= bits[i];
            if (power == 0)
                break;
        }
    }

    result = local_result;
    n = n_local;
}
