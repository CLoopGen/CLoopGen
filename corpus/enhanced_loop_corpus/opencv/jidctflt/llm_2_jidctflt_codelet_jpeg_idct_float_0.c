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



void loop() {
    for (ctr = 8; ctr > 0; ctr--) {
        JCOEFPTR col_ptr = inptr;
        FLOAT_MULT_TYPE *q_ptr = quantptr;
        float *ws_ptr = wsptr;

        if (col_ptr[8] == 0 && col_ptr[16] == 0 && col_ptr[24] == 0 &&
            col_ptr[32] == 0 && col_ptr[40] == 0 && col_ptr[48] == 0 && col_ptr[56] == 0) {
            float dcval = (((float)(col_ptr[0])) * (q_ptr[0] * ((FLOAT_MULT_TYPE)0.125)));
            for (int i = 0; i < 8; i++) {
                ws_ptr[i] = dcval;
            }
        } else {
            tmp0 = (((float)(col_ptr[0])) * (q_ptr[0] * ((FLOAT_MULT_TYPE)0.125)));
            tmp1 = (((float)(col_ptr[16])) * (q_ptr[16] * ((FLOAT_MULT_TYPE)0.125)));
            tmp2 = (((float)(col_ptr[32])) * (q_ptr[32] * ((FLOAT_MULT_TYPE)0.125)));
            tmp3 = (((float)(col_ptr[48])) * (q_ptr[48] * ((FLOAT_MULT_TYPE)0.125)));

            tmp10 = tmp0 + tmp2;
            tmp11 = tmp0 - tmp2;
            tmp13 = tmp1 + tmp3;
            tmp12 = (tmp1 - tmp3) * ((float)1.414213562) - tmp13;

            tmp0 = tmp10 + tmp13;
            tmp3 = tmp10 - tmp13;
            tmp1 = tmp11 + tmp12;
            tmp2 = tmp11 - tmp12;

            tmp4 = (((float)(col_ptr[8])) * (q_ptr[8] * ((FLOAT_MULT_TYPE)0.125)));
            tmp5 = (((float)(col_ptr[24])) * (q_ptr[24] * ((FLOAT_MULT_TYPE)0.125)));
            tmp6 = (((float)(col_ptr[40])) * (q_ptr[40] * ((FLOAT_MULT_TYPE)0.125)));
            tmp7 = (((float)(col_ptr[56])) * (q_ptr[56] * ((FLOAT_MULT_TYPE)0.125)));

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

            ws_ptr[0] = tmp0 + tmp7;
            ws_ptr[7] = tmp0 - tmp7;
            ws_ptr[1] = tmp1 + tmp6;
            ws_ptr[6] = tmp1 - tmp6;
            ws_ptr[2] = tmp2 + tmp5;
            ws_ptr[5] = tmp2 - tmp5;
            ws_ptr[3] = tmp3 + tmp4;
            ws_ptr[4] = tmp3 - tmp4;
        }

        inptr += 8;
        quantptr += 8;
        wsptr += 8;
    }
}
