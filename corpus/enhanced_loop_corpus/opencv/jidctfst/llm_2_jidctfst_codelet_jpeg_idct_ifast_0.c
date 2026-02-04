#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef JLONG DCTELEM;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef JLONG IFAST_MULT_TYPE;

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
    if (inptr[0] == 0 && inptr[16] == 0 && inptr[24] == 0 && inptr[32] == 0 && inptr[40] == 0 && inptr[48] == 0 && inptr[56] == 0) {
        int dcval = (int)(((inptr[0]) * (quantptr[0])) >> 12);
        wsptr[0] = dcval;
        wsptr[8] = dcval;
        wsptr[16] = dcval;
        wsptr[24] = dcval;
        wsptr[32] = dcval;
        wsptr[40] = dcval;
        wsptr[48] = dcval;
        wsptr[56] = dcval;
        inptr += 8;
        quantptr += 8;
        wsptr++;
        continue;
    }
    tmp0 = (((inptr[0]) * (quantptr[0])) >> 12);
    tmp1 = (((inptr[16]) * (quantptr[16])) >> 12);
    tmp2 = (((inptr[32]) * (quantptr[32])) >> 12);
    tmp3 = (((inptr[48]) * (quantptr[48])) >> 12);
    tmp10 = tmp0 + tmp2;
    tmp11 = tmp0 - tmp2;
    tmp13 = tmp1 + tmp3;
    tmp12 = ((DCTELEM)(((tmp1 - tmp3) * (((JLONG)362))) >> 8)) - tmp13;
    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;
    tmp4 = (((inptr[8]) * (quantptr[8])) >> 12);
    tmp5 = (((inptr[24]) * (quantptr[24])) >> 12);
    tmp6 = (((inptr[40]) * (quantptr[40])) >> 12);
    tmp7 = (((inptr[56]) * (quantptr[56])) >> 12);
    z13 = tmp6 + tmp5;
    z10 = tmp6 - tmp5;
    z11 = tmp4 + tmp7;
    z12 = tmp4 - tmp7;
    tmp7 = z11 + z13;
    tmp11 = ((DCTELEM)(((z11 - z13) * (((JLONG)362))) >> 8));
    z5 = ((DCTELEM)(((z10 + z12) * (((JLONG)473))) >> 8));
    tmp10 = ((DCTELEM)(((z12) * (((JLONG)277))) >> 8)) - z5;
    tmp12 = ((DCTELEM)(((z10) * (-((JLONG)669))) >> 8)) + z5;
    tmp6 = tmp12 - tmp7;
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;
    wsptr[0] = (int)(tmp0 + tmp7);
    wsptr[56] = (int)(tmp0 - tmp7);
    wsptr[8] = (int)(tmp1 + tmp6);
    wsptr[48] = (int)(tmp1 - tmp6);
    wsptr[16] = (int)(tmp2 + tmp5);
    wsptr[40] = (int)(tmp2 - tmp5);
    wsptr[32] = (int)(tmp3 + tmp4);
    wsptr[24] = (int)(tmp3 - tmp4);
    inptr += 8;
    quantptr += 8;
    wsptr++;
}
}
