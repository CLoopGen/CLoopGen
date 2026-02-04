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



void loop() {
    float local_wsptr[8];
    float local_coeffs[8];
    JCOEFPTR in_local = inptr;
    FLOAT_MULT_TYPE *q_local = quantptr;
    float *ws_local = wsptr;

    for (ctr = 8; ctr > 0; ctr--) {
        local_coeffs[0] = (((float)(in_local[8 * 0])) * (q_local[8 * 0]));
        if ((in_local[8 * 1] | in_local[8 * 2] | in_local[8 * 3] | in_local[8 * 4] | in_local[8 * 5] | in_local[8 * 6] | in_local[8 * 7]) == 0) {
            for (int i = 0; i < 8; i++) {
                local_wsptr[i] = local_coeffs[0];
            }
        } else {
            local_coeffs[1] = (((float)(in_local[8 * 2])) * (q_local[8 * 2]));
            local_coeffs[2] = (((float)(in_local[8 * 4])) * (q_local[8 * 4]));
            local_coeffs[3] = (((float)(in_local[8 * 6])) * (q_local[8 * 6]));
            tmp10 = local_coeffs[0] + local_coeffs[2];
            tmp11 = local_coeffs[0] - local_coeffs[2];
            tmp13 = local_coeffs[1] + local_coeffs[3];
            tmp12 = (local_coeffs[1] - local_coeffs[3]) * ((float)1.414213562) - tmp13;
            tmp0 = tmp10 + tmp13;
            tmp3 = tmp10 - tmp13;
            tmp1 = tmp11 + tmp12;
            tmp2 = tmp11 - tmp12;

            local_coeffs[4] = (((float)(in_local[8 * 1])) * (q_local[8 * 1]));
            local_coeffs[5] = (((float)(in_local[8 * 3])) * (q_local[8 * 3]));
            local_coeffs[6] = (((float)(in_local[8 * 5])) * (q_local[8 * 5]));
            local_coeffs[7] = (((float)(in_local[8 * 7])) * (q_local[8 * 7]));
            z13 = local_coeffs[6] + local_coeffs[5];
            z10 = local_coeffs[6] - local_coeffs[5];
            z11 = local_coeffs[4] + local_coeffs[7];
            z12 = local_coeffs[4] - local_coeffs[7];
            tmp7 = z11 + z13;
            tmp11 = (z11 - z13) * ((float)1.414213562);
            z5 = (z10 + z12) * ((float)1.847759065);
            tmp10 = ((float)1.0823921999999999) * z12 - z5;
            tmp12 = ((float)-2.6131259299999998) * z10 + z5;
            tmp6 = tmp12 - tmp7;
            tmp5 = tmp11 - tmp6;
            tmp4 = tmp10 + tmp5;

            local_wsptr[0] = tmp0 + tmp7;
            local_wsptr[7] = tmp0 - tmp7;
            local_wsptr[1] = tmp1 + tmp6;
            local_wsptr[6] = tmp1 - tmp6;
            local_wsptr[2] = tmp2 + tmp5;
            local_wsptr[5] = tmp2 - tmp5;
            local_wsptr[4] = tmp3 + tmp4;
            local_wsptr[3] = tmp3 - tmp4;
        }

        for (int i = 0; i < 8; i++) {
            ws_local[i] = local_wsptr[i];
        }

        in_local++;
        q_local++;
        ws_local++;
    }

    inptr = in_local;
    quantptr = q_local;
    wsptr = ws_local;
}
