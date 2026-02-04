#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 tmp26;
extern INT32 tmp27;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[8][8] = {
        {0, 8, 16, 24, 32, 40, 48, 56},
        {1, 9, 17, 25, 33, 41, 49, 57},
        {2, 10, 18, 26, 34, 42, 50, 58},
        {3, 11, 19, 27, 35, 43, 51, 59},
        {4, 12, 20, 28, 36, 44, 52, 60},
        {5, 13, 21, 29, 37, 45, 53, 61},
        {6, 14, 22, 30, 38, 46, 54, 62},
        {7, 15, 23, 31, 39, 47, 55, 63}
    };
    int w_indices[16] = {
        0, 8, 16, 24, 32, 40, 48, 56,
        63, 55, 47, 39, 31, 23, 15, 7
    };

    for (ctr = 0; ctr < 8; ctr++) {
        JCOEFPTR local_inptr = inptr + indices[ctr][0];
        ISLOW_MULT_TYPE *local_quantptr = quantptr + indices[ctr][0];
        int *local_wsptr = wsptr + w_indices[ctr];

        tmp0 = (((ISLOW_MULT_TYPE)(local_inptr[indices[ctr][0]])) * (local_quantptr[indices[ctr][0]]));
        tmp0 <<= 13;
        tmp0 += ((INT32)1) << (13 - 2 - 1);
        z1 = (((ISLOW_MULT_TYPE)(local_inptr[indices[ctr][4]])) * (local_quantptr[indices[ctr][4]]));
        tmp1 = ((z1) * (((INT32)((1.3065629649999999) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((z1) * (((INT32)4433)));
        tmp10 = tmp0 + tmp1;
        tmp11 = tmp0 - tmp1;
        tmp12 = tmp0 + tmp2;
        tmp13 = tmp0 - tmp2;
        z1 = (((ISLOW_MULT_TYPE)(local_inptr[indices[ctr][2]])) * (local_quantptr[indices[ctr][2]]));
        z2 = (((ISLOW_MULT_TYPE)(local_inptr[indices[ctr][6]])) * (local_quantptr[indices[ctr][6]]));
        z3 = z1 - z2;
        z4 = ((z3) * (((INT32)((0.275899379) * (((INT32)1) << 13) + 0.5))));
        z3 = ((z3) * (((INT32)((1.3870398450000001) * (((INT32)1) << 13) + 0.5))));
        tmp0 = z3 + ((z2) * (((INT32)20995)));
        tmp1 = z4 + ((z1) * (((INT32)7373)));
        tmp2 = z3 - ((z1) * (((INT32)((0.60134488699999999) * (((INT32)1) << 13) + 0.5))));
        tmp3 = z4 - ((z2) * (((INT32)((0.50979557900000005) * (((INT32)1) << 13) + 0.5))));
        tmp20 = tmp10 + tmp0;
        tmp27 = tmp10 - tmp0;
        tmp21 = tmp12 + tmp1;
        tmp26 = tmp12 - tmp1;
        tmp22 = tmp13 + tmp2;
        tmp25 = tmp13 - tmp2;
        tmp23 = tmp11 + tmp3;
        tmp24 = tmp11 - tmp3;
        z1 = (((ISLOW_MULT_TYPE)(local_inptr[indices[ctr][1]])) * (local_quantptr[indices[ctr][1]]));
        z2 = (((ISLOW_MULT_TYPE)(local_inptr[indices[ctr][3]])) * (local_quantptr[indices[ctr][3]]));
        z3 = (((ISLOW_MULT_TYPE)(local_inptr[indices[ctr][5]])) * (local_quantptr[indices[ctr][5]]));
        z4 = (((ISLOW_MULT_TYPE)(local_inptr[indices[ctr][7]])) * (local_quantptr[indices[ctr][7]]));
        tmp11 = z1 + z3;
        tmp1 = ((z1 + z2) * (((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5))));
        tmp2 = ((tmp11) * (((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
        tmp3 = ((z1 + z4) * (((INT32)((1.0932018670000001) * (((INT32)1) << 13) + 0.5))));
        tmp10 = ((z1 - z4) * (((INT32)((0.89716758600000002) * (((INT32)1) << 13) + 0.5))));
        tmp11 = ((tmp11) * (((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
        tmp12 = ((z1 - z2) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
        tmp0 = tmp1 + tmp2 + tmp3 - ((z1) * (((INT32)((2.2863411440000001) * (((INT32)1) << 13) + 0.5))));
        tmp13 = tmp10 + tmp11 + tmp12 - ((z1) * (((INT32)((1.835730603) * (((INT32)1) << 13) + 0.5))));
        z1 = ((z2 + z3) * (((INT32)((0.13861716900000001) * (((INT32)1) << 13) + 0.5))));
        tmp1 += z1 + ((z2) * (((INT32)((0.071888073999999996) * (((INT32)1) << 13) + 0.5))));
        tmp2 += z1 - ((z3) * (((INT32)((1.125726048) * (((INT32)1) << 13) + 0.5))));
        z1 = ((z3 - z2) * (((INT32)((1.407403738) * (((INT32)1) << 13) + 0.5))));
        tmp11 += z1 - ((z3) * (((INT32)((0.76636728200000004) * (((INT32)1) << 13) + 0.5))));
        tmp12 += z1 + ((z2) * (((INT32)((1.971951411) * (((INT32)1) << 13) + 0.5))));
        z2 += z4;
        z1 = ((z2) * (-((INT32)((0.66665565800000004) * (((INT32)1) << 13) + 0.5))));
        tmp1 += z1;
        tmp3 += z1 + ((z4) * (((INT32)((1.0653889620000001) * (((INT32)1) << 13) + 0.5))));
        z2 = ((z2) * (-((INT32)((1.247225013) * (((INT32)1) << 13) + 0.5))));
        tmp10 += z2 + ((z4) * (((INT32)((3.141271809) * (((INT32)1) << 13) + 0.5))));
        tmp12 += z2;
        z2 = ((z3 + z4) * (-((INT32)((1.3533180010000001) * (((INT32)1) << 13) + 0.5))));
        tmp2 += z2;
        tmp3 += z2;
        z2 = ((z4 - z3) * (((INT32)((0.410524528) * (((INT32)1) << 13) + 0.5))));
        tmp10 += z2;
        tmp11 += z2;

        local_wsptr[0] = (int)((tmp20 + tmp0) >> (13 - 2));
        local_wsptr[1] = (int)((tmp20 - tmp0) >> (13 - 2));
        local_wsptr[2] = (int)((tmp21 + tmp1) >> (13 - 2));
        local_wsptr[3] = (int)((tmp21 - tmp1) >> (13 - 2));
        local_wsptr[4] = (int)((tmp22 + tmp2) >> (13 - 2));
        local_wsptr[5] = (int)((tmp22 - tmp2) >> (13 - 2));
        local_wsptr[6] = (int)((tmp23 + tmp3) >> (13 - 2));
        local_wsptr[7] = (int)((tmp23 - tmp3) >> (13 - 2));
        local_wsptr[8] = (int)((tmp24 + tmp10) >> (13 - 2));
        local_wsptr[9] = (int)((tmp24 - tmp10) >> (13 - 2));
        local_wsptr[10] = (int)((tmp25 + tmp11) >> (13 - 2));
        local_wsptr[11] = (int)((tmp25 - tmp11) >> (13 - 2));
        local_wsptr[12] = (int)((tmp26 + tmp12) >> (13 - 2));
        local_wsptr[13] = (int)((tmp26 - tmp12) >> (13 - 2));
        local_wsptr[14] = (int)((tmp27 + tmp13) >> (13 - 2));
        local_wsptr[15] = (int)((tmp27 - tmp13) >> (13 - 2));

        inptr++;
        quantptr++;
        wsptr++;
    }
}
