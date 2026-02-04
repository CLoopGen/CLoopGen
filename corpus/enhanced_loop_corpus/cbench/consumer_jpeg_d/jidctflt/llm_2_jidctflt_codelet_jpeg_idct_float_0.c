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
    int offset = 8 * ctr;
    if ((inptr[offset - 8] | inptr[offset - 16] | inptr[offset - 24] | inptr[offset - 32] | 
         inptr[offset - 40] | inptr[offset - 48] | inptr[offset - 56]) == 0) {
        float dcval = (((float)(inptr[offset - 64])) * (quantptr[offset - 64]));
        wsptr[offset - 64] = dcval;
        wsptr[offset - 56] = dcval;
        wsptr[offset - 48] = dcval;
        wsptr[offset - 40] = dcval;
        wsptr[offset - 32] = dcval;
        wsptr[offset - 24] = dcval;
        wsptr[offset - 16] = dcval;
        wsptr[offset - 8] = dcval;
        inptr--;
        quantptr--;
        wsptr--;
        continue;
    }
    tmp0 = (((float)(inptr[offset - 64])) * (quantptr[offset - 64]));
    tmp1 = (((float)(inptr[offset - 48])) * (quantptr[offset - 48]));
    tmp2 = (((float)(inptr[offset - 32])) * (quantptr[offset - 32]));
    tmp3 = (((float)(inptr[offset - 16])) * (quantptr[offset - 16]));
    tmp10 = tmp0 + tmp2;
    tmp11 = tmp0 - tmp2;
    tmp13 = tmp1 + tmp3;
    tmp12 = (tmp1 - tmp3) * ((float)1.414213562) - tmp13;
    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;
    tmp4 = (((float)(inptr[offset - 56])) * (quantptr[offset - 56]));
    tmp5 = (((float)(inptr[offset - 40])) * (quantptr[offset - 40]));
    tmp6 = (((float)(inptr[offset - 24])) * (quantptr[offset - 24]));
    tmp7 = (((float)(inptr[offset - 8])) * (quantptr[offset - 8]));
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
    wsptr[offset - 64] = tmp0 + tmp7;
    wsptr[offset - 8] = tmp0 - tmp7;
    wsptr[offset - 56] = tmp1 + tmp6;
    wsptr[offset - 16] = tmp1 - tmp6;
    wsptr[offset - 48] = tmp2 + tmp5;
    wsptr[offset - 24] = tmp2 - tmp5;
    wsptr[offset - 32] = tmp3 + tmp4;
    wsptr[offset - 40] = tmp3 - tmp4;
    inptr--;
    quantptr--;
    wsptr--;
}
}
