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
// Use indirect access via index array to simulate non-sequential memory access pattern
const int indices[8] = {0, 2, 4, 6, 1, 3, 5, 7};
const int write_order[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Logical output mapping

for (ctr = 8; ctr > 0; ctr--) {
    short invals[8];
    float qvals[8];

    // Gather inputs using indirect indexing with stride simulation
    for (int i = 0; i < 8; i++) {
        int idx = indices[i];
        invals[i] = inptr[idx * 8];
        qvals[i] = quantptr[idx * 8];
    }

    if ((invals[1] | invals[2] | invals[3] | invals[4] | invals[5] | invals[6] | invals[7]) == 0) {
        float dcval = ((float)invals[0]) * qvals[0];
        for (int i = 0; i < 8; i++) {
            wsptr[write_order[i]] = dcval;
        }
        inptr++;
        quantptr++;
        wsptr++;
        continue;
    }

    tmp0 = ((float)invals[0]) * qvals[0]; // index 0
    tmp1 = ((float)invals[1]) * qvals[1]; // index 2
    tmp2 = ((float)invals[2]) * qvals[2]; // index 4
    tmp3 = ((float)invals[3]) * qvals[3]; // index 6

    tmp10 = tmp0 + tmp2;
    tmp11 = tmp0 - tmp2;
    tmp13 = tmp1 + tmp3;
    tmp12 = (tmp1 - tmp3) * ((float)1.414213562) - tmp13;

    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;

    tmp4 = ((float)invals[4]) * qvals[4]; // index 1
    tmp5 = ((float)invals[5]) * qvals[5]; // index 3
    tmp6 = ((float)invals[6]) * qvals[6]; // index 5
    tmp7 = ((float)invals[7]) * qvals[7]; // index 7

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

    wsptr[write_order[0]] = tmp0 + tmp7;
    wsptr[write_order[7]] = tmp0 - tmp7;
    wsptr[write_order[1]] = tmp1 + tmp6;
    wsptr[write_order[6]] = tmp1 - tmp6;
    wsptr[write_order[2]] = tmp2 + tmp5;
    wsptr[write_order[5]] = tmp2 - tmp5;
    wsptr[write_order[4]] = tmp3 + tmp4;
    wsptr[write_order[3]] = tmp3 - tmp4;

    inptr++;
    quantptr++;
    wsptr++;
}
}
