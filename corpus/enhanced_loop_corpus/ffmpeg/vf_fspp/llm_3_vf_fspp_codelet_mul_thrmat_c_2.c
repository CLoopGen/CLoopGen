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
    // Variant 2: Reverse consecutive memory access
    for (a = 63; a >= 0; a--)
        thr_adr[a] = q * thr_adr_noq[a];
}
