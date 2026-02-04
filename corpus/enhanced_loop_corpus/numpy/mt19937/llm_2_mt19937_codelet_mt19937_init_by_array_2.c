#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *init_key;
extern int key_length;
extern int i;
extern int j;
extern uint32_t *mt;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; k; k--) {
    int idx_i = i;
    int idx_j = j % key_length;
    mt[idx_i] = (mt[idx_i] ^ ((mt[idx_i - 1] ^ (mt[idx_i - 1] >> 30)) * 1664525UL)) + init_key[idx_j] + idx_j;
    mt[idx_i] &= 4294967295UL;
    i++;
    j++;
    if (i >= 624) {
        mt[0] = mt[623];
        i = 1;
    }
    if (j >= key_length) {
        j = 0;
    }
}
}
