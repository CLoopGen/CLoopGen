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
for (y = 0; y < src_h; y += 2) {
    const uint8_t *c0_curr = c0_data;
    const uint8_t *c1_curr = c1_data;
    const uint8_t *c2_curr = c2_data;
    uint8_t *d0_curr = d0_data;
    uint8_t *d1_curr = d1_data;
    uint8_t *d2_curr = d2_data;

    const uint8_t *c0_next = c0_curr;
    const uint8_t *c1_next = c1_curr;
    const uint8_t *c2_next = c2_curr;
    uint8_t *d0_next = d0_curr;
    uint8_t *d1_next = d1_curr;
    uint8_t *d2_next = d2_curr;

    if (!c0_shift_h || (y & c0_shift_h))
        c0_next += c0_linesize;
    if (!c1_shift_h || (y & c1_shift_h))
        c1_next += c1_linesize;
    if (!c2_shift_h || (y & c2_shift_h))
        c2_next += c2_linesize;
    d0_next += d0_linesize;
    d1_next += d1_linesize;
    d2_next += d2_linesize;

    for (x = slicew_start; x < slicew_end; x++) {
        const int c0 = c0_curr[x >> c0_shift_w];
        const int c1 = c1_curr[x >> c1_shift_w];
        const int c2 = c2_curr[x >> c2_shift_w];
        const int c0_next_val = c0_next[x >> c0_shift_w];
        const int c1_next_val = c1_next[x >> c1_shift_w];
        const int c2_next_val = c2_next[x >> c2_shift_w];

        d0_curr[d0_signed_linesize * c0 + x] = c0;
        d1_curr[d1_signed_linesize * c0 + x] = c1;
        d2_curr[d2_signed_linesize * c0 + x] = c2;

        if (y + 1 < src_h) {
            d0_next[d0_signed_linesize * c0_next_val + x] = c0_next_val;
            d1_next[d1_signed_linesize * c0_next_val + x] = c1_next_val;
            d2_next[d2_signed_linesize * c0_next_val + x] = c2_next_val;
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

    if (!c0_shift_h || ((y+1) & c0_shift_h))
        c0_data += c0_linesize;
    if (!c1_shift_h || ((y+1) & c1_shift_h))
        c1_data += c1_linesize;
    if (!c2_shift_h || ((y+1) & c2_shift_h))
        c2_data += c2_linesize;
    d0_data += d0_linesize;
    d1_data += d1_linesize;
    d2_data += d2_linesize;
}
}
