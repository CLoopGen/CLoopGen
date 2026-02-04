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



void loop() {
    // Variant 2: Strided Memory Access with Reverse and Step Loop
    // Modify access pattern to process elements in reverse order with a fixed stride
    // This creates a strided, non-sequential access pattern to simulate different cache behavior

    const int stride = 4;  // Process every 4th element in reverse to create strided access
    for (y = sliceh_start; y < sliceh_end; y++) {
        // Process x in reverse with stride to alter spatial locality
        for (x = src_w - 1; x >= 0; x -= stride) {
            // Handle multiple points within the stride window to maintain coverage
            for (int step = 0; step < stride && (x - step) >= 0; step++) {
                const int adjusted_x = x - step;
                const int c0 = c0_data[adjusted_x >> c0_shift_w];
                const int c1 = c1_data[adjusted_x >> c1_shift_w];
                const int c2 = c2_data[adjusted_x >> c2_shift_w];

                const ptrdiff_t write_offset = mirror ? -c0 : c0;

                *(d0_data + write_offset) = c0;
                *(d1_data + write_offset) = c1;
                *(d2_data + write_offset) = c2;
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
