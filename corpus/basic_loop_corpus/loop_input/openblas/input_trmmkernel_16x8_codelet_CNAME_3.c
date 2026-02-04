#include <stdio.h>

typedef long BLASLONG;

BLASLONG k;
float *ptrba;
float *ptrbb;
float res0_0 = 0.0f;
float res0_1 = 0.0f;
float res0_2 = 0.0f;
float res0_3 = 0.0f;
float res0_4 = 0.0f;
float res0_5 = 0.0f;
float res0_6 = 0.0f;
float res0_7 = 0.0f;
float res1_0 = 0.0f;
float res1_1 = 0.0f;
float res1_2 = 0.0f;
float res1_3 = 0.0f;
float res1_4 = 0.0f;
float res1_5 = 0.0f;
float res1_6 = 0.0f;
float res1_7 = 0.0f;
float res2_0 = 0.0f;
float res2_1 = 0.0f;
float res2_2 = 0.0f;
float res2_3 = 0.0f;
float res2_4 = 0.0f;
float res2_5 = 0.0f;
float res2_6 = 0.0f;
float res2_7 = 0.0f;
float res3_0 = 0.0f;
float res3_1 = 0.0f;
float res3_2 = 0.0f;
float res3_3 = 0.0f;
float res3_4 = 0.0f;
float res3_5 = 0.0f;
float res3_6 = 0.0f;
float res3_7 = 0.0f;
float a0;
float a1;
float b0;
float b1;
float b2;
float b3;
BLASLONG temp;

static float arrba[2097152]; // ~8MB: 2^18 * 8 floats per iteration * sizeof(float)
static float arrbb[1048576]; // ~4MB: 2^18 * 4 floats per iteration * sizeof(float)

void init_vars() {
    ptrba = arrba;
    ptrbb = arrbb;
    temp = 262144; // 2^18 iterations -> total of 262144*8 = 2,097,152 accesses to ptrba, 262144*4 = 1,048,576 to ptrbb

    for (int i = 0; i < 2097152; i++) {
        arrba[i] = 1.0f + (i & 15) * 0.01f;
    }
    for (int i = 0; i < 1048576; i++) {
        arrbb[i] = 2.0f + (i & 7) * 0.02f;
    }

    res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 = 0.0f;
    res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 = 0.0f;
    res2_0 = res2_1 = res2_2 = res2_3 = res2_4 = res2_5 = res2_6 = res2_7 = 0.0f;
    res3_0 = res3_1 = res3_2 = res3_3 = res3_4 = res3_5 = res3_6 = res3_7 = 0.0f;
}