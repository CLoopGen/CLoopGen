#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int src_h;
extern  int slicew_start;
extern  int slicew_end;
extern  int c0_linesize;
extern  int c1_linesize;
extern  int c2_linesize;
extern  int c0_shift_h;
extern  int c1_shift_h;
extern  int c2_shift_h;
extern  uint8_t *c0_data;
extern  uint8_t *c1_data;
extern  uint8_t *c2_data;
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
extern uint8_t *d0_data;
extern uint8_t *d1_data;
extern uint8_t *d2_data;
extern uint8_t * d0;
extern uint8_t * d1;
extern uint8_t * d2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < src_h; y++) {
        for (x = slicew_start; x < slicew_end; x++) {
            const int c0_x = x >> c0_shift_w;
            const int c1_x = x >> c1_shift_w;
            const int c2_x = x >> c2_shift_w;
            const int c0 = c0_data[c0_x];
            const int c1 = c1_data[c1_x];
            const int c2 = c2_data[c2_x];
            const ptrdiff_t offset = (ptrdiff_t)d0_signed_linesize * c0 + x;
            *(d0 + offset) = c0;
            *(d1 + offset) = c1;
            *(d2 + offset) = c2;
        }
        const int update_c0 = !c0_shift_h || (y & c0_shift_h);
        const int update_c1 = !c1_shift_h || (y & c1_shift_h);
        const int update_c2 = !c2_shift_h || (y & c2_shift_h);
        c0_data += update_c0 * c0_linesize;
        c1_data += update_c1 * c1_linesize;
        c2_data += update_c2 * c2_linesize;
        d0_data += d0_linesize;
        d1_data += d1_linesize;
        d2_data += d2_linesize;
    }
}
