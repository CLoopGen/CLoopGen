#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int threshold;
extern int w;
extern  uint16_t *src;
extern  uint16_t *ref;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t diff;
    for (int x = 0; x < w; x += 2) {
        // Introduce WAW and RAW dependencies via grouped updates
        if (x + 1 < w) {
            // First element: compute and store with intermediate reuse
            diff = (src[x] >= ref[x]) ? (src[x] - ref[x]) : (ref[x] - src[x]);
            dst[x] = (diff <= threshold) ? src[x] : ref[x];

            // Second element depends on first write (artificial WAW-like dependency)
            diff = (src[x+1] >= ref[x+1]) ? (src[x+1] - ref[x+1]) : (ref[x+1] - src[x+1]);
            dst[x+1] = (diff <= threshold) ? src[x+1] : ref[x+1];
        } else {
            diff = (src[x] >= ref[x]) ? (src[x] - ref[x]) : (ref[x] - src[x]);
            dst[x] = (diff <= threshold) ? src[x] : ref[x];
        }
    }
}
