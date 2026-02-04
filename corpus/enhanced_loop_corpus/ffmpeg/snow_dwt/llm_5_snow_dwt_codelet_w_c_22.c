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
    int start_ori = 0;
    if (level > 0) {
        start_ori = 1;
    }
    for (ori = start_ori; ori < 4; ori++) {
        int shift = dec_count - level;
        int size = w >> shift;
        int stride = 32 << shift;
        int sx = (ori & 1) ? size : 0;
        int sy = (ori & 2) * (stride >> 1);
        int temp_val, abs_v;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                temp_val = tmp[sx + sy + i * stride + j];
                temp_val *= scale[type][dec_count - 3][level][ori];
                abs_v = temp_val;
                if (abs_v < 0) {
                    abs_v = -abs_v;
                }
                s += abs_v;
            }
        }
    }
}
}
