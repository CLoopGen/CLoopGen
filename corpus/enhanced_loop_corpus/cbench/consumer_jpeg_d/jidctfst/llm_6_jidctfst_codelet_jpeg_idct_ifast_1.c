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
        // Introduce local copy to eliminate potential WAW and WAR hazards with wsptr across iterations
        for (int i = 0; i < 8; ++i) {
            local_wsptr[i] = wsptr[i];
        }

        if ((local_wsptr[1] | local_wsptr[2] | local_wsptr[3] | local_wsptr[4] |
             local_wsptr[5] | local_wsptr[6] | local_wsptr[7]) == 0) {
            JSAMPLE dcval = range_limit[((int)((local_wsptr[0]) >> (2 + 3))) & (255 * 4 + 3)];
            // Unroll assignments to break potential loop-carried dependency through memory
            outptr[0] = dcval;
            outptr[1] = dcval;
            outptr[2] = dcval;
            outptr[3] = dcval;
            outptr[4] = dcval;
            outptr[5] = dcval;
            outptr[6] = dcval;
            outptr[7] = dcval;
            // Update shared pointer only at the end to reduce interference
            wsptr += 8;
            continue;
        }

        // Rearranged computation to minimize temporary reuse (reduce WAW on tmp variables)
        DCTELEM t10 = local_wsptr[0] + local_wsptr[4];
        DCTELEM t11 = local_wsptr[0] - local_wsptr[4];
        DCTELEM t13 = local_wsptr[2] + local_wsptr[6];
        DCTELEM t12 = (((DCTELEM)(local_wsptr[2] - local_wsptr[6]) * 362) >> 8) - t13;

        DCTELEM t0 = t10 + t13;
        DCTELEM t3 = t10 - t13;
        DCTELEM t1 = t11 + t12;
        DCTELEM t2 = t11 - t12;

        DCTELEM z13 = local_wsptr[5] + local_wsptr[3];
        DCTELEM z10 = local_wsptr[5] - local_wsptr[3];
        DCTELEM z11 = local_wsptr[1] + local_wsptr[7];
        DCTELEM z12 = local_wsptr[1] - local_wsptr[7];

        DCTELEM t7 = z11 + z13;
        DCTELEM t11b = ((DCTELEM)((z11 - z13) * 362) >> 8);
        DCTELEM z5 = ((DCTELEM)((z10 + z12) * 473) >> 8);

        DCTELEM t10b = ((DCTELEM)(z12 * 277) >> 8) - z5;
        DCTELEM t12b = ((DCTELEM)(z10 * (-669)) >> 8) + z5;

        DCTELEM t6 = t12b - t7;
        DCTELEM t5 = t11b - t6;
        DCTELEM t4 = t10b + t5;

        outptr[0] = range_limit[((int)((t0 + t7) >> 5)) & 1023];
        outptr[7] = range_limit[((int)((t0 - t7) >> 5)) & 1023];
        outptr[1] = range_limit[((int)((t1 + t6) >> 5)) & 1023];
        outptr[6] = range_limit[((int)((t1 - t6) >> 5)) & 1023];
        outptr[2] = range_limit[((int)((t2 + t5) >> 5)) & 1023];
        outptr[5] = range_limit[((int)((t2 - t5) >> 5)) & 1023];
        outptr[4] = range_limit[((int)((t3 + t4) >> 5)) & 1023];
        outptr[3] = range_limit[((int)((t3 - t4) >> 5)) & 1023];

        wsptr += 8;
    }
}
