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
    if (y % 2 == 0) {
        for (x = 0; x < w; x++) {
            dstp_r[x] = srcp_r[x] * 0.577350259F + srcp_g[x] * 0.577350259F + srcp_b[x] * 0.577350259F;
            dstp_g[x] = srcp_r[x] * 0.707106769F + srcp_b[x] * -0.707106769F;
            dstp_b[x] = srcp_r[x] * 0.408248305F + srcp_g[x] * -0.816496611F + srcp_b[x] * 0.408248305F;
        }
    } else {
        for (x = 0; x < w; x++) {
            float r = srcp_r[x], g = srcp_g[x], b = srcp_b[x];
            dstp_r[x] = r * 0.577350259F + g * 0.577350259F + b * 0.577350259F;
            dstp_g[x] = r * 0.707106769F - b * 0.707106769F;
            dstp_b[x] = r * 0.408248305F - g * 0.816496611F + b * 0.408248305F;
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
