#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array to simulate irregular strides
    // Use a fixed index map to simulate non-unit strided access, promoting flexibility
    static const int index_map[6][4] = {
        {0*4, 0*4, 0*4, 0*4}, // offset for filter[2]
        {-1*4, -1*4, -1*4, -1*4}, // offset for filter[1]
        {-2*4, -2*4, -2*4, -2*4}, // offset for filter[0]
        {1*4, 1*4, 1*4, 1*4},  // offset for filter[3]
        {2*4, 2*4, 2*4, 2*4},  // offset for filter[4]
        {3*4, 3*4, 3*4, 3*4}   // offset for filter[5]
    };
    for (y = 0; y < h; y++) {
        for (x = 0; x < 4; x++) {
            int sum = 0;
            sum += filter[2] * tmp[x + index_map[0][x]];
            sum -= filter[1] * tmp[x + index_map[1][x]];
            sum += filter[0] * tmp[x + index_map[2][x]];
            sum += filter[3] * tmp[x + index_map[3][x]];
            sum -= filter[4] * tmp[x + index_map[4][x]];
            sum += filter[5] * tmp[x + index_map[5][x]];
            dst[x] = cm[(sum + 64) >> 7];
        }
        dst += dststride;
        tmp += 4;
    }
}
