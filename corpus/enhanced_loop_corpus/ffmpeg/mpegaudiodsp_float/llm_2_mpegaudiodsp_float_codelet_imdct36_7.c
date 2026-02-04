#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float icos36[9];
extern  float icos36h[9];
extern float *out;
extern float *buf;
extern float *win;
extern int i;
extern int j;
extern float t0;
extern float t1;
extern float t2;
extern float t3;
extern float s0;
extern float s1;
extern float s2;
extern float s3;
extern float tmp[18];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Original strided access is transformed to use consecutive indexing via local accumulation.
    // We precompute base indices and restructure accesses to improve spatial locality.

    float *out_base = out;
    float *buf_base = buf;
    float *win_base = win;
    int idx[8];
    
    // Precompute all required indices to enable consecutive ordering
    for (int k = 0; k < 4; k++) {
        idx[0 + k] = 9 + k;
        idx[4 + k] = 8 - k;
    }

    for (j = 0; j < 4; j++) {
        t0 = tmp[i];
        t1 = tmp[i + 2];
        s0 = t1 + t0;
        s2 = t1 - t0;
        t2 = tmp[i + 1];
        t3 = tmp[i + 3];
        s1 = 2.0f * icos36h[j] * (t3 + t2);
        s3 = icos36[8 - j] * (t3 - t2);

        t0 = s0 + s1;
        t1 = s0 - s1;

        // Use precomputed indices for more predictable access
        int a = idx[j], b = idx[j + 4];
        out_base[a * 32] = win_base[a] * t1 + buf_base[4 * a];
        out_base[b * 32] = win_base[b] * t1 + buf_base[4 * b];
        buf_base[4 * a] = win_base[(36 + 8 - 1) & ~7 >> 1 | 9 + j] * t0;
        buf_base[4 * b] = win_base[(36 + 8 - 1) & ~7 >> 1 | 8 - j] * t0;

        t0 = s2 + s3;
        t1 = s2 - s3;

        int c = idx[8 - j], d = idx[0 + j];
        out_base[c * 32] = win_base[c] * t1 + buf_base[4 * c];
        out_base[d * 32] = win_base[d] * t1 + buf_base[4 * d];
        buf_base[4 * c] = win_base[(36 + 8 - 1) & ~7 >> 1 | 9 + 8 - j] * t0;
        buf_base[4 * d] = win_base[(36 + 8 - 1) & ~7 >> 1 | j] * t0;

        i += 4;
    }
}
