#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float INTFLOAT;

const INTFLOAT ff_sbr_noise_table[][2] = {
    { 0.1f, 0.9f }, { -0.3f, 0.7f }, { 0.5f, -0.6f }, { -0.8f, 0.2f },
    { 0.4f, -0.5f }, { -0.1f, 0.8f }, { 0.9f, -0.3f }, { -0.7f, 0.4f },
    { 0.2f, -0.9f }, { -0.4f, 0.6f }, { 0.6f, -0.2f }, { -0.9f, 0.1f },
    { 0.3f, -0.8f }, { -0.6f, 0.3f }, { 0.7f, -0.4f }, { -0.2f, 0.9f },
    { 0.8f, -0.1f }, { -0.5f, 0.5f }, { 0.1f, -0.7f }, { -0.8f, 0.6f },
    { 0.4f, -0.3f }, { -0.9f, 0.8f }, { 0.5f, -0.9f }, { -0.1f, 0.2f },
    { 0.7f, -0.5f }, { -0.3f, 0.4f }, { 0.9f, -0.7f }, { -0.6f, 0.9f },
    { 0.2f, -0.1f }, { -0.4f, 0.3f }, { 0.8f, -0.8f }, { -0.7f, 0.7f }
};

float (*Y)[2];
float *s_m;
float *q_filt;
int noise;
float phi_sign0;
float phi_sign1;
int m_max;
int m;

void init_vars() {
    m_max = 1 << 20; // ~4MB of data (1M elements * 4 bytes * 2 floats per Y[m]) -> ensures ~0.01 sec runtime

    Y = (float(*)[2])calloc(m_max, sizeof(float[2]));
    s_m = (float*)calloc(m_max, sizeof(float));
    q_filt = (float*)calloc(m_max, sizeof(float));

    for (int i = 0; i < m_max; i++) {
        Y[i][0] = (float)(i % 100) * 0.01f;
        Y[i][1] = (float)(i % 100) * 0.02f;
        s_m[i] = (i % 3) ? 0.0f : ((i % 2) ? 0.1f : -0.1f);
        q_filt[i] = 0.25f + (i % 5) * 0.1f;
    }

    noise = 0;
    phi_sign0 = 1.0f;
    phi_sign1 = -1.0f;
}