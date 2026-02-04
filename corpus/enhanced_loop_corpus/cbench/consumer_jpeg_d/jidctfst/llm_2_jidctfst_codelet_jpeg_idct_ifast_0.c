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
        JCOEFPTR in_offset = inptr + 8 * 0;
        IFAST_MULT_TYPE *quant_offset = quantptr + 8 * 0;
        int *ws_offset = wsptr + 8 * 0;

        if ((in_offset[8] | in_offset[16] | in_offset[24] | in_offset[32] | in_offset[40] | in_offset[48] | in_offset[56]) == 0) {
            int dcval = (int)(((IFAST_MULT_TYPE)(in_offset[0])) * (quant_offset[0]));
            for (int i = 0; i < 8; i++) {
                ws_offset[i] = dcval;
            }
            inptr++;
            quantptr++;
            wsptr++;
            continue;
        }

        tmp0 = (((IFAST_MULT_TYPE)(in_offset[0])) * (quant_offset[0]));
        tmp1 = (((IFAST_MULT_TYPE)(in_offset[16])) * (quant_offset[16]));
        tmp2 = (((IFAST_MULT_TYPE)(in_offset[32])) * (quant_offset[32]));
        tmp3 = (((IFAST_MULT_TYPE)(in_offset[48])) * (quant_offset[48]));
        tmp10 = tmp0 + tmp2;
        tmp11 = tmp0 - tmp2;
        tmp13 = tmp1 + tmp3;
        tmp12 = ((DCTELEM)(((tmp1 - tmp3) * (((INT32)362))) >> (8))) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;

        tmp4 = (((IFAST_MULT_TYPE)(in_offset[8])) * (quant_offset[8]));
        tmp5 = (((IFAST_MULT_TYPE)(in_offset[24])) * (quant_offset[24]));
        tmp6 = (((IFAST_MULT_TYPE)(in_offset[40])) * (quant_offset[40]));
        tmp7 = (((IFAST_MULT_TYPE)(in_offset[56])) * (quant_offset[56]));

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

        ws_offset[0] = (int)(tmp0 + tmp7);
        ws_offset[7] = (int)(tmp0 - tmp7);
        ws_offset[1] = (int)(tmp1 + tmp6);
        ws_offset[6] = (int)(tmp1 - tmp6);
        ws_offset[2] = (int)(tmp2 + tmp5);
        ws_offset[5] = (int)(tmp2 - tmp5);
        ws_offset[4] = (int)(tmp3 + tmp4);
        ws_offset[3] = (int)(tmp3 - tmp4);

        inptr++;
        quantptr++;
        wsptr++;
    }
}
