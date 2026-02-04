#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern int32_t width;
extern uint8_t *src_tmp;
extern int16_t *dst_tmp;
extern int32_t loop_cnt;
extern int32_t cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cnt = width >> 4; cnt--;) {
        // Use indirect indexing via array of pointers to simulate strided/indirect access pattern
        uint8_t **src_ptrs = (uint8_t**)alloca(height * sizeof(uint8_t*));
        int16_t **dst_ptrs = (int16_t**)alloca(height * sizeof(int16_t*));
        
        // Initialize pointer array to point to each row (strided access base)
        for (int i = 0; i < height; i++) {
            src_ptrs[i] = &src[i * src_stride];
            dst_ptrs[i] = &dst[i * dst_stride];
        }

        // Now process 16 columns (unrolled partially) using indirect access
        for (int col = 0; col < 16; col++) {
            for (int row = 0; row < height; row++) {
                dst_ptrs[row][col] = (int16_t)(src_ptrs[row][col]);
            }
        }

        // Move to next 16-column block
        src += 16;
        dst += 16;
    }
}
