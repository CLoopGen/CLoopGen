#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mirror;
extern  int limit;
extern  int src_w;
extern  int sliceh_start;
extern  int sliceh_end;
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
extern uint16_t *d0_data;
extern uint16_t *d1_data;
extern uint16_t *d2_data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = sliceh_start; y < sliceh_end; y++) {
    for (x = 0; x < src_w; x++) {
        const int c0 = ((c0_data[x >> c0_shift_w]) > (limit) ? (limit) : (c0_data[x >> c0_shift_w]));
        const int c1 = c1_data[x >> c1_shift_w];
        const int c2 = c2_data[x >> c2_shift_w];
        if (mirror) {
            *(d0_data - c0) = c0;
            *(d1_data - c1) = c1;
            *(d2_data - c2) = c2;
        } else {
            *(d0_data + c0) = c0;
            *(d1_data + c1) = c1;
            *(d2_data + c2) = c2;
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
