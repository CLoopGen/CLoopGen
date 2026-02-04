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
for (i = 0; i < elems; i++) {
    cur_len = (nb ? *data & 15 : *data >> 4) + 1;
    counts[cur_len]++;
    max_bits = ((max_bits) > (cur_len) ? (max_bits) : (cur_len));
    lens[i] = cur_len;
    data += nb;
    nb ^= 1;
}

}
