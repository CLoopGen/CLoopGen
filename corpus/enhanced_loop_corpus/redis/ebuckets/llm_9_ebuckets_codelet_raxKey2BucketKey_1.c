#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *raxKey;
extern uint64_t bucketKey;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 3; ++i) {
        uint64_t temp1 = (raxKey[i * 2] << 4) ^ raxKey[i * 2 + 1];
        uint64_t temp2 = temp1 & 0xFF;
        bucketKey = (bucketKey << 16) | temp2;
    }
}
