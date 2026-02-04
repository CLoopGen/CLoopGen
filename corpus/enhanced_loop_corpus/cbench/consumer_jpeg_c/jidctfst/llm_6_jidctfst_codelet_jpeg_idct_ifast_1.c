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
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + output_col;
        DCTELEM local_wsptr[8];
        for (int i = 0; i < 8; i++) {
            local_wsptr[i] = wsptr[i];
        }
        if ((local_wsptr[1] | local_wsptr[2] | local_wsptr[3] | local_wsptr[4] | 
             local_wsptr[5] | local_wsptr[6] | local_wsptr[7]) == 0) {
            JSAMPLE dcval = range_limit[((int)((local_wsptr[0]) >> (2 + 3))) & (255 * 4 + 3)];
            outptr[0] = dcval;
            outptr[1] = dcval;
            outptr[2] = dcval;
            outptr[3] = dcval;
            outptr[4] = dcval;
            outptr[5] = dcval;
            outptr[6] = dcval;
            outptr[7] = dcval;
            wsptr += 8;
            continue;
        }
        tmp10 = ((DCTELEM)local_wsptr[0] + (DCTELEM)local_wsptr[4]);
        tmp11 = ((DCTELEM)local_wsptr[0] - (DCTELEM)local_wsptr[4]);
        tmp13 = ((DCTELEM)local_wsptr[2] + (DCTELEM)local_wsptr[6]);
        tmp12 = ((DCTELEM)((((DCTELEM)local_wsptr[2] - (DCTELEM)local_wsptr[6]) * (((INT32)362))) >> (8))) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;
        z13 = (DCTELEM)local_wsptr[5] + (DCTELEM)local_wsptr[3];
        z10 = (DCTELEM)local_wsptr[5] - (DCTELEM)local_wsptr[3];
        z11 = (DCTELEM)local_wsptr[1] + (DCTELEM)local_wsptr[7];
        z12 = (DCTELEM)local_wsptr[1] - (DCTELEM)local_wsptr[7];
        tmp7 = z11 + z13;
        tmp11 = ((DCTELEM)(((z11 - z13) * (((INT32)362))) >> (8)));
        z5 = ((DCTELEM)(((z10 + z12) * (((INT32)473))) >> (8)));
        tmp10 = ((DCTELEM)(((z12) * (((INT32)277))) >> (8))) - z5;
        tmp12 = ((DCTELEM)(((z10) * (-((INT32)669))) >> (8))) + z5;
        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 + tmp5;
        outptr[0] = range_limit[((int)((tmp0 + tmp7) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[7] = range_limit[((int)((tmp0 - tmp7) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[1] = range_limit[((int)((tmp1 + tmp6) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[6] = range_limit[((int)((tmp1 - tmp6) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[2] = range_limit[((int)((tmp2 + tmp5) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[5] = range_limit[((int)((tmp2 - tmp5) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[4] = range_limit[((int)((tmp3 + tmp4) >> (2 + 3))) & (255 * 4 + 3)];
        outptr[3] = range_limit[((int)((tmp3 - tmp4) >> (2 + 3))) & (255 * 4 + 3)];
        wsptr += 8;
    }
}
