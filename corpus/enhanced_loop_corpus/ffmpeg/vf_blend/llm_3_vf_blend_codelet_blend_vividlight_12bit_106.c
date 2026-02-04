#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using indirect indexing with fixed step through lines
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) { // Stride of 2 on j for reduced frequency and strided access
            // Access even indices only, simulate strided pattern across row
            dst[j] = top[j] + (((top[j] < 2048) ? 
                (((2 * top[j]) == 0) ? (2 * top[j]) : 
                ((0) > (4095 - ((4095 - (bottom[j])) << 12) / (2 * top[j])) ? (0) : 
                (4095 - ((4095 - (bottom[j])) << 12) / (2 * top[j])))) : 
                (((2 * (top[j] - 2048)) == 4095) ? (2 * (top[j] - 2048)) : 
                ((4095) > ((((bottom[j]) << 12) / (4095 - (2 * (top[j] - 2048))))) ? 
                ((((bottom[j]) << 12) / (4095 - (2 * (top[j] - 2048))))) : (4095)))) - top[j]) * opacity;

            // Handle odd index if within bounds (preserve correctness)
            if (j + 1 < width) {
                dst[j + 1] = top[j + 1] + (((top[j + 1] < 2048) ? 
                    (((2 * top[j + 1]) == 0) ? (2 * top[j + 1]) : 
                    ((0) > (4095 - ((4095 - (bottom[j + 1])) << 12) / (2 * top[j + 1])) ? (0) : 
                    (4095 - ((4095 - (bottom[j + 1])) << 12) / (2 * top[j + 1])))) : 
                    (((2 * (top[j + 1] - 2048)) == 4095) ? (2 * (top[j + 1] - 2048)) : 
                    ((4095) > ((((bottom[j + 1]) << 12) / (4095 - (2 * (top[j + 1] - 2048))))) ? 
                    ((((bottom[j + 1]) << 12) / (4095 - (2 * (top[j + 1] - 2048))))) : (4095)))) - top[j + 1]) * opacity;
            }
        }
        // Update pointers with original strides
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
