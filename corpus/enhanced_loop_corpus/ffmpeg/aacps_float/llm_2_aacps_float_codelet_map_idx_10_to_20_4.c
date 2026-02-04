#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *par_mapped;
extern  int8_t *par;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration and offset adjustment
    int8_t *mapped_base = &par_mapped[2 * b];
    int8_t *par_base = &par[b];
    for (; b >= 0; b--) {
        mapped_base[1] = mapped_base[0] = par_base[0];
        mapped_base -= 2;
        par_base--;
    }
}
