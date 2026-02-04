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
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        int step = cm & 3;
        int w1 = w1tab[step];
        int r = block[0 + x * 4 + y * stride];
        int g = block[1 + x * 4 + y * stride];
        int b = block[2 + x * 4 + y * stride];
        akku += prods[step];
        at1_r += w1 * r;
        at1_g += w1 * g;
        at1_b += w1 * b;
        at2_r += r;
        at2_g += g;
        at2_b += b;
        cm >>= 2;
    }
}
}
