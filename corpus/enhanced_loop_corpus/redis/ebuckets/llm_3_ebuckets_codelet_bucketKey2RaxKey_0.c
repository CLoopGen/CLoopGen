#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t bucketKey;
extern unsigned char *raxKey;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using an index array (Memory Access Pattern: indirect/strided)
    int indices[6] = {5, 3, 1, 4, 0, 2}; // Non-sequential access pattern
    uint64_t tempBucket = bucketKey;
    for (int i = 0; i < 6; ++i) {
        raxKey[indices[i]] = (unsigned char)(tempBucket & 255);
        tempBucket >>= 8;
    }
}
