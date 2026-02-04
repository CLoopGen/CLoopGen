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
    const uint16_t *c0_row = c0_data;
    const uint16_t *c1_row = c1_data;
    const uint16_t *c2_row = c2_data;
    uint16_t *d0_row = d0_data;
    uint16_t *d1_row = d1_data;
    uint16_t *d2_row = d2_data;

    for (x = slicew_start; x < slicew_end; x++) {
        const int c0_idx = x >> c0_shift_w;
        const int c1_idx = x >> c1_shift_w;
        const int c2_idx = x >> c2_shift_w;

        const int c0_val = (c0_row[c0_idx] > limit) ? limit : c0_row[c0_idx];
        const int c1_val = c1_row[c1_idx];
        const int c2_val = c2_row[c2_idx];

        d0_row[x] = c0_val;
        d1_row[x] = c1_val;
        d2_row[x] = c2_val;
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
