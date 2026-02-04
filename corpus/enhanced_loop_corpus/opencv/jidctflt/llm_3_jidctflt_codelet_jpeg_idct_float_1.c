#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
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
extern float *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int access_pattern[8] = {0, 2, 4, 6, 1, 3, 5, 7}; // Strided access: even indices first, then odd
    for (ctr = 0; ctr < 8; ctr++) {
        int idx = access_pattern[ctr];
        outptr = output_buf[idx] + output_col;
        z5 = wsptr[idx] + ((float)128 + (float)0.5);
        tmp10 = z5 + wsptr[(idx + 4) % 8];
        tmp11 = z5 - wsptr[(idx + 4) % 8];
        tmp13 = wsptr[(idx + 2) % 8] + wsptr[(idx + 6) % 8];
        tmp12 = (wsptr[(idx + 2) % 8] - wsptr[(idx + 6) % 8]) * ((float)1.414213562) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;
        z13 = wsptr[(idx + 5) % 8] + wsptr[(idx + 3) % 8];
        z10 = wsptr[(idx + 5) % 8] - wsptr[(idx + 3) % 8];
        z11 = wsptr[(idx + 1) % 8] + wsptr[(idx + 7) % 8];
        z12 = wsptr[(idx + 1) % 8] - wsptr[(idx + 7) % 8];
        tmp7 = z11 + z13;
        tmp11 = (z11 - z13) * ((float)1.414213562);
        z5 = (z10 + z12) * ((float)1.847759065);
        tmp10 = z5 - z12 * ((float)1.0823921999999999);
        tmp12 = z5 - z10 * ((float)2.6131259299999998);
        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 - tmp5;
        outptr[0] = range_limit[((int)(tmp0 + tmp7)) & (255 * 4 + 3)];
        outptr[7] = range_limit[((int)(tmp0 - tmp7)) & (255 * 4 + 3)];
        outptr[1] = range_limit[((int)(tmp1 + tmp6)) & (255 * 4 + 3)];
        outptr[6] = range_limit[((int)(tmp1 - tmp6)) & (255 * 4 + 3)];
        outptr[2] = range_limit[((int)(tmp2 + tmp5)) & (255 * 4 + 3)];
        outptr[5] = range_limit[((int)(tmp2 - tmp5)) & (255 * 4 + 3)];
        outptr[3] = range_limit[((int)(tmp3 + tmp4)) & (255 * 4 + 3)];
        outptr[4] = range_limit[((int)(tmp3 - tmp4)) & (255 * 4 + 3)];
    }
}
