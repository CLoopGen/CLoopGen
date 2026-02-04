#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern  uint8_t *p1;
extern int width;
extern int threshold;
extern  uint8_t *coordinates[];
extern int coord;
extern int maxc;
extern uint16_t *dst;
extern int x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with reversed coordinate traversal
    // Memory Access Pattern Modification: Access coordinates in reverse order (i = 7 down to 0) with strided access.
    // This changes temporal access pattern and may expose different cache behavior.

    for (x = 0; x < width; x++) {
        int max = (((const av_alias16 *)(&p1[x * 2]))->u16);
        int limit = ((max + threshold) > maxc ? maxc : max + threshold);

        // Traverse coordinates in reverse order (strided backward access)
        for (i = 7; i >= 0; i--) {
            if (coord & (1 << i)) {
                uint16_t val = ((const av_alias16 *)(coordinates[i] + x * 2))->u16;
                max = (max > val) ? max : val;
            }
            // Clamp after each update to maintain semantics
            max = (max > limit) ? limit : max;
        }

        dst[x] = max;
    }
}
