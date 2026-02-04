#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef int DCTELEM;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern DCTELEM tmp0;
extern DCTELEM tmp1;
extern DCTELEM tmp2;
extern DCTELEM tmp3;
extern DCTELEM tmp4;
extern DCTELEM tmp5;
extern DCTELEM tmp6;
extern DCTELEM tmp7;
extern DCTELEM tmp10;
extern DCTELEM tmp11;
extern DCTELEM tmp12;
extern DCTELEM tmp13;
extern DCTELEM z5;
extern DCTELEM z10;
extern DCTELEM z11;
extern DCTELEM z12;
extern DCTELEM z13;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Precompute base pointers and use indirect indexing via a fixed index map to simulate irregular access
    const int idx_map[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Simulate potential future remapping or shuffle
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + output_col;
        int base_idx = ctr << 3; // Equivalent to ctr * 8

        // Indirect memory access using pointer arithmetic with index array
        int w0 = wsptr[base_idx + idx_map[0]];
        int w1 = wsptr[base_idx + idx_map[1]];
        int w2 = wsptr[base_idx + idx_map[2]];
        int w3 = wsptr[base_idx + idx_map[3]];
        int w4 = wsptr[base_idx + idx_map[4]];
        int w5 = wsptr[base_idx + idx_map[5]];
        int w6 = wsptr[base_idx + idx_map[6]];
        int w7 = wsptr[base_idx + idx_map[7]];

        if ((w1 | w2 | w3 | w4 | w5 | w6 | w7) == 0) {
            JSAMPLE dcval = range_limit[((int)((w0) >> (2 + 3))) & (255 * 4 + 3)];
            for (int i = 0; i < 8; i++) {
                outptr[i] = dcval;
            }
            continue;
        }

        tmp10 = ((DCTELEM)w0 + (DCTELEM)w4);
        tmp11 = ((DCTELEM)w0 - (DCTELEM)w4);
        tmp13 = ((DCTELEM)w2 + (DCTELEM)w6);
        tmp12 = ((DCTELEM)((((DCTELEM)w2 - (DCTELEM)w6) * (((INT32)362))) >> (8))) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;
        z13 = (DCTELEM)w5 + (DCTELEM)w3;
        z10 = (DCTELEM)w5 - (DCTELEM)w3;
        z11 = (DCTELEM)w1 + (DCTELEM)w7;
        z12 = (DCTELEM)w1 - (DCTELEM)w7;
        tmp7 = z11 + z13;
        tmp11 = ((DCTELEM)(((z11 - z13) * (((INT32)362))) >> (8)));
        z5 = ((DCTELEM)(((z10 + z12) * (((INT32)473))) >> (8)));
        tmp10 = ((DCTELEM)(((z12) * (((INT32)277))) >> (8))) - z5;
        tmp12 = ((DCTELEM)(((z10) * (-((INT32)669))) >> (8))) + z5;
        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;

        // Store results using direct sequential access
        outptr[0] = range_limit[((int)((tmp0 + tmp7) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[1] = range_limit[((int)((tmp1 + tmp6) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[2] = range_limit[((int)((tmp2 + tmp5) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[3] = range_limit[((int)((tmp3 - tmp4) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[4] = range_limit[((int)((tmp3 + tmp4) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[5] = range_limit[((int)((tmp2 - tmp5) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[6] = range_limit[((int)((tmp1 - tmp6) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[7] = range_limit[((int)((tmp0 - tmp7) >> (2 + 3))) & (255 * 4 + 3)];
    }
}
