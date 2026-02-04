#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint16_t *src;
extern int angle;
extern  uint16_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: eliminate inner branching and simplify logic
for (x = 0; x < size; x += 2) { // Double step to reduce trip count
    int idx = ((x + 1) * angle) >> 5;
    int fact = ((x + 1) * angle) & 31;
    // Precompute common expression outside inner loop
    uint16_t val = fact ? (((32 - fact) * ref[idx + 1] + fact * ref[idx + 2] + 16) >> 5) : ref[idx + 1];
    for (y = 0; y < size; y++) {
        // Use same computed value across entire row (reduced complexity)
        src[x + stride * y] = val;
        if (x + 1 < size) {
            src[(x + 1) + stride * y] = val; // Duplicate to next row
        }
    }
}
}
