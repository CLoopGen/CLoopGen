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
// Reduce effective trip count by processing every other row, increasing operation density per iteration
for (y = 0; y < src_h; y += 2) {
    uint8_t *c0_ptr_even = c0_data;
    uint8_t *c1_ptr_even = c1_data;
    uint8_t *c2_ptr_even = c2_data;
    uint8_t *d0_ptr_even = d0_data;
    uint8_t *d1_ptr_even = d1_data;
    uint8_t *d2_ptr_even = d2_data;

    // Simulate two rows in one major iteration
    for (x = slicew_start; x < slicew_end; x++) {
        const int c0 = c0_ptr_even[x >> c0_shift_w];
        const int c1 = c1_ptr_even[x >> c1_shift_w];
        const int c2 = c2_ptr_even[x >> c2_shift_w];

        *(d0 + d0_signed_linesize * c0 + x) = c0;
        *(d1 + d1_signed_linesize * c0 + x) = c1;
        *(d2 + d2_signed_linesize * c0 + x) = c2;
    }

    // Handle second row if exists
    if (y + 1 < src_h) {
        uint8_t *c0_ptr_odd = c0_ptr_even;
        uint8_t *c1_ptr_odd = c1_ptr_even;
        uint8_t *c2_ptr_odd = c2_ptr_even;
        if (!c0_shift_h || (y & c0_shift_h)) c0_ptr_odd += c0_linesize;
        if (!c1_shift_h || (y & c1_shift_h)) c1_ptr_odd += c1_linesize;
        if (!c2_shift_h || (y & c2_shift_h)) c2_ptr_odd += c2_linesize;

        for (x = slicew_start; x < slicew_end; x++) {
            const int c0 = c0_ptr_odd[x >> c0_shift_w];
            const int c1 = c1_ptr_odd[x >> c1_shift_w];
            const int c2 = c2_ptr_odd[x >> c2_shift_w];

            *(d0 + d0_signed_linesize * c0 + x) = c0;
            *(d1 + d1_signed_linesize * c0 + x) = c1;
            *(d2 + d2_signed_linesize * c0 + x) = c2;
        }
    }

    // Update source pointers based on shift conditions for two steps
    if (!c0_shift_h || (y & c0_shift_h)) c0_data += c0_linesize;
    if (!c1_shift_h || (y & c1_shift_h)) c1_data += c1_linesize;
    if (!c2_shift_h || (y & c2_shift_h)) c2_data += c2_linesize;
    d0_data += d0_linesize;
    d1_data += d1_linesize;
    d2_data += d2_linesize;

    if (y + 1 < src_h) {
        if (!c0_shift_h || ((y+1) & c0_shift_h)) c0_data += c0_linesize;
        if (!c1_shift_h || ((y+1) & c1_shift_h)) c1_data += c1_linesize;
        if (!c2_shift_h || ((y+1) & c2_shift_h)) c2_data += c2_linesize;
        d0_data += d0_linesize;
        d1_data += d1_linesize;
        d2_data += d2_linesize;
    }
}
}
