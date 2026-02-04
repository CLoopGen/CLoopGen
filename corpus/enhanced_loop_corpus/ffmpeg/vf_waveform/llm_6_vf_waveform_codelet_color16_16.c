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
    const int temp_c0_shift = c0_shift_h ? ((y & c0_shift_h) ? c0_linesize : 0) : c0_linesize;
    const int temp_c1_shift = c1_shift_h ? ((y & c1_shift_h) ? c1_linesize : 0) : c1_linesize;
    const int temp_c2_shift = c2_shift_h ? ((y & c2_shift_h) ? c2_linesize : 0) : c2_linesize;
    uint16_t *local_c0 = c0_data + temp_c0_shift * y;
    uint16_t *local_c1 = c1_data + temp_c1_shift * y;
    uint16_t *local_c2 = c2_data + temp_c2_shift * y;
    uint16_t *local_d0 = d0_data + d0_linesize * y;
    uint16_t *local_d1 = d1_data + d1_linesize * y;
    uint16_t *local_d2 = d2_data + d2_linesize * y;

    for (x = slicew_start; x < slicew_end; x++) {
        const int index_x0 = x >> c0_shift_w;
        const int index_x1 = x >> c1_shift_w;
        const int index_x2 = x >> c2_shift_w;
        const int c0_val = (local_c0[index_x0] > limit) ? limit : local_c0[index_x0];
        const int c1_val = local_c1[index_x1];
        const int c2_val = local_c2[index_x2];

        // Introduce WAW dependency by reordering and combining stores with intermediate computation
        int addr_offset = d0_signed_linesize * c0_val + x;
        d0[addr_offset] = c0_val;
        d1[addr_offset] = c1_val;
        d2[addr_offset] = c2_val;
    }
}
}
