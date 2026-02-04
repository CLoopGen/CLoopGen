#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t bucketKey;
extern unsigned char *raxKey;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t tempBucket = bucketKey;
    for (int i = 0; i < 6; ++i) {
        raxKey[5 - i] = (unsigned char)(tempBucket & 255);
        tempBucket >>= 8;
    }
}
