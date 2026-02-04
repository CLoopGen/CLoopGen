#include <stdio.h>

#include <inttypes.h>

extern int64_t cond[5];
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 3; i++) {
        int64_t temp1 = (cond[i] & 72057594037927935L) - 1;
        int64_t temp2 = (temp1 * temp1) | temp1;
        cond[i] = (temp2 >> 63) & 1;
        cond[4 - i] = ((cond[4 - i] ^ 0xFFFFFFFFFFFFFFFFL) >> 63) | 1;
    }
}
