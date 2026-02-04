#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

extern JSAMPARRAY output_buf;
extern JDIMENSION output_col;
extern INT32 tmp0;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp12;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT32 local_wsptr[8];
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr] + output_col;
    for (int i = 0; i < 8; i++) {
        local_wsptr[i] = wsptr[i];
    }
    if ((local_wsptr[1] | local_wsptr[2] | local_wsptr[3] | local_wsptr[5] | local_wsptr[6] | local_wsptr[7]) == 0) {
        JSAMPLE dcval = range_limit[(int)((((INT32)local_wsptr[0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
        outptr[0] = dcval;
        outptr[1] = dcval;
        outptr[2] = dcval;
        outptr[3] = dcval;
    } else {
        INT32 t0 = ((INT32)local_wsptr[0]) << (13 + 1);
        INT32 t2 = (((INT32)local_wsptr[2]) * (((INT32)15137))) + (((INT32)local_wsptr[6]) * (-((INT32)6270)));
        INT32 t10 = t0 + t2;
        INT32 t12 = t0 - t2;
        INT32 z1 = (INT32)local_wsptr[7];
        INT32 z2 = (INT32)local_wsptr[5];
        INT32 z3 = (INT32)local_wsptr[3];
        INT32 z4 = (INT32)local_wsptr[1];
        INT32 p0 = ((z1) * (-((INT32)1730))) + ((z2) * (((INT32)11893))) + ((z3) * (-((INT32)17799))) + ((z4) * (((INT32)8697)));
        INT32 p2 = ((z1) * (-((INT32)4176))) + ((z2) * (-((INT32)4926))) + ((z3) * (((INT32)7373))) + ((z4) * (((INT32)20995)));
        outptr[0] = range_limit[(int)(((t10 + p2) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1)) & (255 * 4 + 3)];
        outptr[3] = range_limit[(int)(((t10 - p2) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)(((t12 + p0) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1)) & (255 * 4 + 3)];
        outptr[2] = range_limit[(int)(((t12 - p0) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1)) & (255 * 4 + 3)];
    }
    wsptr += 8;
}

}
