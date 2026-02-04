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
    int temp_counts[17] = {0};
    int temp_max_bits = 0;
    for (i = 0; i < elems; i++) {
        cur_len = (nb ? *data & 15 : *data >> 4) + 1;
        temp_counts[cur_len]++;
        if (cur_len > temp_max_bits) {
            temp_max_bits = cur_len;
        }
        lens[i] = cur_len;
        data += nb;
        nb ^= 1;
    }
    for (int j = 0; j < 17; j++) {
        counts[j] += temp_counts[j];
    }
    max_bits = (max_bits > temp_max_bits) ? max_bits : temp_max_bits;
}
