#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mirror;
extern  int src_w;
extern  int sliceh_start;
extern  int sliceh_end;
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
extern uint8_t *d0_data;
extern uint8_t *d1_data;
extern uint8_t *d2_data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = sliceh_start; y < sliceh_end; y++) {
    uint8_t *temp_d0 = d0_data;
    uint8_t *temp_d1 = d1_data;
    uint8_t *temp_d2 = d2_data;
    const uint8_t *temp_c0 = c0_data;
    const uint8_t *temp_c1 = c1_data;
    const uint8_t *temp_c2 = c2_data;

    for (x = 0; x < src_w; x++) {
        const int c0 = temp_c0[x >> c0_shift_w];
        const int c1 = temp_c1[x >> c1_shift_w];
        const int c2 = temp_c2[x >> c2_shift_w];

        int offset = mirror ? -c0 : c0;

        // Introduce artificial WAW and WAR dependencies via temporary accumulation
        // Use same offset for all to create data dependency chain
        temp_d0[offset] = c0;
        temp_d1[offset] = c1;
        temp_d2[offset] = c2;

        // Create loop-carried dependency: each iteration depends on prior write via c0
        // This creates a RAW hazard artificially carried across iterations
        if (x > 0) {
            temp_d0[offset] += temp_d1[offset]; // Feedback from previous state
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
