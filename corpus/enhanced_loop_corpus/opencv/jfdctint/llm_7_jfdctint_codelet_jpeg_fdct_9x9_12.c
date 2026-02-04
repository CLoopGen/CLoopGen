#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

typedef int DCTELEM;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp4;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern INT32 z2;
extern DCTELEM workspace[8];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (;;) {
    elemptr = sample_data[ctr] + start_col;

    // Combine loads into a local array to eliminate repeated memory access and change data flow
    JSAMPLE local[9];
    for (int i = 0; i < 9; i++) {
        local[i] = elemptr[i];
    }

    // Eliminate redundant casts and pre-convert to int to reduce expression-level dependencies
    int l0 = local[0], l1 = local[1], l2 = local[2], l3 = local[3], l4 = local[4], l5 = local[5], l6 = local[6], l7 = local[7], l8 = local[8];

    // Remove some intermediate variables to create stronger loop-carried dependence on tmp usage
    INT32 sum08 = l0 + l8;
    INT32 sum17 = l1 + l7;
    INT32 sum26 = l2 + l6;
    INT32 sum35 = l3 + l5;

    INT32 diff08 = l0 - l8;
    INT32 diff17 = l1 - l7;
    INT32 diff26 = l2 - l6;
    INT32 diff35 = l3 - l5;

    // Fuse computations of z1 and z2 directly into output assignments to remove WAW on z1/z2
    dataptr[0] = (DCTELEM)((((sum08 + sum26 + sum35) + (sum17 + l4) - 9 * 128)) << 1);

    INT32 base_factor = (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5)));
    dataptr[6] = (DCTELEM)((((sum08 + sum26 + sum35 - 2*(sum17 + l4)) * base_factor) + ((INT32)1 << 11)) >> 12);

    // Inline multiplications to increase arithmetic intensity and remove temporary storage
    INT32 termA = (sum08 - sum26) * ((INT32)((1.3289260490000001) * ((INT32)1 << 13) + 0.5));
    INT32 termB = (sum17 - 2*l4) * base_factor;
    INT32 coefC1 = ((INT32)((1.0833504410000001) * ((INT32)1 << 13) + 0.5));
    INT32 coefC2 = ((INT32)((0.245575608) * ((INT32)1 << 13) + 0.5));

    dataptr[2] = (DCTELEM)((((sum26 - sum35) * coefC1 + termA + termB) + ((INT32)1 << 11)) >> 12);
    dataptr[4] = (DCTELEM)((((sum35 - sum08) * coefC2 + termA - termB) + ((INT32)1 << 11)) >> 12);

    // Strengthen loop-carried dependence by reusing diff values in cumulative way
    static INT32 accum_diff = 0;  // Introduce loop-carried state (WAR dependency across iterations)
    accum_diff += diff08 + diff17 + diff26 + diff35;
    INT32 adjusted_diff = diff08 - diff26 - diff35 + (accum_diff & 0x7); // Light dependence on prior iteration

    INT32 factor122 = ((INT32)((1.224744871) * ((INT32)1 << 13) + 0.5));
    dataptr[3] = (DCTELEM)(((adjusted_diff * factor122) + ((INT32)1 << 11)) >> 12);

    // Reuse transformed values with modified order to alter pipeline behavior
    INT32 d11 = diff17 * factor122;
    INT32 d02 = (diff08 + diff26) * ((INT32)((0.90903895499999998) * ((INT32)1 << 13) + 0.5));
    INT32 d03 = (diff08 + diff35) * ((INT32)((0.48368952500000001) * ((INT32)1 << 13) + 0.5));
    INT32 d23 = (diff26 - diff35) * ((INT32)((1.392728481) * ((INT32)1 << 13) + 0.5));

    dataptr[1] = (DCTELEM)(((d11 + d02 + d03) + ((INT32)1 << 11)) >> 12);
    dataptr[5] = (DCTELEM)(((d02 - d11 - d23) + ((INT32)1 << 11)) >> 12);
    dataptr[7] = (DCTELEM)(((d03 - d11 + d23) + ((INT32)1 << 11)) >> 12);

    ctr++;
    if (ctr != 8) {
        if (ctr == 9)
            break;
        dataptr += 8;
    } else
        dataptr = workspace;
}
}
