#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t idct_simple_mmx_perm[64];
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp[64];
    for (i = 0; i < 64; i++) {
        temp[i] = src[i] + 1;  // Introduce temporary computation with anti-dependence (WAR)
        dst[idct_simple_mmx_perm[i]] = temp[i];  // Write to dst using permuted index
    }
}
