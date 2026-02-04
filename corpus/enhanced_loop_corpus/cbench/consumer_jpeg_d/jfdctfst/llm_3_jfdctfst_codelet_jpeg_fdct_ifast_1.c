#include <stdio.h>

#include <inttypes.h>

typedef int DCTELEM;

typedef long INT32;

extern DCTELEM tmp0;
extern DCTELEM tmp1;
extern DCTELEM tmp2;
extern DCTELEM tmp3;
extern DCTELEM tmp4;
extern DCTELEM tmp5;
extern DCTELEM tmp6;
extern DCTELEM tmp7;
extern DCTELEM tmp10;
extern DCTELEM tmp11;
extern DCTELEM tmp12;
extern DCTELEM tmp13;
extern DCTELEM z1;
extern DCTELEM z2;
extern DCTELEM z3;
extern DCTELEM z4;
extern DCTELEM z5;
extern DCTELEM z11;
extern DCTELEM z13;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
DCTELEM *indices[] = {dataptr + 0, dataptr + 8, dataptr + 16, dataptr + 24,
                      dataptr + 32, dataptr + 40, dataptr + 48, dataptr + 56};
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    tmp0 = indices[0][ctr] + indices[7][ctr];
    tmp7 = indices[0][ctr] - indices[7][ctr];
    tmp1 = indices[1][ctr] + indices[6][ctr];
    tmp6 = indices[1][ctr] - indices[6][ctr];
    tmp2 = indices[2][ctr] + indices[5][ctr];
    tmp5 = indices[2][ctr] - indices[5][ctr];
    tmp3 = indices[3][ctr] + indices[4][ctr];
    tmp4 = indices[3][ctr] - indices[4][ctr];
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    indices[0][ctr] = tmp10 + tmp11;
    indices[4][ctr] = tmp10 - tmp11;
    z1 = ((DCTELEM)(((tmp12 + tmp13) * (((INT32)181))) >> (8)));
    indices[2][ctr] = tmp13 + z1;
    indices[6][ctr] = tmp13 - z1;
    tmp10 = tmp4 + tmp5;
    tmp11 = tmp5 + tmp6;
    tmp12 = tmp6 + tmp7;
    z5 = ((DCTELEM)(((tmp10 - tmp12) * (((INT32)98))) >> (8)));
    z2 = ((DCTELEM)(((tmp10) * (((INT32)139))) >> (8))) + z5;
    z4 = ((DCTELEM)(((tmp12) * (((INT32)334))) >> (8))) + z5;
    z3 = ((DCTELEM)(((tmp11) * (((INT32)181))) >> (8)));
    z11 = tmp7 + z3;
    z13 = tmp7 - z3;
    indices[5][ctr] = z13 + z2;
    indices[3][ctr] = z13 - z2;
    indices[1][ctr] = z11 + z4;
    indices[7][ctr] = z11 - z4;
}
}
