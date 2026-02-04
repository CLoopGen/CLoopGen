#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

#define FIRLEN 21
#define HALFFIRLEN ((FIRLEN - 1) / 2)
#define BUFFER_SIZE 1024

float *firbuf;
float *hpfsmpl;
float *psy_fir_coeffs;
int i;
int j;

void init_vars() {
    firbuf = (float*)aligned_alloc(32, sizeof(float) * (BUFFER_SIZE + FIRLEN));
    hpfsmpl = (float*)aligned_alloc(32, sizeof(float) * BUFFER_SIZE);
    psy_fir_coeffs = (float*)aligned_alloc(32, sizeof(float) * HALFFIRLEN);

    for (int idx = 0; idx < BUFFER_SIZE + FIRLEN; idx++) {
        firbuf[idx] = (float)((idx % 100) - 50) / 100.0f;
    }

    for (int idx = 0; idx < HALFFIRLEN; idx++) {
        float theta = (float)(M_PI * idx / (HALFFIRLEN));
        float w = (idx == 0) ? 1.0f : sinf(M_PI * idx / HALFFIRLEN) / (M_PI * idx / HALFFIRLEN);
        psy_fir_coeffs[idx] = cosf(M_PI * idx / (2 * HALFFIRLEN)) * w;
    }
}