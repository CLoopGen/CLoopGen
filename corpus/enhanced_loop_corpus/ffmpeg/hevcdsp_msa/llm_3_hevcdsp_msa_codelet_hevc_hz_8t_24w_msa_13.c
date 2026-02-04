#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern int16_t *dst;
extern int32_t dst_stride;
extern int32_t height;
extern uint32_t loop_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (loop_cnt = (height >> 1); loop_cnt--;) {
        // Variant 2: Strided memory access with indirect indexing using index array
        int32_t idx[4];
        for (int i = 0; i < 4; ++i) {
            idx[i] = i * 2;  // Simulate non-unit stride indices
        }

        // Access source with strided pattern via indirect indexing
        int16_t temp[8];
        for (int i = 0; i < 4; ++i) {
            temp[i*2+0] = (int16_t)(src[idx[i]             ]);
            temp[i*2+1] = (int16_t)(src[idx[i] + src_stride]);
        }

        // Write to destination with same strided logic
        for (int i = 0; i < 4; ++i) {
            dst[idx[i]              ] = temp[i*2+0] + 10;
            dst[idx[i] + dst_stride ] = temp[i*2+1] + 10;
        }

        // Advance pointers by two rows
        src += (src_stride << 1);
        dst += (dst_stride << 1);
    }
}
