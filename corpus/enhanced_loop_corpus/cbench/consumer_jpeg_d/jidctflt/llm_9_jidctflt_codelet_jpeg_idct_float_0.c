#include <stdio.h>

#include <inttypes.h>

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
    tmp0 = (((float)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp1 = (((float)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp2 = (((float)(inptr[8 * 4])) * (quantptr[8 * 4]));
    tmp3 = (((float)(inptr[8 * 6])) * (quantptr[8 * 6]));
    tmp10 = tmp0 + tmp2;
    tmp11 = tmp0 - tmp2;
    tmp13 = tmp1 + tmp3;
    tmp12 = (tmp1 - tmp3) * ((float)1.414213562) - tmp13;
    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;
    tmp4 = (((float)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp5 = (((float)(inptr[8 * 3])) * (quantptr[8 * 3]));
    tmp6 = (((float)(inptr[8 * 5])) * (quantptr[8 * 5]));
    tmp7 = (((float)(inptr[8 * 7])) * (quantptr[8 * 7]));
    z13 = tmp6 + tmp5;
    z10 = tmp6 - tmp5;
    z11 = tmp4 + tmp7;
    z12 = tmp4 - tmp7;
    tmp7 = z11 + z13;
    tmp11 = (z11 - z13) * ((float)1.414213562);
    z5 = (z10 + z12) * ((float)1.847759065);
    tmp10 = ((float)1.0823921999999999) * z12 - z5;
    tmp12 = ((float)-2.6131259299999998) * z10 + z5;
    tmp6 = tmp12 - tmp7;
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;
    wsptr[8 * 0] = tmp0 + tmp7;
    wsptr[8 * 7] = tmp0 - tmp7;
    wsptr[8 * 1] = tmp1 + tmp6;
    wsptr[8 * 6] = tmp1 - tmp6;
    wsptr[8 * 2] = tmp2 + tmp5;
    wsptr[8 * 5] = tmp2 - tmp5;
    wsptr[8 * 4] = tmp3 + tmp4;
    wsptr[8 * 3] = tmp3 - tmp4;
    inptr++;
    quantptr++;
    wsptr++;
    ctr--; 
    if (ctr <= 0) break;
    tmp0 = (((float)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp1 = (((float)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp2 = (((float)(inptr[8 * 4])) * (quantptr[8 * 4]));
    tmp3 = (((float)(inptr[8 * 6])) * (quantptr[8 * 6]));
    tmp10 = tmp0 + tmp2;
    tmp11 = tmp0 - tmp2;
    tmp13 = tmp1 + tmp3;
    tmp12 = (tmp1 - tmp3) * ((float)1.414213562) - tmp13;
    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;
    tmp4 = (((float)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp5 = (((float)(inptr[8 * 3])) * (quantptr[8 * 3]));
    tmp6 = (((float)(inptr[8 * 5])) * (quantptr[8 * 5]));
    tmp7 = (((float)(inptr[8 * 7])) * (quantptr[8 * 7]));
    z13 = tmp6 + tmp5;
    z10 = tmp6 - tmp5;
    z11 = tmp4 + tmp7;
    z12 = tmp4 - tmp7;
    tmp7 = z11 + z13;
    tmp11 = (z11 - z13) * ((float)1.414213562);
    z5 = (z10 + z12) * ((float)1.847759065);
    tmp10 = ((float)1.0823921999999999) * z12 - z5;
    tmp12 = ((float)-2.6131259299999998) * z10 + z5;
    tmp6 = tmp12 - tmp7;
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;
    wsptr[8 * 0] = tmp0 + tmp7;
    wsptr[8 * 7] = tmp0 - tmp7;
    wsptr[8 * 1] = tmp1 + tmp6;
    wsptr[8 * 6] = tmp1 - tmp6;
    wsptr[8 * 2] = tmp2 + tmp5;
    wsptr[8 * 5] = tmp2 - tmp5;
    wsptr[8 * 4] = tmp3 + tmp4;
    wsptr[8 * 3] = tmp3 - tmp4;
    inptr++;
    quantptr++;
    wsptr++;
}

}
