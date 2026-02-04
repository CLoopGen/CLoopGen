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
    for (x = 0; x < width; x++)
        sad += ((src1[x] - src2[x]) >= 0 ? (src1[x] - src2[x]) : (-(src1[x] - src2[x])));
    src1 += stride1;
    src2 += stride2;
}

}
