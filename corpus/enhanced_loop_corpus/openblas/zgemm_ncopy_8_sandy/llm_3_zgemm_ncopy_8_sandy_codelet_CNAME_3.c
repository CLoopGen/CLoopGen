#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG stride = 2;
for (i = 0; i < row / 4; i += 1) {
    BLASLONG base_src = (i << 3);
    BLASLONG base_dst = i * (stride << 3);
    dest0[base_dst + 0*stride] = src0[base_src + 0];
    dest0[base_dst + 1*stride] = src0[base_src + 1];
    dest0[base_dst + 2*stride] = src0[base_src + 2];
    dest0[base_dst + 3*stride] = src0[base_src + 3];
    dest0[base_dst + 4*stride] = src0[base_src + 4];
    dest0[base_dst + 5*stride] = src0[base_src + 5];
    dest0[base_dst + 6*stride] = src0[base_src + 6];
    dest0[base_dst + 7*stride] = src0[base_src + 7];
}
}
