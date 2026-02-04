#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    const uint8_t* base_src = src1;
    tmp[0] = 0 * base_src[-2] + -7 * base_src[-1] + 42 * base_src[0] + 96 * base_src[1] + -2 * base_src[2] + -1 * base_src[3];
    tmp[1] = 0 * base_src[-1] + -7 * base_src[0] + 42 * base_src[1] + 96 * base_src[2] + -2 * base_src[3] + -1 * base_src[4];
    tmp[2] = 0 * base_src[0] + -7 * base_src[1] + 42 * base_src[2] + 96 * base_src[3] + -2 * base_src[4] + -1 * base_src[5];
    tmp[3] = 0 * base_src[1] + -7 * base_src[2] + 42 * base_src[3] + 96 * base_src[4] + -2 * base_src[5] + -1 * base_src[6];
    tmp[4] = 0 * base_src[2] + -7 * base_src[3] + 42 * base_src[4] + 96 * base_src[5] + -2 * base_src[6] + -1 * base_src[7];
    tmp[5] = 0 * base_src[3] + -7 * base_src[4] + 42 * base_src[5] + 96 * base_src[6] + -2 * base_src[7] + -1 * base_src[8];
    tmp[6] = 0 * base_src[4] + -7 * base_src[5] + 42 * base_src[6] + 96 * base_src[7] + -2 * base_src[8] + -1 * base_src[9];
    tmp[7] = 0 * base_src[5] + -7 * base_src[6] + 42 * base_src[7] + 96 * base_src[8] + -2 * base_src[9] + -1 * base_src[10];
    
    // Strided write pattern: simulate non-unit stride in temp buffer (e.g., padding or matrix row skip)
    tmp = (int16_t*)((uint8_t*)tmp + 8 * sizeof(int16_t));
    src1 += srcStride;
}
}
