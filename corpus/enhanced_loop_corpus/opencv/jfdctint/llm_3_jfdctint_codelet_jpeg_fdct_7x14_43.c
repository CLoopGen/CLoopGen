#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp4;
extern INT32 tmp5;
extern INT32 tmp6;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp16;
extern DCTELEM *dataptr;
extern DCTELEM *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (ctr = 0; ctr < 7; ctr++) {
        // Variant 2: Strided access with index remapping via pointer arithmetic offset table
        const int offsets[] = {0, 8, 16, 24, 32, 40, 48, 56}; // Stride of 8 elements

        tmp0 = dataptr[offsets[0]] + wsptr[offsets[5]];
        tmp1 = dataptr[offsets[1]] + wsptr[offsets[4]];
        tmp2 = dataptr[offsets[2]] + wsptr[offsets[3]];
        tmp13 = dataptr[offsets[3]] + wsptr[offsets[2]];
        tmp4 = dataptr[offsets[4]] + wsptr[offsets[1]];
        tmp5 = dataptr[offsets[5]] + wsptr[offsets[0]];
        tmp6 = dataptr[offsets[6]] + dataptr[offsets[7]];

        tmp10 = tmp0 + tmp6;
        tmp14 = tmp0 - tmp6;
        tmp11 = tmp1 + tmp5;
        tmp15 = tmp1 - tmp5;
        tmp12 = tmp2 + tmp4;
        tmp16 = tmp2 - tmp4;

        tmp0 = dataptr[offsets[0]] - wsptr[offsets[5]];
        tmp1 = dataptr[offsets[1]] - wsptr[offsets[4]];
        tmp2 = dataptr[offsets[2]] - wsptr[offsets[3]];
        tmp3 = dataptr[offsets[3]] - wsptr[offsets[2]];
        tmp4 = dataptr[offsets[4]] - wsptr[offsets[1]];
        tmp5 = dataptr[offsets[5]] - wsptr[offsets[0]];
        tmp6 = dataptr[offsets[6]] - dataptr[offsets[7]];

        dataptr[offsets[0]] = (DCTELEM)(((((tmp10 + tmp11 + tmp12 + tmp13) * (((INT32)((0.653061224) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        tmp13 += tmp13;
        dataptr[offsets[4]] = (DCTELEM)(((((tmp10 - tmp13) * (((INT32)((0.83210605199999998) * (((INT32)1) << 13) + 0.5)))) + ((tmp11 - tmp13) * (((INT32)((0.20551322299999999) * (((INT32)1) << 13) + 0.5)))) - ((tmp12 - tmp13) * (((INT32)((0.57583525499999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        tmp10 = ((tmp14 + tmp15) * (((INT32)((0.72207456999999997) * (((INT32)1) << 13) + 0.5))));
        dataptr[offsets[2]] = (DCTELEM)(((tmp10 + ((tmp14) * (((INT32)((0.17833769099999999) * (((INT32)1) << 13) + 0.5)))) + ((tmp16) * (((INT32)((0.400721155) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr[offsets[6]] = (DCTELEM)(((tmp10 - ((tmp15) * (((INT32)((1.122795725) * (((INT32)1) << 13) + 0.5)))) - ((tmp16) * (((INT32)((0.90041226200000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        tmp10 = tmp1 + tmp2;
        tmp11 = tmp5 - tmp4;
        dataptr[offsets[7]] = (DCTELEM)(((((tmp0 - tmp10 + tmp3 - tmp11 - tmp6) * (((INT32)((0.653061224) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        tmp3 = ((tmp3) * (((INT32)((0.653061224) * (((INT32)1) << 13) + 0.5))));
        tmp10 = ((tmp10) * (-((INT32)((0.103406812) * (((INT32)1) << 13) + 0.5))));
        tmp11 = ((tmp11) * (((INT32)((0.91776083900000005) * (((INT32)1) << 13) + 0.5))));
        tmp10 += tmp11 - tmp3;
        tmp11 = ((tmp0 + tmp2) * (((INT32)((0.78200740999999996) * (((INT32)1) << 13) + 0.5)))) + ((tmp4 + tmp6) * (((INT32)((0.49136782299999998) * (((INT32)1) << 13) + 0.5))));
        dataptr[offsets[5]] = (DCTELEM)(((tmp10 + tmp11 - ((tmp2) * (((INT32)((1.550341076) * (((INT32)1) << 13) + 0.5)))) + ((tmp4) * (((INT32)((0.73142820200000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        tmp12 = ((tmp0 + tmp1) * (((INT32)((0.87174047799999998) * (((INT32)1) << 13) + 0.5)))) + ((tmp5 - tmp6) * (((INT32)((0.30503518600000001) * (((INT32)1) << 13) + 0.5))));
        dataptr[offsets[3]] = (DCTELEM)(((tmp10 + tmp12 - ((tmp1) * (((INT32)((0.27696584400000002) * (((INT32)1) << 13) + 0.5)))) - ((tmp5) * (((INT32)((2.0048034349999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));
        dataptr[offsets[1]] = (DCTELEM)(((tmp11 + tmp12 + tmp3 - ((tmp0) * (((INT32)((0.735987049) * (((INT32)1) << 13) + 0.5)))) - ((tmp6) * (((INT32)((0.082925824999999995) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 + 2) - 1))) >> (13 + 2));

        dataptr++;
        wsptr++;
    }
}
