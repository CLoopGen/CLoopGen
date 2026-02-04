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



void loop() {
    for (ctr = 8; ctr > 0; ctr--) {
        if ((inptr[8 * 1] | inptr[8 * 2] | inptr[8 * 3] | inptr[8 * 4] | inptr[8 * 5] | inptr[8 * 6] | inptr[8 * 7]) == 0) {
            int dcval = (int)(((IFAST_MULT_TYPE)(inptr[0])) * (quantptr[0]));
            for (int i = 0; i < 8; i++) {
                wsptr[i] = dcval;
            }
            inptr++;
            quantptr++;
            wsptr += 8;
            continue;
        }

        DCTELEM t[8];
        for (int i = 0; i < 8; i++) {
            t[i] = (((IFAST_MULT_TYPE)(inptr[i * 8])) * (quantptr[i * 8]));
        }

        tmp0 = t[0]; tmp1 = t[1]; tmp2 = t[2]; tmp3 = t[3];
        tmp10 = tmp0 + tmp2;
        tmp11 = tmp0 - tmp2;
        tmp13 = tmp1 + tmp3;
        tmp12 = ((DCTELEM)(((tmp1 - tmp3) * (((INT32)362))) >> 8)) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        z13 = tmp6 + tmp5;
        z10 = tmp6 - tmp5;
        z11 = tmp4 + tmp7;
        z12 = tmp4 - tmp7;
        tmp7 = z11 + z13;
        tmp11 = ((DCTELEM)(((z11 - z13) * (((INT32)362))) >> 8));
        z5 = ((DCTELEM)(((z10 + z12) * (((INT32)473))) >> 8));
        tmp10 = ((DCTELEM)(((z12) * (((INT32)277))) >> 8)) - z5;
        tmp12 = ((DCTELEM)(((z10) * (-((INT32)669))) >> 8)) + z5;
        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;

        wsptr[0] = (int)(tmp0 + tmp7);
        wsptr[7] = (int)(tmp0 - tmp7);
        wsptr[1] = (int)(tmp1 + tmp6);
        wsptr[6] = (int)(tmp1 - tmp6);
        wsptr[2] = (int)(tmp2 + tmp5);
        wsptr[5] = (int)(tmp2 - tmp5);
        wsptr[4] = (int)(tmp3 + tmp4);
        wsptr[3] = (int)(tmp3 - tmp4);

        inptr++;
        quantptr++;
        wsptr += 8;
    }
}
