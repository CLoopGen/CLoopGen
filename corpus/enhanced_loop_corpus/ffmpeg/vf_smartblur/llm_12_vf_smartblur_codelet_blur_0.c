#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  int dst_linesize;
extern  uint8_t *src;
extern  int src_linesize;
extern  int w;
extern  int h;
extern  int threshold;
extern int x;
extern int y;
extern int orig;
extern int filtered;
extern int diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_val;
    for (y = 0; y < h; ++y) {
        for (x = 0; x < w; ++x) {
            // Reorder memory accesses to remove immediate write-back, reducing WAW hazards
            orig = src[x + y * src_linesize];
            filtered = dst[x + y * dst_linesize];
            diff = orig - filtered;

            temp_val = filtered; // Local accumulation to decouple write from read

            if (diff > 0) {
                if (diff > 2 * threshold)
                    temp_val = orig;
                else if (diff > threshold)
                    temp_val = orig - threshold;
            } else {
                if (-diff > 2 * threshold)
                    temp_val = orig;
                else if (-diff > threshold)
                    temp_val = orig + threshold;
            }

            // Single write at end of iteration — reduces intra-loop WAW and WAR dependencies
            dst[x + y * dst_linesize] = temp_val;
        }
    }
}
