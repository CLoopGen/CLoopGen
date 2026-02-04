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
const uint16_t **indirect_src = (const uint16_t**)malloc((h + 5) * sizeof(uint16_t*));
int16_t **indirect_tmp = (int16_t**)malloc((h + 5) * sizeof(int16_t*));
for (int j = 0; j < h + 5; j++) {
    indirect_src[j] = src + j * srcStride;
    indirect_tmp[j] = tmp + j * tmpStride;
}
for (i = 0; i < h + 5; i++) {
    indirect_tmp[i][0] = (indirect_src[i][0] + indirect_src[i][1]) * 20 - (indirect_src[i][-1] + indirect_src[i][2]) * 5 + (indirect_src[i][-2] + indirect_src[i][3]) + pad;
    indirect_tmp[i][1] = (indirect_src[i][1] + indirect_src[i][2]) * 20 - (indirect_src[i][0] + indirect_src[i][3]) * 5 + (indirect_src[i][-1] + indirect_src[i][4]) + pad;
}
free(indirect_src);
free(indirect_tmp);
}
