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
    int skip_row = (y < 10 || y >= h - 10);
    for (x = 0; x < w; x++) {
        if (!skip_row || x % 2 == 0) {
            float r_val = srcp_r[x] * 0.577350259F;
            float g_val = srcp_g[x] * 0.577350259F;
            float b_val = srcp_b[x] * 0.577350259F;
            dstp_r[x] = r_val + g_val + b_val;
            dstp_g[x] = srcp_r[x] * 0.707106769F - srcp_b[x] * 0.707106769F;
            dstp_b[x] = srcp_r[x] * 0.408248305F - srcp_g[x] * 0.816496611F + srcp_b[x] * 0.408248305F;
        } else {
            dstp_r[x] = dstp_g[x] = dstp_b[x] = 0.0F;
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
