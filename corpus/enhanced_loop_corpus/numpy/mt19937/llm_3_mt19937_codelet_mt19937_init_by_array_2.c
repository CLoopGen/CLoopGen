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
    int prev_i = (i == 0) ? 623 : i - 1;
    mt[i] = (mt[i] ^ ((mt[prev_i] ^ (mt[prev_i] >> 30)) * 1664525UL)) + init_key[j] + j;
    mt[i] &= 4294967295UL;
    i += 2;
    j++;
    if (i >= 624) {
        i = (i == 624) ? 0 : 1;
        mt[0] = mt[623];
    }
    if (j >= key_length) {
        j = 0;
    }
    k--; 
    if (!k) break;
    prev_i = (i == 0) ? 623 : i - 1;
    mt[i] = (mt[i] ^ ((mt[prev_i] ^ (mt[prev_i] >> 30)) * 1664525UL)) + init_key[j] + j;
    mt[i] &= 4294967295UL;
    i += 2;
    j++;
    if (i >= 624) {
        i = (i == 624) ? 0 : 1;
        mt[0] = mt[623];
    }
    if (j >= key_length) {
        j = 0;
    }
}
}
