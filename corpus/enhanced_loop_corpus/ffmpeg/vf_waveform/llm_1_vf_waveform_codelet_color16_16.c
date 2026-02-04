#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int limit;
extern  int src_h;
extern  int slicew_start;
extern  int slicew_end;
extern  int c0_linesize;
extern  int c1_linesize;
extern  int c2_linesize;
extern  int c0_shift_h;
extern  int c1_shift_h;
extern  int c2_shift_h;
extern  uint16_t *c0_data;
extern  uint16_t *c1_data;
extern  uint16_t *c2_data;
extern  int d0_linesize;
extern  int d1_linesize;
extern  int d2_linesize;
extern  int c0_shift_w;
extern  int c1_shift_w;
extern  int c2_shift_w;
extern int x;
extern int y;
extern  int d0_signed_linesize;
extern  int d1_signed_linesize;
extern  int d2_signed_linesize;
extern uint16_t *d0_data;
extern uint16_t *d1_data;
extern uint16_t *d2_data;
extern uint16_t * d0;
extern uint16_t * d1;
extern uint16_t * d2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < src_h; y++) {
    for (x = slicew_start; x < slicew_end; x += 2) {
        const int idx0_0 = (x + 0) >> c0_shift_w;
        const int idx1_0 = (x + 0) >> c1_shift_w;
        const int idx2_0 = (x + 0) >> c2_shift_w;
        const int c0_0 = (c0_data[idx0_0] > limit) ? limit : c0_data[idx0_0];
        const int c1_0 = c1_data[idx1_0];
        const int c2_0 = c2_data[idx2_0];
        *(d0 + d0_signed_linesize * c0_0 + x + 0) = c0_0;
        *(d1 + d1_signed_linesize * c0_0 + x + 0) = c1_0;
        *(d2 + d2_signed_linesize * c0_0 + x + 0) = c2_0;

        if (x + 1 < slicew_end) {
            const int idx0_1 = (x + 1) >> c0_shift_w;
            const int idx1_1 = (x + 1) >> c1_shift_w;
            const int idx2_1 = (x + 1) >> c2_shift_w;
            const int c0_1 = (c0_data[idx0_1] > limit) ? limit : c0_data[idx0_1];
            const int c1_1 = c1_data[idx1_1];
            const int c2_1 = c2_data[idx2_1];
            *(d0 + d0_signed_linesize * c0_1 + x + 1) = c0_1;
            *(d1 + d1_signed_linesize * c0_1 + x + 1) = c1_1;
            *(d2 + d2_signed_linesize * c0_1 + x + 1) = c2_1;
        }
    }
    if (!c0_shift_h || (y & c0_shift_h))
        c0_data += c0_linesize;
    if (!c1_shift_h || (y & c1_shift_h))
        c1_data += c1_linesize;
    if (!c2_shift_h || (y & c2_shift_h))
        c2_data += c2_linesize;
    d0_data += d0_linesize;
    d1_data += d1_linesize;
    d2_data += d2_linesize;
}
}
