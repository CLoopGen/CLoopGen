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
uint32_t prev_mt_i = mt[i];
for (; k; k--) {
    uint32_t data = (prev_mt_i ^ ((mt[i - 1] ^ (mt[i - 1] >> 30)) * 1664525UL)) + init_key[j] + j;
    data &= 4294967295UL;
    mt[i] = data;
    prev_mt_i = data;
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
