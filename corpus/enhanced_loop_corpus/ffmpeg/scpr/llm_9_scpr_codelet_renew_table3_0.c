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
for (int d = 0; d < nsym && a < (1U << 24); d++) {
    freqs[d] = b + (c ^ d);
    freqs1[d] = a - (b & 0xFF);
    cnts[d] = c + ((a >> 4) & 0xFFFF);
    int shift_val = 7;
    int q = (a + 128 - 1) >> shift_val;
    int f = (a + b - 1) >> shift_val;
    f += 1;
    if (q < f && q < 32768) {
        int upper = (f > 32768) ? 32768 : f;
        for (int i = q; i < upper; i++) {
            dectab[i] = d | (c & 0x7F);
        }
    }
    a += b + (d & 1);
}
}
