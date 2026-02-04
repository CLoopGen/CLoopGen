#include <stdio.h>

typedef long BLASLONG;

BLASLONG bm = 16000;
BLASLONG bk = 256;
float alpha = 1.1f;

float bb_storage[512] __attribute__((aligned(32)));
float *bb = bb_storage;

BLASLONG i;
BLASLONG k;

float C0_storage[16000 * 16] __attribute__((aligned(32)));
float *C0 = C0_storage;

float C1_storage[16000 * 16] __attribute__((aligned(32)));
float *C1 = C1_storage;

float ptrba_storage[16000 * 16 * 256] __attribute__((aligned(32)));
float *ptrba = ptrba_storage;

float res0_0, res0_1, res0_2, res0_3, res0_4, res0_5, res0_6, res0_7;
float res0_8, res0_9, res0_10, res0_11, res0_12, res0_13, res0_14, res0_15;
float res1_0, res1_1, res1_2, res1_3, res1_4, res1_5, res1_6, res1_7;
float res1_8, res1_9, res1_10, res1_11, res1_12, res1_13, res1_14, res1_15;

float a0, a1, b0, b1;

BLASLONG off = 0;
BLASLONG temp;

float *ptrbb;

void init_vars() {
    for (int i = 0; i < 512; i++) {
        bb_storage[i] = 1.0f + (i * 0.01f);
    }

    for (int i = 0; i < 16000 * 16; i++) {
        C0_storage[i] = 0.0f;
        C1_storage[i] = 0.0f;
    }

    for (int i = 0; i < 16000 * 16 * 256; i++) {
        ptrba_storage[i] = 0.1f + (i * 0.001f);
    }

    ptrbb = bb;
}