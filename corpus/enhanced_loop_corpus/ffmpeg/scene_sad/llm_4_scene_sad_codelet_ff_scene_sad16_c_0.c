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
for (y = 0; y < height; y++) {
    for (x = 0; x < width; x++) {
        int16_t diff = src1w[x] - src2w[x];
        if (diff >= 0) {
            sad += diff;
        } else {
            sad -= diff;
        }
    }
    src1w += stride1;
    src2w += stride2;
}
}
