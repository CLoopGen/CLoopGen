#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *pix1;
extern uint8_t *pix2;
extern ptrdiff_t stride;
extern int h;
extern int s;
extern int i;
extern  uint32_t *sq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern - process every second element first, then the odd-offsets
    uint8_t *p1_even = pix1;
    uint8_t *p2_even = pix2;
    uint8_t *p1_odd = pix1 + 1;
    uint8_t *p2_odd = pix2 + 1;
    for (i = 0; i < h; i++) {
        // Process even indices: 0, 2, 4, 6
        s += sq[p1_even[0] - p2_even[0]];
        s += sq[p1_even[2] - p2_even[2]];
        s += sq[p1_even[4] - p2_even[4]];
        s += sq[p1_even[6] - p2_even[6]];
        // Process odd indices: 1, 3, 5, 7
        s += sq[p1_odd[0] - p2_odd[0]];
        s += sq[p1_odd[2] - p2_odd[2]];
        s += sq[p1_odd[4] - p2_odd[4]];
        s += sq[p1_odd[6] - p2_odd[6]];
        p1_even += stride;
        p2_even += stride;
        p1_odd += stride;
        p2_odd += stride;
    }
}
