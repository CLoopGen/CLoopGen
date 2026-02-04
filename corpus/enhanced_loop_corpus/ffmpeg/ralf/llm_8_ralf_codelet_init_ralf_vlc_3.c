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
int i_start = 0;
for (i = i_start; i < elems; i += 2) {
    int temp1 = *data >> 4;
    int temp2 = *data & 15;
    cur_len = nb ? temp2 + 1 : temp1 + 1;
    counts[cur_len]++;
    if (cur_len > max_bits) max_bits = cur_len;
    lens[i] = cur_len;
    if (i + 1 < elems) {
        lens[i + 1] = cur_len;
    }
    data += nb ? 1 : 2;
    nb ^= 1;
}
}
