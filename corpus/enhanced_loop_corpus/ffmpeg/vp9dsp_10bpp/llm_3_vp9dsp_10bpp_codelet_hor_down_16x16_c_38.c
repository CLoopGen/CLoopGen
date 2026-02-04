#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[46];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal and stride of 2
    // Simulate strided access pattern by stepping backwards with gaps

    // Reverse iteration with stride emulation via index scaling
    for (i = 13; i >= 0; i -= 2) {  // Half the iterations, but process two logical steps
        int idx = i;

        // Strided read from left: access every other element but use neighboring ones
        v[idx * 2] = (left[idx + 1] + left[idx + 0] + 1) >> 1;
        v[idx * 2 + 1] = (left[idx + 2] + (left[idx + 1] << 1) + left[idx + 0] + 2) >> 2;

        // Top array accessed with negative offset, now also in reverse order
        v[32 + idx] = (top[idx - 1] + (top[idx] << 1) + top[idx + 1] + 2) >> 2;

        // Process intermediate index when possible (idx-1), ensuring bounds
        if (i > 0) {
            int j = i - 1;
            v[j * 2] = (left[j + 1] + left[j + 0] + 1) >> 1;
            v[j * 2 + 1] = (left[j + 2] + (left[j + 1] << 1) + left[j + 0] + 2) >> 2;
            v[32 + j] = (top[j - 1] + (top[j] << 1) + top[j + 1] + 2) >> 2;
        }
    }
}
