#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *bits;
extern int size;
extern  uint8_t *insyms;
extern int i;
extern int counts[17];
extern uint16_t syms[1296];
extern uint8_t bits2[1296];
extern int maxbits;
extern int realsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i++) {
        uint8_t bit_val = bits[i];
        if (!bit_val) continue;
        bits2[realsize] = bit_val;
        syms[realsize] = insyms ? insyms[i] : i;
        realsize++;
        if (bit_val > maxbits) {
            maxbits = bit_val;
        }
        counts[bit_val]++;
    }
}
