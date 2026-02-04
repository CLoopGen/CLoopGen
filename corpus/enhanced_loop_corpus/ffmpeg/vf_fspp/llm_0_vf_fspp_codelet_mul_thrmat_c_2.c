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
for (i = 0; i < 1; i++)
    for (a = 0; a < 64; a++)
        thr_adr[a] = q * thr_adr_noq[a];
}
