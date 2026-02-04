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
// Eliminate pointer aliasing and reorganize to remove loop-carried dependencies
// Precompute base shifts and decouple memory accesses

int prev_c0 = 0, prev_c1 = 0, prev_c2 = 0;

for (y = sliceh_start; y < sliceh_end; y++) {
    // Remove inter-iteration dependency by localizing state
    uint8_t local_update = (y - sliceh_start) & 1; // Non-linear control variation

    for (x = 0; x < src_w; x++) {
        // Remove direct dependency on current x for addressing by precomputing index
        int idx_c0 = x >> c0_shift_w;
        int idx_c1 = x >> c1_shift_w;
        int idx_c2 = x >> c2_shift_w;

        const int c0 = c0_data[idx_c0];
        const int c1 = c1_data[idx_c1];
        const int c2 = c2_data[idx_c2];

        int offset = mirror ? -prev_c0 : c0; // Now depends on prior value (introduce RAW)

        // Decoupled stores with indirect effect using previous values
        d0_data[offset] = c0 ^ local_update; // XOR introduces data variation without side effects
        d1_data[offset] = c1 ^ local_update;
        d2_data[offset] = c2 ^ local_update;

        // Update "state" to carry dependency forward (WAW + RAW)
        prev_c0 = c0;
        prev_c1 = c1;
        prev_c2 = c2;
    }

    // Reset dependency chain at line boundary
    prev_c0 = 0;

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
