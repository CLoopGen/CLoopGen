#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int32_t height;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = (height >> 3); cnt--;) {
        {
            {
                {
                    // Access 8 consecutive rows but stride through columns with step 2
                    volatile uint8_t dummy1 = src[0 * src_stride];
                    volatile uint8_t dummy2 = src[2 * src_stride];
                    volatile uint8_t dummy3 = src[4 * src_stride];
                    volatile uint8_t dummy4 = src[6 * src_stride];
                }
                ;
                {
                    // Access next set of strided elements in a non-unit pattern
                    volatile uint8_t dummy5 = src[1 * src_stride];
                    volatile uint8_t dummy6 = src[3 * src_stride];
                    volatile uint8_t dummy7 = src[5 * src_stride];
                    volatile uint8_t dummy8 = src[7 * src_stride];
                }
                ;
            }
            ;
            {
                {
                    // Simulate vertical access with alternating negative offset (mirrored access)
                    volatile uint8_t dummy9  = src[(8 - 1) * src_stride];
                    volatile uint8_t dummy10 = src[(8 - 3) * src_stride];
                    volatile uint8_t dummy11 = src[(8 - 5) * src_stride];
                    volatile uint8_t dummy12 = src[(8 - 7) * src_stride];
                }
                ;
                {
                    // Forward and backward interlaced access pattern
                    volatile uint8_t dummy13 = src[0 * src_stride];
                    volatile uint8_t dummy14 = src[7 * src_stride];
                    volatile uint8_t dummy15 = src[1 * src_stride];
                    volatile uint8_t dummy16 = src[6 * src_stride];
                }
                ;
            }
            ;
        }
        ;
        src += (8 * src_stride);
    }
}
