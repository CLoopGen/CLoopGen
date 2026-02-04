#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern ptrdiff_t dpitch;
extern  int16_t *ref_buf;
extern ptrdiff_t pitch;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every second element, then handle remainder (modified access pattern)
    // Simulate strided traversal by accessing non-consecutive indices (stride of 2), with bounds check
    for (i = 0; i < 4; i++, buf += dpitch, ref_buf += pitch) {
        for (j = 0; j < 4; j += 2) {  // Stride-2 access on inner loop
            if (j + 1 < 4) {
                buf[j] += ((ref_buf[j] + ref_buf[j + 1]) >> 1);
                // Handle next element in stride separately if needed
                if (j + 2 < 4) {
                    buf[j + 2] += ((ref_buf[j + 2] + ref_buf[j + 3]) >> 1);
                }
            } else {
                buf[j] += ((ref_buf[j] + ref_buf[j + 1]) >> 1); // Fallback for boundary
            }
        }
    }
}
