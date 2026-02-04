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
    // Variant 2: Strided Indirect Access via Pointer Arithmetic
    // Replace direct array indexing with pointer arithmetic using strides
    // to simulate hardware-friendly or transformed memory layouts.

    float *tp = tmp + i;
    float *op = out;
    float *bp = buf;
    float *wp = win;

    // Precompute windowing offset base
    int win_offset_base = ((36 + 8 - 1) & ~7) / 2;

    for (j = 0; j < 4; j++) {
        t0 = tp[0];
        t1 = tp[2];
        s0 = t1 + t0;
        s2 = t1 - t0;
        t2 = tp[1];
        t3 = tp[3];
        s1 = 2.0f * icos36h[j] * (t3 + t2);
        s3 = icos36[8 - j] * (t3 - t2);

        t0 = s0 + s1;
        t1 = s0 - s1;

        // Strided output and buffer updates using pointer offsets
        float *out_p1 = op + (9 + j) * 32;
        float *out_p2 = op + (8 - j) * 32;
        float *buf_p1 = bp + 4 * (9 + j);
        float *buf_p2 = bp + 4 * (8 - j);
        float *win_p1 = wp + (9 + j);
        float *win_p2 = wp + (8 - j);
        float *win_buf1 = wp + win_offset_base + 9 + j;
        float *win_buf2 = wp + win_offset_base + 8 - j;

        *out_p1 = (*win_p1) * t1 + *buf_p1;
        *out_p2 = (*win_p2) * t1 + *buf_p2;
        *buf_p1 = (*win_buf1) * t0;
        *buf_p2 = (*win_buf2) * t0;

        t0 = s2 + s3;
        t1 = s2 - s3;

        float *out_p3 = op + (17 - j) * 32;
        float *out_p4 = op + j * 32;
        float *buf_p3 = bp + 4 * (17 - j);
        float *buf_p4 = bp + 4 * j;
        float *win_p3 = wp + (17 - j);
        float *win_p4 = wp + j;
        float *win_buf3 = wp + win_offset_base + 17 - j;
        float *win_buf4 = wp + win_offset_base + j;

        *out_p3 = (*win_p3) * t1 + *buf_p3;
        *out_p4 = (*win_p4) * t1 + *buf_p4;
        *buf_p3 = (*win_buf3) * t0;
        *buf_p4 = (*win_buf4) * t0;

        tp += 4;  // Move temp pointer stride-wise
        i += 4;
    }
}
