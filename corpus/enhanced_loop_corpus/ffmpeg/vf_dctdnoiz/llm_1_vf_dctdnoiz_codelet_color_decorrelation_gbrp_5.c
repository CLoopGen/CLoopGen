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
        int offset = y * src_linesize;
        int doffset = y * dst_linesize;
        for (x = 0; x < w; x++) {
            int idx = offset + x;
            int didx = doffset + x;
            dstp_r[didx] = srcp_r[idx] * 0.577350259F + srcp_g[idx] * 0.577350259F + srcp_b[idx] * 0.577350259F;
            dstp_g[didx] = srcp_r[idx] * 0.707106769F + srcp_b[idx] * -0.707106769F;
            dstp_b[didx] = srcp_r[idx] * 0.408248305F + srcp_g[idx] * -0.816496611F + srcp_b[idx] * 0.408248305F;
        }
    }
}
