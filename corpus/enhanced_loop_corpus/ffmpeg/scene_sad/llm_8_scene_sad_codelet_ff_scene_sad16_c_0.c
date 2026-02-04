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
    ptrdiff_t y, x;
    for (y = 0; y < height; y += 2) {
        for (x = 0; x < width; x += 2) {
            int diff1 = src1w[x] - src2w[x];
            int diff2 = src1w[x+1] - src2w[x+1];
            int diff3 = src1w[stride1 + x] - src2w[stride2 + x];
            int diff4 = src1w[stride1 + x+1] - src2w[stride2 + x+1];
            sad += (diff1 >= 0 ? diff1 : -diff1);
            sad += (diff2 >= 0 ? diff2 : -diff2);
            sad += (diff3 >= 0 ? diff3 : -diff3);
            sad += (diff4 >= 0 ? diff4 : -diff4);
        }
        src1w += 2 * stride1;
        src2w += 2 * stride2;
    }
}
