#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *par_mapped;
extern  int8_t *par;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using a separate index variable with non-unit stride
    int idx = 2 * b;
    for (int i = b; i >= 0; i--, idx -= 2) {
        par_mapped[idx + 1] = par_mapped[idx] = par[i];
    }
}
