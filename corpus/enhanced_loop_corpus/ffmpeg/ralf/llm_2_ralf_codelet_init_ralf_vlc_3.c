#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *data;
extern int elems;
extern uint8_t lens[644];
extern int counts[17];
extern int i;
extern int cur_len;
extern int max_bits;
extern int nb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access on lens[] and counts[], with data accessed in reverse stride pattern
    int stride = 2;
    for (i = 0; i < elems; i++) {
        cur_len = (nb ? data[i % 32] & 15 : data[i % 32] >> 4) + 1;
        counts[cur_len * stride]++;  // Strided access in counts array
        max_bits = ((max_bits) > (cur_len) ? (max_bits) : (cur_len));
        lens[i * stride] = cur_len;  // Strided write into lens
        nb ^= 1;
    }
}
