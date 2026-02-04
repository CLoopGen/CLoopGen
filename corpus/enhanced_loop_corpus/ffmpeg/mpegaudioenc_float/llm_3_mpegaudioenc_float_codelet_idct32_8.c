#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int bitinv32[32];
extern int *out;
extern int *tab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access on 'tab' with indirect indexing via bitinv32, but unrolled by factor 4
    // This increases spatial locality and exposes instruction-level parallelism
    for (i = 0; i < 32; i += 4) {
        out[i]     = tab[bitinv32[i]];
        out[i + 1] = tab[bitinv32[i + 1]];
        out[i + 2] = tab[bitinv32[i + 2]];
        out[i + 3] = tab[bitinv32[i + 3]];
    }
}
