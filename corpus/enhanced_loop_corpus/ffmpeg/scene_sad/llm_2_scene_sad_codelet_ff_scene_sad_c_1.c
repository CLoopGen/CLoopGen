#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern ptrdiff_t stride1;
extern  uint8_t *src2;
extern ptrdiff_t stride2;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern uint64_t sad;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    uint8_t *s1 = src1;
    uint8_t *s2 = src2;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width - 1; x += 2) {
            int diff1 = s1[x] - s2[x];
            int diff2 = s1[x+1] - s2[x+1];
            sad += (diff1 >= 0 ? diff1 : -diff1);
            sad += (diff2 >= 0 ? diff2 : -diff2);
        }
        if (x < width) {
            int diff = s1[x] - s2[x];
            sad += (diff >= 0 ? diff : -diff);
        }
        s1 += stride1;
        s2 += stride2;
    }
}
