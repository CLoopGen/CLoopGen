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
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    if (dataptr[8 * 0] == dataptr[8 * 7]) {
        tmp0 = dataptr[8 * 0] << 1;
        tmp7 = 0;
    } else {
        tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
        tmp7 = dataptr[8 * 0] - dataptr[8 * 7];
    }
    if (dataptr[8 * 1] <= dataptr[8 * 6]) {
        tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
        tmp6 = -(dataptr[8 * 6] - dataptr[8 * 1]);
    } else {
        tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
        tmp6 = dataptr[8 * 1] - dataptr[8 * 6];
    }
    tmp2 = dataptr[8 * 2] + dataptr[8 * 5];
    tmp5 = dataptr[8 * 2] - dataptr[8 * 5];
    tmp3 = dataptr[8 * 3] + dataptr[8 * 4];
    tmp4 = dataptr[8 * 3] - dataptr[8 * 4];
    tmp10 = tmp0 + tmp3;
    tmp13 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp12 = tmp1 - tmp2;
    dataptr[8 * 0] = tmp10 + tmp11;
    dataptr[8 * 4] = tmp10 - tmp11;
    z1 = ((DCTELEM)(((tmp12 + tmp13) * (((INT32)181))) >> (8)));
    dataptr[8 * 2] = tmp13 + z1;
    dataptr[8 * 6] = tmp13 - z1;
    tmp10 = tmp4 + tmp5;
    tmp11 = tmp5 + tmp6;
    tmp12 = tmp6 + tmp7;
    z5 = ((DCTELEM)(((tmp10 - tmp12) * (((INT32)98))) >> (8)));
    z2 = ((DCTELEM)(((tmp10) * (((INT32)139))) >> (8))) + z5;
    z4 = ((DCTELEM)(((tmp12) * (((INT32)334))) >> (8))) + z5;
    z3 = ((DCTELEM)(((tmp11) * (((INT32)181))) >> (8)));
    z11 = tmp7 + z3;
    z13 = tmp7 - z3;
    dataptr[8 * 5] = z13 + z2;
    dataptr[8 * 3] = z13 - z2;
    dataptr[8 * 1] = z11 + z4;
    dataptr[8 * 7] = z11 - z4;
    dataptr++;
}
}
