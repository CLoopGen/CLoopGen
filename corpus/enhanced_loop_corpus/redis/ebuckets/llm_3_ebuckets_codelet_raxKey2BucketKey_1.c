#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *raxKey;
extern uint64_t bucketKey;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index lookup table
    // Define a fixed indirect access pattern within bounds
    static const int indices[6] = {5, 4, 3, 2, 1, 0}; // Reverse order access
    bucketKey = 0;
    for (int i = 0; i < 6; ++i) {
        bucketKey = (bucketKey << 8) + raxKey[indices[i]];
    }
}
