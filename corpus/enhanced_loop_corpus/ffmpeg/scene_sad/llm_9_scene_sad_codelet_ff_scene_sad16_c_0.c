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
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            uint16_t a = src1w[x], b = src2w[x];
            sad += (a > b) ? (a - b) : (b - a);
        }
        src1w += stride1;
        src2w += stride2;
    }
}
