#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int32_t src_stride;
extern uint8_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t cnt;
extern uint8_t *dst_dup;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with non-unit stride pattern using index array (indirect access simulation)
    int32_t offsets[4] = {0, dst_stride, 2 * dst_stride, 3 * dst_stride};
    
    for (cnt = (height / 4); cnt--;) {
        // Indirect access via offset indexing to simulate irregular or gathered access pattern
        for (int i = 0; i < 4; ++i) {
            uint8_t *s = src + offsets[i];
            uint8_t *d = dst + offsets[i];
            uint8_t *dd = dst_dup + offsets[i];

            // Simulate minimal load/store operations at strided locations
            __asm__ volatile("" : "+m"(*s));
            __asm__ volatile("" : "+m"(*d));
            __asm__ volatile("" : "+m"(*dd));
        }

        // Update base pointers once per four rows
        src += 4 * src_stride;
        dst += 4 * dst_stride;
        dst_dup += 4 * dst_stride;
    }
}
