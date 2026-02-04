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
int i;
for (a = 0; a < 128; a += 2) {
    thr_adr[a] = q * thr_adr_noq[a];
    if (a + 1 < 64) {
        thr_adr[a + 1] = q * thr_adr_noq[a + 1];
    }
}
}
