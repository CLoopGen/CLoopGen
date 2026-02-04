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
        const uint8_t *c0_ptr = c0_data;
        const uint8_t *c1_ptr = c1_data;
        const uint8_t *c2_ptr = c2_data;
        uint8_t *d0_row = d0_data;
        uint8_t *d1_row = d1_data;
        uint8_t *d2_row = d2_data;
        for (x = slicew_start; x < slicew_end; x++) {
            const int c0 = c0_ptr[x >> c0_shift_w];
            const int c1 = c1_ptr[x >> c1_shift_w];
            const int c2 = c2_ptr[x >> c2_shift_w];
            d0_row[d0_signed_linesize * c0 + x] = c0;
            d1_row[d1_signed_linesize * c0 + x] = c1;
            d2_row[d2_signed_linesize * c0 + x] = c2;
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
