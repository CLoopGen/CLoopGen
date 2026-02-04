#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern uint32_t cm;
extern int x;
extern int y;
extern  int w1tab[4];
extern  int prods[4];
extern int at1_r;
extern int at1_g;
extern int at1_b;
extern int at2_r;
extern int at2_g;
extern int at2_b;
extern int akku;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_r[4], temp_g[4], temp_b[4];
    for (y = 0; y < 4; y++) {
        for (x = 0; x < 4; x++) {
            int step = cm & 3;
            int w1 = w1tab[step];
            int idx = x * 4 + y * stride;
            temp_r[x] = block[0 + idx];
            temp_g[x] = block[1 + idx];
            temp_b[x] = block[2 + idx];
            akku += prods[step];
            at1_r += w1 * temp_r[x];
            at1_g += w1 * temp_g[x];
            at1_b += w1 * temp_b[x];
            cm >>= 2;
        }
        // Introduce loop-carried dependency: accumulate final pixel row into at2 only after full row processing
        for (x = 0; x < 4; x++) {
            at2_r += temp_r[x];
            at2_g += temp_g[x];
            at2_b += temp_b[x];
        }
    }
}
