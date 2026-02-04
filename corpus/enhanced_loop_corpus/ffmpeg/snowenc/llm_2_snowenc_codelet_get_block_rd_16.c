#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern uint8_t (*obmc_edged)[32];
extern  int obmc_stride;
extern  int ref_stride;
extern uint8_t *dst;
extern IDWTELEM *pred;
extern uint8_t *cur;
extern int sx;
extern int sy;
extern int x0;
extern int _usr_y0;
extern int x1;
extern int _usr_y1;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define y0 _usr_y0
#define y1 _usr_y1



void loop(){
    // Variant 1: Consecutive Memory Access with Array Reordering (Structure-of-Arrays to Array-of-Structures like access)
    // We process multiple elements ahead using a more cache-friendly linear traversal by precomputing base pointers and using offsets.
    IDWTELEM *pred_base = pred + y0 * obmc_stride;
    uint8_t *cur_base = cur + y0 * ref_stride;
    uint8_t *dst_base = dst + sx + sy * ref_stride;
    
    for (y = y0; y < y1; y++) {
        int offset = y - y0;
        const uint8_t *obmc1 = obmc_edged[y];
        const IDWTELEM *pred1 = pred_base + offset * obmc_stride;
        uint8_t *cur1 = cur_base + offset * ref_stride;
        uint8_t *dst1 = dst_base + (sy + offset) * ref_stride;

        // Ensure unit stride in inner loop for better vectorization
        for (x = x0; x < x1; x++) {
            int v = (cur1[x] * obmc1[x] + (1 << (8 - 4 - 1))) >> (8 - 4);
            v = (v + pred1[x]) >> 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst1[x] = v;
        }
    }
}
