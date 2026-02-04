#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint8_t * src0;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int H;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access on src0 and transformed index arithmetic
    ptrdiff_t strided_offset = 1; // Simulate non-unit stride in access pattern
    for (k = 2; k <= 4; ++k) {
        src1 += stride;
        src2 -= stride;
        // Access src0 with artificial stride (e.g., every second valid index mapped via k)
        H += k * (src0[k * strided_offset] - src0[-k * strided_offset]);
        V += k * (src1[0] - src2[0]);
    }
}
