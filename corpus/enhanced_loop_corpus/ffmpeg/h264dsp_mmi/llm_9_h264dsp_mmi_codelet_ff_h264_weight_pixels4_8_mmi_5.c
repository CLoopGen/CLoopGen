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
    for (y = 0; y < height * 3; y++ , block += stride / 3) {
        // Increased trip count and reduced memory stride per iteration
        // Simulates higher computational intensity with more iterations
        volatile uint8_t dummy = block[0]; // Prevent optimization
        (void)dummy;
    }
}
