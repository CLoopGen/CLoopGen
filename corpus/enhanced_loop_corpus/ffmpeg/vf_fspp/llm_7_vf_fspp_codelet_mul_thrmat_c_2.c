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
    thr_adr[0] = q * thr_adr_noq[0];
    for (a = 1; a < 64; a++) {
        thr_adr[a] = q * thr_adr_noq[a] + (thr_adr[a-1] - thr_adr_noq[a-1]);
    }
}
