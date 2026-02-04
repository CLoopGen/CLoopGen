#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *block;
extern ptrdiff_t stride;
extern int height;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp = 0;
    for (y = 0; y < height; y++) {
        temp += block[0];           // Introduce RAW dependency: each iteration reads block[0] and depends on previous temp value
        block += stride;            // Update pointer after use
    }
    block -= stride;                // Restore block to last valid position (semantic preservation)
}
