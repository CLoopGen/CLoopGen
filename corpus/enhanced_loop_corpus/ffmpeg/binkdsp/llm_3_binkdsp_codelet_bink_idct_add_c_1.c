#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dest;
extern int linesize;
extern int32_t *block;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive and flattened access using pointer arithmetic without indexing
    uint8_t *d = dest;
    int32_t *b = block;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
            d[j] += b[j];
        d += linesize;
        b += 8;
    }
}
