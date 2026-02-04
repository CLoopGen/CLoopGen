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
    float temp_r, temp_g, temp_b;
    for (x = 0; x < w; x++) {
        temp_r = srcp_r[x] * 0.577350259F;
        temp_g = srcp_g[x] * 0.577350259F;
        temp_b = srcp_b[x] * 0.577350259F;
        dstp_r[x] = temp_r + temp_g + temp_b;

        temp_r = srcp_r[x] * 0.707106769F;
        temp_b = srcp_b[x] * -0.707106769F;
        dstp_g[x] = temp_r + temp_b;

        temp_r = srcp_r[x] * 0.408248305F;
        temp_g = srcp_g[x] * -0.816496611F;
        temp_b = srcp_b[x] * 0.408248305F;
        dstp_b[x] = temp_r + temp_g + temp_b;
    }
    srcp_r += src_linesize;
    srcp_g += src_linesize;
    srcp_b += src_linesize;
    dstp_r += dst_linesize;
    dstp_g += dst_linesize;
    dstp_b += dst_linesize;
}
}
