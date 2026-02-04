#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern  uint8_t *src;
extern int src_step;
extern int len;
extern int radius;
extern  int inv;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < len * 2; i += 2) {
        int idx1 = (2 * len - radius - i - 1) * src_step;
        int idx2 = (i - radius - 1) * src_step;
        sum += (src[idx1] - ((i - radius - 1) >= 0 ? src[idx2] : 0)) * inv;
        dst[i * dst_step] = sum >> 16;
        if (i + 1 < len) {
            dst[(i + 1) * dst_step] = (sum + (src[(2 * len - radius - i - 2) * src_step] - ((i - radius) >= 0 ? src[(i - radius) * src_step] : 0)) * inv) >> 16;
        }
    }
}
