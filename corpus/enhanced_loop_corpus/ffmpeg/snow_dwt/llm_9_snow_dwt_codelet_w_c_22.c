#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int type;
extern int s;
extern int i;
extern int j;
extern  int dec_count;
extern int tmp[1024];
extern int level;
extern int ori;
extern  int scale[2][2][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (level = 0; level < dec_count; level++) {
    int shift_level = dec_count - level;
    int base_stride = 32 << shift_level;
    for (ori = level ? 1 : 0; ori < 4; ori += 2) {
        int size = w >> shift_level;
        int sx = (ori & 1) ? size : 0;
        int sy = (ori & 2) ? base_stride >> 1 : 0;
        int factor = scale[type][shift_level - 3][level][ori];
        int inner_size = size >> 1;
        for (i = 0; i < inner_size; i++) {
            int offset_row = sx + sy + i * 2 * base_stride;
            for (j = 0; j < size; j++) {
                int index = offset_row + j;
                int v = tmp[index] * factor;
                s += (v >= 0) ? v : -v;
            }
        }
    }
}
}
