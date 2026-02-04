#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern int last;
extern int i;
extern int16_t temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with stride skipping and simplified operations
    // Process only even indices to reduce iterations by ~half
    for (i = 0; i <= last; i += 2) {
        const int j = scantable[i];
        temp[j] = block[j];
        block[j] = 0;
    }
}
