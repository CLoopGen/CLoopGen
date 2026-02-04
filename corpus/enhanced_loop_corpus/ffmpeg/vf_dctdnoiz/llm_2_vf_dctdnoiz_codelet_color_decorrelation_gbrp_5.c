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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    // This variant assumes width is even and processes two pixels per iteration to enable better vectorization
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x += 2) {
            // Process two consecutive pixels at once
            int x1 = x;
            int x2 = x + 1;

            // Pixel 1
            dstp_r[x1] = srcp_r[x1] * 0.577350259F + srcp_g[x1] * 0.577350259F + srcp_b[x1] * 0.577350259F;
            dstp_g[x1] = srcp_r[x1] * 0.707106769F + srcp_b[x1] * -0.707106769F;
            dstp_b[x1] = srcp_r[x1] * 0.408248305F + srcp_g[x1] * -0.816496611F + srcp_b[x1] * 0.408248305F;

            // Pixel 2 (if within bounds)
            if (x2 < w) {
                dstp_r[x2] = srcp_r[x2] * 0.577350259F + srcp_g[x2] * 0.577350259F + srcp_b[x2] * 0.577350259F;
                dstp_g[x2] = srcp_r[x2] * 0.707106769F + srcp_b[x2] * -0.707106769F;
                dstp_b[x2] = srcp_r[x2] * 0.408248305F + srcp_g[x2] * -0.816496611F + srcp_b[x2] * 0.408248305F;
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
