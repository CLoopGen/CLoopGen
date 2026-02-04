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
    if (bits[i]) {
        bits2[realsize] = bits[i];
        syms[realsize] = insyms ? insyms[i] : i;
        realsize++;
        maxbits = ((maxbits) > (bits[i]) ? (maxbits) : (bits[i]));
        counts[bits[i]]++;
    }
}

}
