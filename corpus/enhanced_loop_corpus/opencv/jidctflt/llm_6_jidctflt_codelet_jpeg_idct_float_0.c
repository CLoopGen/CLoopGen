#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef float FLOAT_MULT_TYPE;

extern float tmp0;
extern float tmp1;
extern float tmp2;
extern float tmp3;
extern float tmp4;
extern float tmp5;
extern float tmp6;
extern float tmp7;
extern float tmp10;
extern float tmp11;
extern float tmp12;
extern float tmp13;
extern float z5;
extern float z10;
extern float z11;
extern float z12;
extern float z13;
extern JCOEFPTR inptr;
extern FLOAT_MULT_TYPE *quantptr;
extern float *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8; ctr > 0; ctr--) {
    float dcval = (((float)(inptr[8 * 0])) * (quantptr[8 * 0] * ((FLOAT_MULT_TYPE)0.125)));
    int all_zero = (inptr[8 * 1] == 0) & (inptr[8 * 2] == 0) & (inptr[8 * 3] == 0) &
                   (inptr[8 * 4] == 0) & (inptr[8 * 5] == 0) & (inptr[8 * 6] == 0) & (inptr[8 * 7] == 0);
    
    tmp0 = dcval;
    tmp1 = all_zero ? 0.0f : (((float)(inptr[8 * 2])) * (quantptr[8 * 2] * ((FLOAT_MULT_TYPE)0.125)));
    tmp2 = all_zero ? 0.0f : (((float)(inptr[8 * 4])) * (quantptr[8 * 4] * ((FLOAT_MULT_TYPE)0.125)));
    tmp3 = all_zero ? 0.0f : (((float)(inptr[8 * 6])) * (quantptr[8 * 6] * ((FLOAT_MULT_TYPE)0.125)));

    tmp10 = tmp0 + tmp2;
    tmp11 = tmp0 - tmp2;
    tmp13 = tmp1 + tmp3;
    tmp12 = (tmp1 - tmp3) * ((float)1.414213562) - tmp13;

    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;

    tmp4 = all_zero ? 0.0f : (((float)(inptr[8 * 1])) * (quantptr[8 * 1] * ((FLOAT_MULT_TYPE)0.125)));
    tmp5 = all_zero ? 0.0f : (((float)(inptr[8 * 3])) * (quantptr[8 * 3] * ((FLOAT_MULT_TYPE)0.125)));
    tmp6 = all_zero ? 0.0f : (((float)(inptr[8 * 5])) * (quantptr[8 * 5] * ((FLOAT_MULT_TYPE)0.125)));
    tmp7 = all_zero ? 0.0f : (((float)(inptr[8 * 7])) * (quantptr[8 * 7] * ((FLOAT_MULT_TYPE)0.125)));

    z13 = tmp6 + tmp5;
    z10 = tmp6 - tmp5;
    z11 = tmp4 + tmp7;
    z12 = tmp4 - tmp7;

    tmp7 = z11 + z13;
    tmp11 = (z11 - z13) * ((float)1.414213562);
    z5 = (z10 + z12) * ((float)1.847759065);

    tmp10 = z5 - z12 * ((float)1.0823921999999999);
    tmp12 = z5 - z10 * ((float)2.6131259299999998);

    tmp6 = tmp12 - tmp7;
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 - tmp5;

    wsptr[8 * 0] = tmp0 + tmp7;
    wsptr[8 * 7] = tmp0 - tmp7;
    wsptr[8 * 1] = tmp1 + tmp6;
    wsptr[8 * 6] = tmp1 - tmp6;
    wsptr[8 * 2] = tmp2 + tmp5;
    wsptr[8 * 5] = tmp2 - tmp5;
    wsptr[8 * 3] = tmp3 + tmp4;
    wsptr[8 * 4] = tmp3 - tmp4;

    if (all_zero) {
        wsptr[8 * 0] = dcval;
        wsptr[8 * 1] = dcval;
        wsptr[8 * 2] = dcval;
        wsptr[8 * 3] = dcval;
        wsptr[8 * 4] = dcval;
        wsptr[8 * 5] = dcval;
        wsptr[8 * 6] = dcval;
        wsptr[8 * 7] = dcval;
    }

    inptr++;
    quantptr++;
    wsptr++;
}
}
