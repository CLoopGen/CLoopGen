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
for (a = 0; a < 8; a++) {
    int base = a * 8;
    for (int b = 0; b < 8; b++)
        thr_adr[base + b] = q * thr_adr_noq[base + b];
}
}
