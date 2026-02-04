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
for (level = 0; level < dec_count; level++)
    for (ori = level ? 1 : 0; ori < 4; ori++) {
        int size = w >> (dec_count - level);
        int sx = (ori & 1) ? size : 0;
        int stride = 32 << (dec_count - level);
        int sy = (ori & 2) ? stride >> 1 : 0;
        int factor = scale[type][dec_count - 3][level][ori];
        for (i = 0; i < size; i += 2)
            for (j = 0; j < size; j += 2) {
                int idx1 = sx + sy + i * stride + j;
                int idx2 = sx + sy + (i + 1) * stride + j;
                int idx3 = sx + sy + i * stride + (j + 1);
                int idx4 = sx + sy + (i + 1) * stride + (j + 1);
                int v1 = tmp[idx1] * factor;
                int v2 = tmp[idx2] * factor;
                int v3 = tmp[idx3] * factor;
                int v4 = tmp[idx4] * factor;
                s += ((v1) >= 0 ? (v1) : (-v1));
                s += ((v2) >= 0 ? (v2) : (-v2));
                s += ((v3) >= 0 ? (v3) : (-v3));
                s += ((v4) >= 0 ? (v4) : (-v4));
            }
    }
}
