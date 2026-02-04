#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int zeros;
extern uint8_t *dst_end;
extern  uint8_t *src_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Process elements in a strided pattern: access every second element in both src and dst
    // After processing, fill in the skipped positions if needed to maintain logical equivalence over full range
    ptrdiff_t stride = 2;
    uint8_t *src_temp = src;
    uint8_t *dst_temp = dst;

    // First pass: process elements with stride
    for (; src_temp < src_end; src_temp += stride, dst_temp += stride) {
        if (zeros == 2) {
            int insert_ep3_byte = *src_temp <= 3;
            if (insert_ep3_byte) {
                if (dst_temp < dst_end)
                    *dst_temp = 3;
                dst_temp++;
                // Adjust forward due to insertion
                if (dst_temp >= dst_end) break;
            }
            zeros = 0;
        }
        if (dst_temp < dst_end)
            *dst_temp = *src_temp;
        if (!*src_temp)
            zeros++;
        else
            zeros = 0;
    }

    // Second pass: handle remaining elements (non-aligned or odd-sized arrays)
    for (src_temp = src + 1; src_temp < src_end; src_temp += stride) {
        uint8_t *local_dst = dst + (src_temp - src);
        if (local_dst >= dst_end) break;
        if (zeros == 2) {
            int insert_ep3_byte = *src_temp <= 3;
            if (insert_ep3_byte) {
                if (local_dst < dst_end)
                    *local_dst = 3;
                local_dst++;
                if (local_dst >= dst_end) break;
            }
            zeros = 0;
        }
        if (local_dst < dst_end)
            *local_dst = *src_temp;
        if (!*src_temp)
            zeros++;
        else
            zeros = 0;
    }

    // Update global pointers based on actual processed size
    src = src_end;
    dst = (dst + (src_end - src)) > dst_end ? dst_end : (dst + (src_end - src));
}
