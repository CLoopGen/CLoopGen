#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int dst_linesize;
extern int src_linesize;
extern int w;
extern int h;
extern int x;
extern int y;
extern float *dstp_r;
extern float *dstp_g;
extern float *dstp_b;
extern  uint8_t *srcp_r;
extern  uint8_t *srcp_g;
extern  uint8_t *srcp_b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 4) {
        for (int k = 0; k < 4 && (x + k) < w; k++) {
            int idx = x + k;
            float sr = srcp_r[idx];
            float sg = srcp_g[idx];
            float sb = srcp_b[idx];
            dstp_r[idx] = (sr + sg + sb) * 0.577350259F;
            dstp_g[idx] = (sr - sb) * 0.707106769F;
            dstp_b[idx] = (sr + sb) * 0.408248305F - sg * 0.816496611F;
        }
    }
    srcp_r += src_linesize;
    srcp_g += src_linesize;
    srcp_b += src_linesize;
    dstp_r += dst_linesize;
    dstp_g += dst_linesize;
    dstp_b += dst_linesize;
}
}
