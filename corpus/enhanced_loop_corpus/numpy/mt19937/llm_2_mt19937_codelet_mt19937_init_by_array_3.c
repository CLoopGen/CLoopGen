#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint32_t *mt;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 624 - 1; k; k--) {
    int idx = i;
    mt[idx] = (mt[idx] ^ ((mt[(idx + 623) % 624] ^ (mt[(idx + 623) % 624] >> 30)) * 1566083941UL)) - i;
    mt[idx] &= 4294967295UL;
    i++;
    if (i >= 624) {
        mt[0] = mt[623];
        i = 1;
    }
}
}
