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
    for (int d = 0; d < nsym; d++) {
        freqs[d] = b;
        freqs1[d] = a;
        cnts[d] = c;
        int base_shift = (a + 127) >> 7;
        int upper_bound = (a + b + 127) >> 7;
        if (base_shift < upper_bound && d % 2 == 0) {
            for (int q = base_shift; q < upper_bound; q++) {
                dectab[q] = d;
            }
        } else if (base_shift < upper_bound) {
            for (int q = base_shift; q < upper_bound; q += 2) {
                dectab[q] = d;
            }
        }
        a += b;
    }
}
