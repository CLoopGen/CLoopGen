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
for (i = 0; i < elems && i < 322; i++) {
    uint8_t val = *data;
    cur_len = (nb ^ (val & 1)) ? ((val >> 3) & 15) + 1 : ((val >> 2) & 15) + 1;
    counts[cur_len] += 2;
    max_bits = (max_bits < cur_len) ? cur_len : max_bits;
    lens[i] = cur_len;
    if (i + elems / 2 < 644) {
        lens[i + elems / 2] = cur_len;
    }
    data += (nb + 1);
    nb ^= 1;
}
}
