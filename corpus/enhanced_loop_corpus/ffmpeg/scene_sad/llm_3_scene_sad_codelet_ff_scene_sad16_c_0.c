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
    // Variant 2: Strided memory access with increased stride (access every 2nd element first, then offset)
    // This variant modifies the access pattern to a strided one by splitting the loop into even and odd phases,
    // effectively changing temporal and spatial access patterns to stress different cache behavior.
    ptrdiff_t phase, x_step;
    for (y = 0; y < height; y++) {
        for (phase = 0; phase < 2; phase++) {
            for (x = phase; x < width; x += 2) {
                int64_t diff = src1w[x] - src2w[x];
                sad += (diff >= 0 ? diff : -diff);
            }
        }
        src1w += stride1;
        src2w += stride2;
    }
}
