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
    uint8_t *local_data = data;
    int local_nb = nb;
    for (i = 0; i < elems; i++) {
        int idx = (i % 2 == 0) ? (local_nb ? *(local_data + (i/2)) & 15 : *(local_data + (i/2)) >> 4) : cur_len;
        cur_len = (i % 2 == 0) ? idx + 1 : cur_len;
        counts[cur_len]++;
        max_bits = (max_bits < cur_len) ? cur_len : max_bits;
        lens[i] = cur_len;
    }
    data += (elems + 1) / 2 * nb;
    nb ^= (elems & 1);
}
