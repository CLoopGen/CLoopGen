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
    // Variant 2: Strided memory access — process every 2nd element in two passes
    uint8_t *s1 = src1;
    uint8_t *s2 = src2;
    for (y = 0; y < height; y++) {
        // First pass: even indices
        for (x = 0; x < width; x += 2) {
            int diff = s1[x] - s2[x];
            sad += (diff >= 0 ? diff : -diff);
        }
        // Second pass: odd indices
        for (x = 1; x < width; x += 2) {
            int diff = s1[x] - s2[x];
            sad += (diff >= 0 ? diff : -diff);
        }
        s1 += stride1;
        s2 += stride2;
    }
}
