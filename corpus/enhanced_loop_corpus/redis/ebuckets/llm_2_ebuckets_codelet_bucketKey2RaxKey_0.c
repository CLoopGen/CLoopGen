#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t bucketKey;
extern unsigned char *raxKey;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive reverse traversal with index remapping (Memory Access Pattern: consecutive backward)
    unsigned char temp[6];
    for (int i = 0; i < 6; ++i) {
        temp[i] = (unsigned char)((bucketKey >> (8 * i)) & 255);
    }
    for (int i = 0; i < 6; ++i) {
        raxKey[5 - i] = temp[i];
    }
}
