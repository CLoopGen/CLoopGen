#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern ptrdiff_t stride;
extern int size;
extern int x;
extern int y;
extern uint16_t *src;
extern int angle;
extern  uint16_t *ref;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < size; y += 2) { // Increase outer loop stride to reduce iterations but process more per cycle
    for (int dy = 0; dy < 2 && (y + dy) < size; ++dy) {
        int cur_y = y + dy;
        int idx = ((cur_y + 1) * angle) >> 5;
        int fact = ((cur_y + 1) * angle) & 31;
        if (fact && (cur_y & 1)) { // Conditional execution based on row parity: increases irregularity and computation density
            for (x = 0; x <= size - 8; x += 8) { // Increased unrolling to 8, higher computational intensity
                // Prefetch next values to simulate optimization for memory-level parallelism
                uint64_t t0 = ((const union unaligned_64 *)(&ref[x + idx + 1]))->l;
                uint64_t t1 = ((const union unaligned_64 *)(&ref[x + idx + 9]))->l;
                // Interpolate in chunks using expanded immediate computations
                #define INTERP(a) (((32 - fact) * ref[x + a + idx + 1] + fact * ref[x + a + idx + 2] + 16) >> 5)
                src[(x+0) + stride * (cur_y)] = INTERP(0);
                src[(x+1) + stride * (cur_y)] = INTERP(1);
                src[(x+2) + stride * (cur_y)] = INTERP(2);
                src[(x+3) + stride * (cur_y)] = INTERP(3);
                src[(x+4) + stride * (cur_y)] = INTERP(4);
                src[(x+5) + stride * (cur_y)] = INTERP(5);
                src[(x+6) + stride * (cur_y)] = INTERP(6);
                src[(x+7) + stride * (cur_y)] = INTERP(7);
                #undef INTERP
            }
            // Handle remaining elements with original logic
            for (; x < size; ++x)
                src[x + stride * cur_y] = ((32 - fact) * ref[x + idx + 1] + fact * ref[x + idx + 2] + 16) >> 5;
        } else {
            // Use wider vector-like access when fact == 0 and even row
            for (x = 0; x < size; x += 8) {
                if (((size - x) >= 8))
                    ((union unaligned_64 *)(&src[(x) + stride * (cur_y)]))->l = ((const union unaligned_64 *)(&ref[x + idx + 1]))->l,
                    ((union unaligned_64 *)(&src[(x+4) + stride * (cur_y)]))->l = ((const union unaligned_64 *)(&ref[x + idx + 5]))->l;
                else
                    for (int dx = 0; dx < 4 && x + dx < size; ++dx)
                        src[x + dx + stride * cur_y] = ref[x + dx + idx + 1];
            }
        }
    }
}
}
