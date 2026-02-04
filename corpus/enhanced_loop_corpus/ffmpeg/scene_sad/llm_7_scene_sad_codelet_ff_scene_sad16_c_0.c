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
    uint64_t temp_sad = sad;
    for (y = 0; y < height; y++) {
        uint64_t row_sad = 0;
        for (x = 0; x < width; x++) {
            uint16_t a = src1w[x];
            uint16_t b = src2w[x];
            row_sad += (a > b) ? (a - b) : (b - a);
        }
        temp_sad += row_sad;
        src1w += stride1;
        src2w += stride2;
    }
    sad = temp_sad;
}
