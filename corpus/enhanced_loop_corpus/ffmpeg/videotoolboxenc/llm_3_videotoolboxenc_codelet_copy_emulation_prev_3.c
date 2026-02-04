#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int zeros;
extern uint8_t *dst_end;
extern  uint8_t *src_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather/scatter) access using index array
    // Use an auxiliary index array to define non-sequential access order
    // Simulate indirect access by iterating through a precomputed index sequence

    // Create a local index mapping: reverse order access within bounds
    ptrdiff_t len = src_end - src;
    ptrdiff_t i;

    // Process elements in reverse order (indirect-like access via reversed indices)
    for (i = len - 1; i >= 0; i--) {
        uint8_t *s = src + i;
        uint8_t *d = dst + i;

        if (s >= src_end) continue;

        if (zeros == 2) {
            int insert_ep3_byte = *s <= 3;
            if (insert_ep3_byte) {
                if (d < dst_end)
                    *d = 3;
                d++;
                if (d >= dst_end) break;
            }
            zeros = 0;
        }
        if (d < dst_end)
            *d = *s;
        if (!*s)
            zeros++;
        else
            zeros = 0;
    }

    // Update global pointers to reflect full advancement
    src = src_end;
    dst = (dst + len) > dst_end ? dst_end : (dst + len);
}
