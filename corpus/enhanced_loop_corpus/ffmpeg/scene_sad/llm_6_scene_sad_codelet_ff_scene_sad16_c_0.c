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
    uint64_t local_sad = 0;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int16_t diff = src1w[x] - src2w[x];
            local_sad += (diff >= 0) ? diff : -diff;
        }
        src1w += stride1;
        src2w += stride2;
    }
    sad += local_sad;
}
