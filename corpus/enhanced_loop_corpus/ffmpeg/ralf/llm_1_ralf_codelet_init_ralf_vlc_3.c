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
if (elems > 0) {
    for (i = 0; i < elems; i += 2) {
        // Unroll the loop to process two iterations per loop cycle
        int remaining = elems - i;

        // First sub-iteration
        cur_len = (nb ? *data & 15 : *data >> 4) + 1;
        counts[cur_len]++;
        max_bits = ((max_bits) > (cur_len) ? (max_bits) : (cur_len));
        lens[i] = cur_len;
        data += nb;
        nb ^= 1;

        // Second sub-iteration, if applicable
        if (remaining > 1) {
            cur_len = (nb ? *data & 15 : *data >> 4) + 1;
            counts[cur_len]++;
            max_bits = ((max_bits) > (cur_len) ? (max_bits) : (cur_len));
            lens[i + 1] = cur_len;
            data += nb;
            nb ^= 1;
        }
    }
}
}
