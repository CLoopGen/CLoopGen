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
int i_start = 0;
int step = 2;
for (i = i_start; i < size; i += step) {
    if (bits[i]) {
        bits2[realsize] = bits[i];
        syms[realsize] = insyms ? insyms[i] : i;
        realsize++;
        if (bits[i] > maxbits) {
            maxbits = bits[i];
        }
        counts[bits[i]]++;
    }
    // Unroll: process next element if within bounds
    int i_next = i + 1;
    if (i_next < size && bits[i_next]) {
        bits2[realsize] = bits[i_next];
        syms[realsize] = insyms ? insyms[i_next] : i_next;
        realsize++;
        if (bits[i_next] > maxbits) {
            maxbits = bits[i_next];
        }
        counts[bits[i_next]]++;
    }
}
}
