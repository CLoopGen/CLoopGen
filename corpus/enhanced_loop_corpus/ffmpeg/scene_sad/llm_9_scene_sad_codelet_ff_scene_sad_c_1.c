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
for (y = 0; y < height; y++) {
    for (x = 0; x < width; x += 4) {
        uint64_t diff1 = src1[x] - src2[x];
        uint64_t diff2 = (x+1 < width) ? (src1[x+1] - src2[x+1]) : 0;
        uint64_t diff3 = (x+2 < width) ? (src1[x+2] - src2[x+2]) : 0;
        uint64_t diff4 = (x+3 < width) ? (src1[x+3] - src2[x+3]) : 0;
        sad += (diff1 >= 0 ? diff1 : -diff1);
        sad += (x+1 < width) ? (diff2 >= 0 ? diff2 : -diff2) : 0;
        sad += (x+2 < width) ? (diff3 >= 0 ? diff3 : -diff3) : 0;
        sad += (x+3 < width) ? (diff4 >= 0 ? diff4 : -diff4) : 0;
    }
    src1 += stride1;
    src2 += stride2;
}
}
