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
// Eliminate loop-carried dependencies by precomputing line strides and using local accumulators
int c0_offset = 0, c1_offset = 0, c2_offset = 0;
int d0_offset = 0, d1_offset = 0, d2_offset = 0;

for (y = sliceh_start; y < sliceh_end; y++) {
    // Remove pointer arithmetic carried across iterations by computing base pointers once
    uint16_t *local_c0 = c0_data + c0_offset;
    uint16_t *local_c1 = c1_data + c1_offset;
    uint16_t *local_c2 = c2_data + c2_offset;
    uint16_t *local_d0 = d0_data + d0_offset;
    uint16_t *local_d1 = d1_data + d1_offset;
    uint16_t *local_d2 = d2_data + d2_offset;

    for (x = 0; x < src_w; x++) {
        const int idx0 = x >> c0_shift_w;
        const int idx1 = x >> c1_shift_w;
        const int idx2 = x >> c2_shift_w;
        int c0 = local_c0[idx0];
        int c1 = local_c1[idx1];
        int c2 = local_c2[idx2];

        if (c0 > limit)
            c0 = limit;

        // Break potential WAR hazard by ensuring no write affects current read in same iteration
        // All reads are completed before any write in this version

        int d_index = mirror ? -c0 : c0;
        local_d0[d_index] = c0;
        local_d1[d_index] = c1;
        local_d2[d_index] = c2;
    }

    // Update offsets instead of raw pointers to eliminate pointer update dependencies
    if (!c0_shift_h || (y & c0_shift_h))
        c0_offset += c0_linesize;
    if (!c1_shift_h || (y & c1_shift_h))
        c1_offset += c1_linesize;
    if (!c2_shift_h || (y & c2_shift_h))
        c2_offset += c2_linesize;
    d0_offset += d0_linesize;
    d1_offset += d1_linesize;
    d2_offset += d2_linesize;
}
}
