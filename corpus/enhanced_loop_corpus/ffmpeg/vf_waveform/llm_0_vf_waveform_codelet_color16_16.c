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
    const int c0_shift_w_inv = 1 << c0_shift_w;
    const int c1_shift_w_inv = 1 << c1_shift_w;
    const int c2_shift_w_inv = 1 << c2_shift_w;
    uint16_t *d0_line = d0 + d0_signed_linesize * (c0_data[0] > limit ? limit : c0_data[0]);
    uint16_t *d1_line = d1 + d1_signed_linesize * (c1_data[0]);
    uint16_t *d2_line = d2 + d2_signed_linesize * (c2_data[0]);
    for (x = slicew_start; x < slicew_end; x++) {
        const int index0 = x >> c0_shift_w;
        const int index1 = x >> c1_shift_w;
        const int index2 = x >> c2_shift_w;
        const int c0 = (c0_data[index0] > limit) ? limit : c0_data[index0];
        const int c1 = c1_data[index1];
        const int c2 = c2_data[index2];
        d0_line[x] = c0;
        d1_line[x] = c1;
        d2_line[x] = c2;
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
