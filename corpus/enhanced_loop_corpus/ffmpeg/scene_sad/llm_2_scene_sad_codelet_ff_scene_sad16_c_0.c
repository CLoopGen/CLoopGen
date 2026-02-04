#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride1;
extern ptrdiff_t stride2;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern uint64_t sad;
extern  uint16_t *src1w;
extern  uint16_t *src2w;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer pre-increment and loop unrolling (factor of 2)
    // This variant accesses memory consecutively by processing two elements per iteration to improve cache locality.
    ptrdiff_t i, j;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width - 1; x += 2) {
            int64_t diff1 = src1w[x] - src2w[x];
            int64_t diff2 = src1w[x + 1] - src2w[x + 1];
            sad += (diff1 >= 0 ? diff1 : -diff1);
            sad += (diff2 >= 0 ? diff2 : -diff2);
        }
        if (x < width) {
            int64_t diff = src1w[x] - src2w[x];
            sad += (diff >= 0 ? diff : -diff);
        }
        src1w += stride1;
        src2w += stride2;
    }
}
