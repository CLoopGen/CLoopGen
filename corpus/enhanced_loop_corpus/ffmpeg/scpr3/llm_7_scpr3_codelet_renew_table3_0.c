#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t nsym;
extern uint16_t *freqs;
extern uint16_t *freqs1;
extern uint16_t *cnts;
extern uint8_t *dectab;
extern uint32_t a;
extern uint32_t b;
extern uint32_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint32_t local_a = a;
for (int d = 0; d < nsym; d++) {
    freqs[d] = b;
    freqs1[d] = local_a;
    cnts[d] = c;
    int threshold = (local_a + b - 1 >> 7) + 1;
    for (int q = (local_a + 128 - 1) >> 7; q < threshold; q++)
        dectab[q] = d;
    local_a += b;
}
a = local_a;
}
