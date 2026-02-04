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
    uint64_t local_sad = 0;
    for (y = 0; y < height; y++) {
        uint64_t row_sad = 0;
        for (x = 0; x < width; x++) {
            int32_t diff = src1[x] - src2[x];
            row_sad += (diff >= 0) ? diff : -diff;
        }
        local_sad += row_sad;
        src1 += stride1;
        src2 += stride2;
    }
    sad = local_sad;
}
