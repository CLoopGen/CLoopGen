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
    const int update_c0 = !c0_shift_h || (y & c0_shift_h);
    const int update_c1 = !c1_shift_h || (y & c1_shift_h);
    const int update_c2 = !c2_shift_h || (y & c2_shift_h);

    for (x = slicew_start; x < slicew_end; x++) {
        const int c0 = c0_data[x >> c0_shift_w];
        const int c1 = c1_data[x >> c1_shift_w];
        const int c2 = c2_data[x >> c2_shift_w];
        uint8_t* target_d0 = d0 + d0_signed_linesize * c0 + x;
        uint8_t* target_d1 = d1 + d1_signed_linesize * c0 + x;
        uint8_t* target_d2 = d2 + d2_signed_linesize * c0 + x;

        *target_d0 = c0;
        *target_d1 = c1;
        *target_d2 = c2;
    }

    if (update_c0)
        c0_data += c0_linesize;
    if (update_c1)
        c1_data += c1_linesize;
    if (update_c2)
        c2_data += c2_linesize;

    d0_data += d0_linesize;
    d1_data += d1_linesize;
    d2_data += d2_linesize;
}
}
