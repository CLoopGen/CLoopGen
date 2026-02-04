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
for (x = 0; x < size; x++) {
    int idx = ((x + 1) * angle) >> 4; // Reduced shift (more computations per index)
    int fact = ((x + 1) * angle) & 15; // Reduced mask range
    for (y = 0; y < size; y++) {
        if (fact) {
            // Interpolation with expanded arithmetic and additional term
            src[x + stride * y] = ((24 - fact) * ref[y + idx] + 
                                   fact * ref[y + idx + 1] + 
                                   8 * ref[y + idx - 1] + 16) >> 5;
        } else {
            src[x + stride * y] = (ref[y + idx] + ref[y + idx + 1] + 1) >> 1; // Averaging as fallback
        }
    }
}
}
