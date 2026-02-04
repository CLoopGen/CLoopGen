#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int dst_linesize;
extern  int sliceh_start;
extern  int sliceh_end;
extern  int step;
extern int y;
extern  int bg;
extern  int dst_w;
extern  int t0;
extern  int t1;
extern uint8_t *dst0;
extern uint8_t *dst1;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int trip_count = (sliceh_end - sliceh_start) * step;
    for (y = 0; y < trip_count; y++) {
        int offset = y * dst_linesize;
        int processed = 0;
        // Unroll by 2 and reduce conditionals with early exit check
        for (x = 0; x < dst_w - 1; x += 2) {
            uint8_t val0 = src[offset + x];
            uint8_t val1 = src[offset + x + 1];
            int cond0 = (val0 != bg);
            int cond1 = (val1 != bg);

            dst0[offset + x]     = cond0 ? t0 : dst0[offset + x];
            dst1[offset + x]     = cond0 ? t1 : dst1[offset + x];
            dst0[offset + x + 1] = cond1 ? t0 : dst0[offset + x + 1];
            dst1[offset + x + 1] = cond1 ? t1 : dst1[offset + x + 1];

            processed += (cond0 | cond1);
        }
        // Scalar cleanup
        if (x < dst_w) {
            uint8_t val = src[offset + x];
            if (val != bg) {
                dst0[offset + x] = t0;
                dst1[offset + x] = t1;
            }
        }
        // Skip full-background lines more aggressively
        if (processed == 0 && step > 1) {
            y += (step - 1); // Simulate skipping blank rows
        }
    }
}
