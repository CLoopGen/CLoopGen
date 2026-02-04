#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access with Array Restructuring
    // Instead of accessing wsptr as a strided pointer (wsptr += 6), we pre-load values into local arrays
    // to enable consecutive access pattern and improve cache locality.

    INT32 ws_local[12][6];  // Simulate local block storage for 12 iterations

    // Pre-load all required data from wsptr in a linear fashion
    int *wsptr_base = wsptr;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            ws_local[i][j] = (INT32)wsptr_base[i * 6 + j];
        }
    }

    for (ctr = 0; ctr < 12; ctr++) {
        outptr = output_buf[ctr] + output_col;

        tmp10 = (INT32)ws_local[ctr][0] + ((((INT32)(128 << 2)) << (2 + 3)) + (((INT32)1) << (2 + 2)));
        tmp10 <<= 13;
        tmp12 = (INT32)ws_local[ctr][4];
        tmp20 = ((tmp12) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
        tmp11 = tmp10 + tmp20;
        tmp21 = tmp10 - tmp20 - tmp20;
        tmp20 = (INT32)ws_local[ctr][2];
        tmp10 = ((tmp20) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
        tmp20 = tmp11 + tmp10;
        tmp22 = tmp11 - tmp10;
        z1 = (INT32)ws_local[ctr][1];
        z2 = (INT32)ws_local[ctr][3];
        z3 = (INT32)ws_local[ctr][5];
        tmp11 = ((z1 + z3) * (((INT32)((0.366025404) * (((INT32)1) << 13) + 0.5))));
        tmp10 = tmp11 + ((z1 + z2) << 13);
        tmp12 = tmp11 + ((z3 - z2) << 13);
        tmp11 = (z1 - z2 - z3) << 13;
        outptr[0] = range_limit[(int)((tmp20 + tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[5] = range_limit[(int)((tmp20 - tmp10) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[1] = range_limit[(int)((tmp21 + tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[4] = range_limit[(int)((tmp21 - tmp11) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[2] = range_limit[(int)((tmp22 + tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
        outptr[3] = range_limit[(int)((tmp22 - tmp12) >> (13 + 2 + 3)) & ((128 << 2) * 2 - 1)];
    }
}
