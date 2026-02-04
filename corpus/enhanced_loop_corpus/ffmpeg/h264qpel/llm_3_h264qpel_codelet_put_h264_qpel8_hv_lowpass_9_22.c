#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    const int offsets[8][5] = {
        {0,1,-1,2,-2}, {1,2,0,3,-1}, {2,3,1,4,0}, {3,4,2,5,1},
        {4,5,3,6,2}, {5,6,4,7,3}, {6,7,5,8,4}, {7,8,6,9,5}
    };
    for (int j = 0; j < 8; j++) {
        tmp[j] = (src[offsets[j][0]] + src[offsets[j][1]]) * 20
               - (src[offsets[j][2]] + src[offsets[j][3]]) * 5
               + (src[offsets[j][4]] + src[offsets[j][3]+1]) + pad;
    }
    tmp += tmpStride;
    src += srcStride;
}
}
