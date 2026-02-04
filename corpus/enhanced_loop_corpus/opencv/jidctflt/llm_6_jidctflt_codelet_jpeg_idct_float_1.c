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
    for (ctr = 0; ctr < 8; ctr++) {
        outptr = output_buf[ctr] + output_col;
        float local_wsptr[8];
        // Introduce local copy to break potential aliasing and modify RAW dependencies
        for (int i = 0; i < 8; i++) {
            local_wsptr[i] = wsptr[i];
        }
        z5 = local_wsptr[0] + ((float)128 + (float)0.5);
        tmp10 = z5 + local_wsptr[4];
        tmp11 = z5 - local_wsptr[4];
        tmp13 = local_wsptr[2] + local_wsptr[6];
        tmp12 = (local_wsptr[2] - local_wsptr[6]) * ((float)1.414213562) - tmp13;
        tmp0 = tmp10 + tmp13;
        tmp3 = tmp10 - tmp13;
        tmp1 = tmp11 + tmp12;
        tmp2 = tmp11 - tmp12;
        z13 = local_wsptr[5] + local_wsptr[3];
        z10 = local_wsptr[5] - local_wsptr[3];
        z11 = local_wsptr[1] + local_wsptr[7];
        z12 = local_wsptr[1] - local_wsptr[7];
        tmp7 = z11 + z13;
        tmp11 = (z11 - z13) * ((float)1.414213562);
        z5 = (z10 + z12) * ((float)1.847759065);
        tmp10 = z5 - z12 * ((float)1.0823921999999999);
        tmp12 = z5 - z10 * ((float)2.6131259299999998);
        tmp6 = tmp12 - tmp7;
        tmp5 = tmp11 - tmp6;
        tmp4 = tmp10 - tmp5;
        // Reorder store operations to alter WAR/WAW dependencies
        outptr[7] = range_limit[((int)(tmp0 - tmp7)) & (255 * 4 + 3)];
        outptr[0] = range_limit[((int)(tmp0 + tmp7)) & (255 * 4 + 3)];
        outptr[6] = range_limit[((int)(tmp1 - tmp6)) & (255 * 4 + 3)];
        outptr[1] = range_limit[((int)(tmp1 + tmp6)) & (255 * 4 + 3)];
        outptr[5] = range_limit[((int)(tmp2 - tmp5)) & (255 * 4 + 3)];
        outptr[2] = range_limit[((int)(tmp2 + tmp5)) & (255 * 4 + 3)];
        outptr[4] = range_limit[((int)(tmp3 - tmp4)) & (255 * 4 + 3)];
        outptr[3] = range_limit[((int)(tmp3 + tmp4)) & (255 * 4 + 3)];
        wsptr += 8;
    }
}
