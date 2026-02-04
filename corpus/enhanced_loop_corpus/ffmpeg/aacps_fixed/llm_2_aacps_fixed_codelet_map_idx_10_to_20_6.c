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
    int8_t *mapped_ptr = &par_mapped[2 * b];
    const int8_t *par_ptr = &par[b];
    for (; b >= 0; b--) {
        mapped_ptr[-1] = mapped_ptr[0] = *par_ptr--;
        mapped_ptr -= 2;
    }
}
