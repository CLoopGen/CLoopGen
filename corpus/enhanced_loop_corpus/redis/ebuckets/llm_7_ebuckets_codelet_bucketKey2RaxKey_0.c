#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t bucketKey;
extern unsigned char *raxKey;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t localKey = bucketKey;
    unsigned char tempArray[6];
    for (int i = 0; i < 6; ++i) {
        tempArray[i] = (unsigned char)(localKey & 255);
        localKey >>= 8;
    }
    for (int i = 0; i < 6; ++i) {
        raxKey[i] = tempArray[5 - i];
    }
}
