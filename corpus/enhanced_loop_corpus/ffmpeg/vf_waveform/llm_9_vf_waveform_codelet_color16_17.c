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
for (y = sliceh_start; y < sliceh_end; y += 2) {
    int processed_rows = 0;
    for (x = 0; x < src_w; x++) {
        const int shift_mask_w = (1 << c0_shift_w) - 1;
        const int c0_raw = c0_data[(x >> c0_shift_w)];
        const int c0_clamped = (c0_raw & ~shift_mask_w) | ((c0_raw & shift_mask_w) > limit ? limit : (c0_raw & shift_mask_w));
        const int c1_val = c1_data[x >> c1_shift_w];
        const int c2_val = c2_data[x >> c2_shift_w];

        int offset = mirror ? -c0_clamped : c0_clamped;
        d0_data[offset] = c0_clamped;
        d1_data[offset] = c1_val;
        d2_data[offset] = c2_val;
    }

    processed_rows++;
    d0_data += d0_linesize;
    d1_data += d1_linesize;
    d2_data += d2_linesize;

    if (y + 1 < sliceh_end) {
        for (x = 0; x < src_w; x++) {
            const int c0_val = (c0_data[x >> c0_shift_w] > limit) ? limit : c0_data[x >> c0_shift_w];
            const int c1_val = c1_data[x >> c1_shift_w];
            const int c2_val = c2_data[x >> c2_shift_w];
            *(d0_data + (mirror ? -c0_val : c0_val)) = c0_val;
            *(d1_data + (mirror ? -c0_val : c0_val)) = c1_val;
            *(d2_data + (mirror ? -c0_val : c0_val)) = c2_val;
        }
        processed_rows++;
        d0_data += d0_linesize;
        d1_data += d1_linesize;
        d2_data += d2_linesize;
    }

    if (!c0_shift_h || (y & c0_shift_h))
        c0_data += c0_linesize * processed_rows;
    if (!c1_shift_h || (y & c1_shift_h))
        c1_data += c1_linesize * processed_rows;
    if (!c2_shift_h || (y & c2_shift_h))
        c2_data += c2_linesize * processed_rows;
}
}
