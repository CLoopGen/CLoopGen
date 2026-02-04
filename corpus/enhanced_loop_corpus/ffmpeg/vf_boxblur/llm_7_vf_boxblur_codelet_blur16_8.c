#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int dst_step;
extern  uint16_t *src;
extern int src_step;
extern int len;
extern int radius;
extern  int inv;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_dst[256]; // Local accumulation to break WAW dependency on dst
    int local_len = len - x < 256 ? len - x : 256;
    int i;
    int temp_sum = sum;
    for (i = 0; i < local_len; i++) {
        int cur_x = x + i;
        temp_sum += (src[(2 * len - radius - cur_x - 1) * src_step] - src[(cur_x - radius - 1) * src_step]) * inv;
        local_dst[i] = temp_sum >> 16;
    }
    // Store results back in a separate loop to eliminate combined compute/store dependency
    for (i = 0; i < local_len; i++) {
        dst[(x + i) * dst_step] = local_dst[i];
    }
    sum = temp_sum;
    x += local_len;
}
