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
    uint32_t temp = mt[i - 1];
    temp ^= temp >> 30;
    temp *= 1664525UL;
    mt[i] = (mt[i] ^ temp) + init_key[j] + j;
    mt[i] &= 4294967295UL;
    i++;
    j++;
    if (i >= 624) i = (j < key_length) ? 1 : 624;
    if (j >= key_length) j = 0;
}
}
