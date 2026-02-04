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
    int indices[8] = {0, 8, 16, 24, 32, 40, 48, 56};
    for (ctr = 8; ctr > 0; ctr--) {
        JCOEFPTR base_in = inptr;
        FLOAT_MULT_TYPE *base_q = quantptr;
        float *base_ws = wsptr;

        int all_zero = 1;
        for (int j = 1; j < 8; j++) {
            if (base_in[indices[j]] != 0) {
                all_zero = 0;
                break;
            }
        }

        if (all_zero) {
            float dcval = (((float)(base_in[0])) * (base_q[0] * ((FLOAT_MULT_TYPE)0.125)));
            for (int j = 0; j < 8; j++) {
                base_ws[indices[j] / 8] = dcval;
            }
        } else {
            tmp0 = (((float)(base_in[indices[0]])) * (base_q[indices[0]] * ((FLOAT_MULT_TYPE)0.125)));
            tmp1 = (((float)(base_in[indices[2]])) * (base_q[indices[2]] * ((FLOAT_MULT_TYPE)0.125)));
            tmp2 = (((float)(base_in[indices[4]])) * (base_q[indices[4]] * ((FLOAT_MULT_TYPE)0.125)));
            tmp3 = (((float)(base_in[indices[6]])) * (base_q[indices[6]] * ((FLOAT_MULT_TYPE)0.125)));

            tmp10 = tmp0 + tmp2;
            tmp11 = tmp0 - tmp2;
            tmp13 = tmp1 + tmp3;
            tmp12 = (tmp1 - tmp3) * ((float)1.414213562) - tmp13;

            tmp0 = tmp10 + tmp13;
            tmp3 = tmp10 - tmp13;
            tmp1 = tmp11 + tmp12;
            tmp2 = tmp11 - tmp12;

            tmp4 = (((float)(base_in[indices[1]])) * (base_q[indices[1]] * ((FLOAT_MULT_TYPE)0.125)));
            tmp5 = (((float)(base_in[indices[3]])) * (base_q[indices[3]] * ((FLOAT_MULT_TYPE)0.125)));
            tmp6 = (((float)(base_in[indices[5]])) * (base_q[indices[5]] * ((FLOAT_MULT_TYPE)0.125)));
            tmp7 = (((float)(base_in[indices[7]])) * (base_q[indices[7]] * ((FLOAT_MULT_TYPE)0.125)));

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

            base_ws[0] = tmp0 + tmp7;
            base_ws[7] = tmp0 - tmp7;
            base_ws[1] = tmp1 + tmp6;
            base_ws[6] = tmp1 - tmp6;
            base_ws[2] = tmp2 + tmp5;
            base_ws[5] = tmp2 - tmp5;
            base_ws[3] = tmp3 + tmp4;
            base_ws[4] = tmp3 - tmp4;
        }

        inptr++;
        quantptr++;
        wsptr++;
    }
}
