#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float (*Y)[2];
float (*X_high)[40][2];
float *g_filt;
int m_max;
intptr_t ixh;
int m;

void init_vars() {
    m_max = 131072;  // 131072 * (2 + 40*2) * sizeof(float) ≈ 4.5 MB of data, reasonable for ~0.01s runtime
    ixh = 0;         // Ensure within [0, 39] range

    // Allocate Y: m_max x 2 floats
    Y = calloc(m_max, 2 * sizeof(float));
    if (!Y) exit(1);

    // Allocate X_high: m_max x 40 x 2 floats
    X_high = calloc(m_max, sizeof(float[40][2]));
    if (!X_high) exit(1);

    // Allocate g_filt: m_max floats
    g_filt = calloc(m_max, sizeof(float));
    if (!g_filt) exit(1);

    // Initialize g_filt and X_high with non-zero values to avoid NaN/inf issues
    for (int i = 0; i < m_max; i++) {
        g_filt[i] = 1.0f;
        for (int j = 0; j < 40; j++) {
            X_high[i][j][0] = (float)(i + j);
            X_high[i][j][1] = (float)(i + j + 1);
        }
    }

    // Ensure ixh is within valid bounds [0, 39]
    ixh = 0;
}