#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int low;
extern int high;
extern int w;
extern int h;
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_val;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i++) {
            temp_val = src[i];
            if (temp_val > high) {
                dst[i] = temp_val;
                continue;
            }
            if ((!i || i == w - 1 || !j || j == h - 1) && temp_val > low) {
                int neighbor_high = 0;
                neighbor_high |= (src[-src_linesize + i - 1] > high);
                neighbor_high |= (src[-src_linesize + i] > high);
                neighbor_high |= (src[-src_linesize + i + 1] > high);
                neighbor_high |= (src[i - 1] > high);
                neighbor_high |= (src[i + 1] > high);
                neighbor_high |= (src[src_linesize + i - 1] > high);
                neighbor_high |= (src[src_linesize + i] > high);
                neighbor_high |= (src[src_linesize + i + 1] > high);
                if (neighbor_high)
                    dst[i] = temp_val;
                else
                    dst[i] = 0;
            } else {
                dst[i] = 0;
            }
        }
        dst += dst_linesize;
        src += src_linesize;
    }
}
