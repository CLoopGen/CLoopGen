#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *raxKey;
extern uint64_t bucketKey;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t localBucket = 0;
    for (int i = 0; i < 6; ++i) {
        localBucket |= ((uint64_t)raxKey[i]) << (8 * (5 - i));
    }
    bucketKey = localBucket;
}
