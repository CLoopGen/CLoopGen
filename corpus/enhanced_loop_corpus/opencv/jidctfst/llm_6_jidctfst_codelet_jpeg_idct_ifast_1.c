#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long JLONG;

typedef JLONG DCTELEM;

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



void loop(){
for (ctr = 0; ctr < 8; ctr++) {
    outptr = output_buf[ctr] + output_col;
    if (wsptr[1] == 0 && wsptr[2] == 0 && wsptr[3] == 0 && wsptr[4] == 0 && wsptr[5] == 0 && wsptr[6] == 0 && wsptr[7] == 0) {
        JSAMPLE dcval = range_limit[((int)((wsptr[0]) >> (1 + 3))) & (255 * 4 + 3)];
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
    DCTELEM ws0 = wsptr[0], ws1 = wsptr[1], ws2 = wsptr[2], ws3 = wsptr[3];
    DCTELEM ws4 = wsptr[4], ws5 = wsptr[5], ws6 = wsptr[6], ws7 = wsptr[7];

    tmp10 = ws0 + ws4;
    tmp11 = ws0 - ws4;
    tmp13 = ws2 + ws6;
    tmp12 = (((ws2 - ws6) * 362LL) >> 8) - tmp13;

    tmp0 = tmp10 + tmp13;
    tmp3 = tmp10 - tmp13;
    tmp1 = tmp11 + tmp12;
    tmp2 = tmp11 - tmp12;

    z13 = ws5 + ws3;
    z10 = ws5 - ws3;
    z11 = ws1 + ws7;
    z12 = ws1 - ws7;

    tmp7 = z11 + z13;
    tmp11 = ((z11 - z13) * 362LL) >> 8;
    z5 = ((z10 + z12) * 473LL) >> 8;
    tmp10 = ((z12 * 277LL) >> 8) - z5;
    tmp12 = ((z10 * (-669LL)) >> 8) + z5;
    tmp6 = tmp12 - tmp7;
    tmp5 = tmp11 - tmp6;
    tmp4 = tmp10 + tmp5;

    outptr[0] = range_limit[((int)((tmp0 + tmp7) >> 4)) & 1023];
    outptr[7] = range_limit[((int)((tmp0 - tmp7) >> 4)) & 1023];
    outptr[1] = range_limit[((int)((tmp1 + tmp6) >> 4)) & 1023];
    outptr[6] = range_limit[((int)((tmp1 - tmp6) >> 4)) & 1023];
    outptr[2] = range_limit[((int)((tmp2 + tmp5) >> 4)) & 1023];
    outptr[5] = range_limit[((int)((tmp2 - tmp5) >> 4)) & 1023];
    outptr[4] = range_limit[((int)((tmp3 + tmp4) >> 4)) & 1023];
    outptr[3] = range_limit[((int)((tmp3 - tmp4) >> 4)) & 1023];

    wsptr += 8;
}
}
