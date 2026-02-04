#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef JLONG DCTELEM;

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



void loop() {
    for (ctr = 0; ctr < 8; ctr++) {
        DCTELEM *base_ptr = dataptr + (7 - ctr) * 8; // Reverse row access: now traversing from last to first row via positive index
        tmp0 = base_ptr[0] + base_ptr[7];
        tmp7 = base_ptr[0] - base_ptr[7];
        tmp1 = base_ptr[1] + base_ptr[6];
        tmp6 = base_ptr[1] - base_ptr[6];
        tmp2 = base_ptr[2] + base_ptr[5];
        tmp5 = base_ptr[2] - base_ptr[5];
        tmp3 = base_ptr[3] + base_ptr[4];
        tmp4 = base_ptr[3] - base_ptr[4];
        tmp10 = tmp0 + tmp3;
        tmp13 = tmp0 - tmp3;
        tmp11 = tmp1 + tmp2;
        tmp12 = tmp1 - tmp2;
        base_ptr[0] = tmp10 + tmp11;
        base_ptr[4] = tmp10 - tmp11;
        z1 = ((DCTELEM)(((tmp12 + tmp13) * (((JLONG)181))) >> (8)));
        base_ptr[2] = tmp13 + z1;
        base_ptr[6] = tmp13 - z1;
        tmp10 = tmp4 + tmp5;
        tmp11 = tmp5 + tmp6;
        tmp12 = tmp6 + tmp7;
        z5 = ((DCTELEM)(((tmp10 - tmp12) * (((JLONG)98))) >> (8)));
        z2 = ((DCTELEM)(((tmp10) * (((JLONG)139))) >> (8))) + z5;
        z4 = ((DCTELEM)(((tmp12) * (((JLONG)334))) >> (8))) + z5;
        z3 = ((DCTELEM)(((tmp11) * (((JLONG)181))) >> (8)));
        z11 = tmp7 + z3;
        z13 = tmp7 - z3;
        base_ptr[5] = z13 + z2;
        base_ptr[3] = z13 - z2;
        base_ptr[1] = z11 + z4;
        base_ptr[7] = z11 - z4;
    }
}
