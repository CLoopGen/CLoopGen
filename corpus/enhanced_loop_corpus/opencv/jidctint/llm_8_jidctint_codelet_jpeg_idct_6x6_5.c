#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long JLONG;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp2;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Eliminate loop-carried dependency on `wsptr` by unrolling two iterations manually
// while maintaining semantic equivalence through careful scheduling

int limit = (6 / 2) * 2; // Ensure even number of iterations for safe unrolling

for (ctr = 0; ctr < limit; ctr += 2) {
    JSAMPROW outptr0 = output_buf[ctr+0] + output_col;
    JSAMPROW outptr1 = output_buf[ctr+1] + output_col;

    // Load all needed data upfront to expose parallelism
    JLONG w0_0 = (JLONG)wsptr[0];  JLONG w0_1 = (JLONG)wsptr[1];  JLONG w0_2 = (JLONG)wsptr[2];
    JLONG w0_3 = (JLONG)wsptr[3];  JLONG w0_4 = (JLONG)wsptr[4];  JLONG w0_5 = (JLONG)wsptr[5];
    JLONG w1_0 = (JLONG)wsptr[6];  JLONG w1_1 = (JLONG)wsptr[7];  JLONG w1_2 = (JLONG)wsptr[8];
    JLONG w1_3 = (JLONG)wsptr[9];  JLONG w1_4 = (JLONG)wsptr[10]; JLONG w1_5 = (JLONG)wsptr[11];

    // First block: process first row (ctr)
    JLONG t0 = ((w0_0 + (1 << 2)) << 13);
    JLONG t2 = w0_4;
    JLONG t10 = t2 * (JLONG)(0.707106781 * (1<<13) + 0.5);
    JLONG u1 = t0 + t10;
    JLONG u11 = t0 - 2*t10;
    t10 = w0_2;
    JLONG u0 = t10 * (JLONG)(1.224744871 * (1<<13) + 0.5);
    JLONG u10 = u1 + u0;
    JLONG u12 = u1 - u0;
    JLONG z1 = w0_1, z2 = w0_3, z3 = w0_5;
    JLONG v1 = ((z1 + z3) * (JLONG)(0.366025404 * (1<<13) + 0.5));
    JLONG v0 = v1 + ((JLONG)((unsigned long)(z1 + z2) << 13));
    JLONG v2 = v1 + ((JLONG)((unsigned long)(z3 - z2) << 13));
    JLONG v3 = ((JLONG)((unsigned long)(z1 - z2 - z3) << 13));

    // Second block: process second row (ctr+1), independent of first
    JLONG s0 = ((w1_0 + (1 << 2)) << 13);
    JLONG s2 = w1_4;
    JLONG s10 = s2 * (JLONG)(0.707106781 * (1<<13) + 0.5);
    JLONG x1 = s0 + s10;
    JLONG x11 = s0 - 2*s10;
    s10 = w1_2;
    JLONG x0 = s10 * (JLONG)(1.224744871 * (1<<13) + 0.5);
    JLONG x10 = x1 + x0;
    JLONG x12 = x1 - x0;
    JLONG y1 = w1_1, y2 = w1_3, y3 = w1_5;
    JLONG w1_val = ((y1 + y3) * (JLONG)(0.366025404 * (1<<13) + 0.5));
    JLONG w0_val = w1_val + ((JLONG)((unsigned long)(y1 + y2) << 13));
    JLONG w2_val = w1_val + ((JLONG)((unsigned long)(y3 - y2) << 13));
    JLONG w3_val = ((JLONG)((unsigned long)(y1 - y2 - y3) << 13));

    // Final store operations separated per row
    int shift = 17, mask = 1023;
    outptr0[0] = range_limit[(int)((u10 + v0) >> shift) & mask];
    outptr0[5] = range_limit[(int)((u10 - v0) >> shift) & mask];
    outptr0[1] = range_limit[(int)((u11 + v3) >> shift) & mask];
    outptr0[4] = range_limit[(int)((u11 - v3) >> shift) & mask];
    outptr0[2] = range_limit[(int)((u12 + v2) >> shift) & mask];
    outptr0[3] = range_limit[(int)((u12 - v2) >> shift) & mask];

    outptr1[0] = range_limit[(int)((x10 + w0_val) >> shift) & mask];
    outptr1[5] = range_limit[(int)((x10 - w0_val) >> shift) & mask];
    outptr1[1] = range_limit[(int)((x11 + w3_val) >> shift) & mask];
    outptr1[4] = range_limit[(int)((x11 - w3_val) >> shift) & mask];
    outptr1[2] = range_limit[(int)((x12 + w2_val) >> shift) & mask];
    outptr1[3] = range_limit[(int)((x12 - w2_val) >> shift) & mask];

    wsptr += 12; // Advance by two blocks
}

// Handle any remaining iteration if original count was odd
if (ctr < 6) {
    outptr = output_buf[ctr] + output_col;
    tmp0 = (JLONG)wsptr[0] + (((JLONG)1) << (1 + 2));
    tmp0 = ((JLONG)((unsigned long)(tmp0) << (13)));
    tmp2 = (JLONG)wsptr[4];
    tmp10 = ((tmp2) * (((JLONG)((0.70710678100000002) * (((JLONG)1) << 13) + 0.5))));
    tmp1 = tmp0 + tmp10;
    tmp11 = tmp0 - tmp10 - tmp10;
    tmp10 = (JLONG)wsptr[2];
    tmp0 = ((tmp10) * (((JLONG)((1.224744871) * (((JLONG)1) << 13) + 0.5))));
    tmp10 = tmp1 + tmp0;
    tmp12 = tmp1 - tmp0;
    z1 = (JLONG)wsptr[1];
    z2 = (JLONG)wsptr[3];
    z3 = (JLONG)wsptr[5];
    tmp1 = ((z1 + z3) * (((JLONG)((0.366025404) * (((JLONG)1) << 13) + 0.5))));
    tmp0 = tmp1 + ((JLONG)((unsigned long)(z1 + z2) << (13)));
    tmp2 = tmp1 + ((JLONG)((unsigned long)(z3 - z2) << (13)));
    tmp1 = ((JLONG)((unsigned long)(z1 - z2 - z3) << (13)));
    outptr[0] = range_limit[(int)((tmp10 + tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[5] = range_limit[(int)((tmp10 - tmp0) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[1] = range_limit[(int)((tmp11 + tmp1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[4] = range_limit[(int)((tmp11 - tmp1) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[2] = range_limit[(int)((tmp12 + tmp2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    outptr[3] = range_limit[(int)((tmp12 - tmp2) >> (13 + 1 + 3)) & (255 * 4 + 3)];
    wsptr += 6;
}

}
