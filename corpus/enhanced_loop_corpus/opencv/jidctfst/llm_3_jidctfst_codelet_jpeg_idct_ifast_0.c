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
int indices[] = {0, 1, 2, 3, 4, 5, 6, 7};
for (ctr = 8; ctr > 0; ctr--) {
    int i0 = indices[0], i1 = indices[1], i2 = indices[2], i3 = indices[3],
        i4 = indices[4], i5 = indices[5], i6 = indices[6], i7 = indices[7];
    if (inptr[i1*8] == 0 && inptr[i2*8] == 0 && inptr[i3*8] == 0 && inptr[i4*8] == 0 &&
        inptr[i5*8] == 0 && inptr[i6*8] == 0 && inptr[i7*8] == 0) {
        int dcval = (int)(((inptr[i0*8]) * (quantptr[i0*8])) >> 12);
        wsptr[i0*8] = dcval;
        wsptr[i1*8] = dcval;
        wsptr[i2*8] = dcval;
        wsptr[i3*8] = dcval;
        wsptr[i4*8] = dcval;
        wsptr[i5*8] = dcval;
        wsptr[i6*8] = dcval;
        wsptr[i7*8] = dcval;
        inptr++;
        quantptr++;
        wsptr++;
        continue;
    }
    tmp0 = (((inptr[i0*8]) * (quantptr[i0*8])) >> 12);
    tmp1 = (((inptr[i2*8]) * (quantptr[i2*8])) >> 12);
    tmp2 = (((inptr[i4*8]) * (quantptr[i4*8])) >> 12);
    tmp3 = (((inptr[i6*8]) * (quantptr[i6*8])) >> 12);
    tmp10 = tmp0 + tmp2;
    tmp11 = tmp0 - tmp2;
    tmp13 = tmp1 + tmp3;
    tmp12 = ((DCTELEM)(((tmp1 - tmp3) * (((JLONG)362))) >> 8)) - tmp13;
    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;
    tmp4 = (((inptr[i1*8]) * (quantptr[i1*8])) >> 12);
    tmp5 = (((inptr[i3*8]) * (quantptr[i3*8])) >> 12);
    tmp6 = (((inptr[i5*8]) * (quantptr[i5*8])) >> 12);
    tmp7 = (((inptr[i7*8]) * (quantptr[i7*8])) >> 12);
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
    wsptr[i0*8] = (int)(tmp0 + tmp7);
    wsptr[i7*8] = (int)(tmp0 - tmp7);
    wsptr[i1*8] = (int)(tmp1 + tmp6);
    wsptr[i6*8] = (int)(tmp1 - tmp6);
    wsptr[i2*8] = (int)(tmp2 + tmp5);
    wsptr[i5*8] = (int)(tmp2 - tmp5);
    wsptr[i4*8] = (int)(tmp3 + tmp4);
    wsptr[i3*8] = (int)(tmp3 - tmp4);
    inptr++;
    quantptr++;
    wsptr++;
}
}
