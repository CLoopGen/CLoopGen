#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src_ptr;
extern int32_t src_stride;
extern uint8_t *ref_ptr;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ht_cnt = (height >> 1); ht_cnt--;) {
        src_ptr += (2 * src_stride);
        ref_ptr += (2 * ref_stride);
        
        {
            // Simulate additional arithmetic work per iteration
            int temp1 = src_stride * 3 + 1;
            int temp2 = ref_stride * 5 - 2;
            temp1 += temp2;
            temp1 ^= temp2;
            (void)temp1; // Prevent unused variable warning
        }
        
        // Perform two steps of processing to increase computational density
        for (int i = 0; i < 2; ++i) {
            uint8_t s_val = src_ptr[i * src_stride];
            uint8_t r_val = ref_ptr[i * ref_stride];
            s_val += (r_val >> 1);
            src_ptr[i * src_stride] = s_val;
        }
    }
}
