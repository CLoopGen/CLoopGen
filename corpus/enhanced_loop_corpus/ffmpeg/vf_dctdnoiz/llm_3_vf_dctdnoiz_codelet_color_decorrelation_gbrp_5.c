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
    // Variant 2: Strided memory access – process every 4th pixel first, then stride through the rest
    // This changes access pattern to improve cache behavior in certain architectures or data sizes
    const int stride = 4;
    for (y = 0; y < h; y++) {
        for (int s = 0; s < stride; s++) {
            for (x = s; x < w; x += stride) {
                dstp_r[x] = srcp_r[x] * 0.577350259F + srcp_g[x] * 0.577350259F + srcp_b[x] * 0.577350259F;
                dstp_g[x] = srcp_r[x] * 0.707106769F + srcp_b[x] * -0.707106769F;
                dstp_b[x] = srcp_r[x] * 0.408248305F + srcp_g[x] * -0.816496611F + srcp_b[x] * 0.408248305F;
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
