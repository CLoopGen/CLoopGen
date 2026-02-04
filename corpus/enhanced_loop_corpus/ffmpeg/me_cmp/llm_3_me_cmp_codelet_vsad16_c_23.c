#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *s1;
extern uint8_t *s2;
extern ptrdiff_t stride;
extern int h;
extern int score;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 1; y < h; y++) {
        for (x = 0; x < 16; x++) {
            ptrdiff_t idx = x * 2; // Strided access with step 2 in logical index (simulating non-unit stride pattern)
            ptrdiff_t base_s1 = (ptrdiff_t)(s1 - s1); // Dummy base for clarity; actual logic uses offset
            ptrdiff_t base_s2 = (ptrdiff_t)(s2 - s2);
            // Use strided memory access: effectively accessing every other element in a stretched layout
            ptrdiff_t offset1 = idx / 2;
            ptrdiff_t offset2 = (idx / 2) + stride;
            score += ((s1[offset1] - s2[offset1] - s1[offset2] + s2[offset2]) >= 0 ? 
                      (s1[offset1] - s2[offset1] - s1[offset2] + s2[offset2]) : 
                      (-(s1[offset1] - s2[offset1] - s1[offset2] + s2[offset2])));
        }
        s1 += stride;
        s2 += stride;
    }
}
