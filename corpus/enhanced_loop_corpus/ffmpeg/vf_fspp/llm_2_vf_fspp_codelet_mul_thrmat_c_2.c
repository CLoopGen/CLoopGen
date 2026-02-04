#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *thr_adr_noq;
extern int16_t *thr_adr;
extern int q;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (a = 0; a < 64; a += 2)
        thr_adr[a] = q * thr_adr_noq[a];
    // Handle odd indices if necessary, but since step is +2 and limit is fixed at 64,
    // this creates a strided pattern accessing only even indices.
}
