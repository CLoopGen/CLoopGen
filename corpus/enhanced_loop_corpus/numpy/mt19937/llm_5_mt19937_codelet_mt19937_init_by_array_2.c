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
    mt[i] = (mt[i] ^ ((mt[i - 1] ^ (mt[i - 1] >> 30)) * 1664525UL)) + init_key[j] + j;
    mt[i] &= 4294967295UL;
    i = (i + 1) & 623;
    j = (j + 1) % (key_length ? key_length : 1);
    if (i == 0) {
        mt[0] = mt[623];
        i = 1;
    }
}
}
