#include <stdio.h>

#include <inttypes.h>

typedef int DCTELEM;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int IFAST_MULT_TYPE;

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
extern DCTELEM z5;
extern DCTELEM z10;
extern DCTELEM z11;
extern DCTELEM z12;
extern DCTELEM z13;
extern JCOEFPTR inptr;
extern IFAST_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8; ctr > 0; ctr--) {
    int non_zero_found = 0;
    if (inptr[8 * 1]) non_zero_found = 1;
    else if (inptr[8 * 2]) non_zero_found = 1;
    else if (inptr[8 * 3]) non_zero_found = 1;
    else if (inptr[8 * 4]) non_zero_found = 1;
    else if (inptr[8 * 5]) non_zero_found = 1;
    else if (inptr[8 * 6]) non_zero_found = 1;
    else if (inptr[8 * 7]) non_zero_found = 1;

    if (!non_zero_found) {
        int dcval = (int)(((IFAST_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        wsptr[8 * 0] = dcval;
        wsptr[8 * 1] = dcval;
        wsptr[8 * 2] = dcval;
        wsptr[8 * 3] = dcval;
        wsptr[8 * 4] = dcval;
        wsptr[8 * 5] = dcval;
        wsptr[8 * 6] = dcval;
        wsptr[8 * 7] = dcval;
        inptr++;
        quantptr++;
        wsptr++;
        continue;
    }

    tmp0 = (((IFAST_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp1 = (((IFAST_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp2 = (((IFAST_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    tmp3 = (((IFAST_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    tmp10 = tmp0 + tmp2;
    tmp11 = tmp0 - tmp2;
    tmp13 = tmp1 + tmp3;
    tmp12 = ((DCTELEM)(((tmp1 - tmp3) * (((INT32)362))) >> (8))) - tmp13;
    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;
    tmp4 = (((IFAST_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp5 = (((IFAST_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    tmp6 = (((IFAST_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
    tmp7 = (((IFAST_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
    z13 = tmp6 + tmp5;
    z10 = tmp6 - tmp5;
    z11 = tmp4 + tmp7;
    z12 = tmp4 - tmp7;
    tmp7 = z11 + z13;
    tmp11 = ((DCTELEM)(((z11 - z13) * (((INT32)362))) >> (8)));
    z5 = ((DCTELEM)(((z10 + z12) * (((INT32)473))) >> (8)));
    tmp10 = ((DCTELEM)(((z12) * (((INT32)277))) >> (8))) - z5;
    tmp12 = ((DCTELEM)(((z10) * (-((INT32)669))) >> (8))) + z5;
    tmp6 = tmp12 - tmp7;
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;
    wsptr[8 * 0] = (int)(tmp0 + tmp7);
    wsptr[8 * 7] = (int)(tmp0 - tmp7);
    wsptr[8 * 1] = (int)(tmp1 + tmp6);
    wsptr[8 * 6] = (int)(tmp1 - tmp6);
    wsptr[8 * 2] = (int)(tmp2 + tmp5);
    wsptr[8 * 5] = (int)(tmp2 - tmp5);
    wsptr[8 * 4] = (int)(tmp3 + tmp4);
    wsptr[8 * 3] = (int)(tmp3 - tmp4);
    inptr++;
    quantptr++;
    wsptr++;
}
}
