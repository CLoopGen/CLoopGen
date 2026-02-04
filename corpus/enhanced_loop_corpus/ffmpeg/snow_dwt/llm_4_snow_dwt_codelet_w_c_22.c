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
    int base_ori = (level == 0) ? 0 : 1;
    for (ori = base_ori; ori < 4; ori++) {
        int size = w >> (dec_count - level);
        int sx = (ori & 1) * size;
        int stride = 32 << (dec_count - level);
        int sy = (ori & 2) ? (stride >> 1) : 0;
        int offset;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                offset = sx + sy + i * stride + j;
                int v = tmp[offset] * scale[type][dec_count - 3][level][ori];
                if (v != 0) {
                    s += (v > 0) ? v : -v;
                }
            }
        }
    }
}
}
