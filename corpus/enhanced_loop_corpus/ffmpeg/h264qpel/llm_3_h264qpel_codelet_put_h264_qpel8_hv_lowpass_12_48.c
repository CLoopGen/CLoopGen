#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    const int offsets[8][11] = {
        {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8},
        {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11},
        {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12},
        {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
        {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},
        {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
    };
    for (int j = 0; j < 8; j++) {
        int idx = offsets[j][j+2]; // Base index derived from pattern
        tmp[j] = (src[idx - j] + src[idx - j + 1]) * 20 
               - (src[idx - j - 1] + src[idx - j + 2]) * 5 
               + (src[idx - j - 2] + src[idx - j + 3]) + pad;
    }
    tmp += tmpStride;
    src += srcStride;
}
}
