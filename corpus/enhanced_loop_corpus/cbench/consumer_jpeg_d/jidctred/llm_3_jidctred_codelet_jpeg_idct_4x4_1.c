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
int indices[8] = {0, 1, 2, 3, 5, 6, 7, 4}; // Reordered access pattern: prioritize non-zero check elements early
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr] + output_col;
    int base_idx = ctr * 8;
    if ((wsptr[base_idx + indices[1]] | wsptr[base_idx + indices[2]] | wsptr[base_idx + indices[3]] |
         wsptr[base_idx + indices[4]] | wsptr[base_idx + indices[5]] | wsptr[base_idx + indices[6]]) == 0) {
        JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[base_idx + indices[0]]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
        outptr[0] = dcval;
        outptr[1] = dcval;
        outptr[2] = dcval;
        outptr[3] = dcval;
        continue;
    }
    tmp0 = ((INT32)wsptr[base_idx + indices[0]]) << (13 + 1);
    tmp2 = (((INT32)wsptr[base_idx + 2]) * (((INT32)15137))) + (((INT32)wsptr[base_idx + 6]) * (-((INT32)6270)));
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    z1 = (INT32)wsptr[base_idx + 7];
    z2 = (INT32)wsptr[base_idx + 5];
    z3 = (INT32)wsptr[base_idx + 3];
    z4 = (INT32)wsptr[base_idx + 1];
    tmp0 = ((z1) * (-((INT32)1730))) + ((z2) * (((INT32)11893))) + ((z3) * (-((INT32)17799))) + ((z4) * (((INT32)8697)));
    tmp2 = ((z1) * (-((INT32)4176))) + ((z2) * (-((INT32)4926))) + ((z3) * (((INT32)7373))) + ((z4) * (((INT32)20995)));
    outptr[0] = range_limit[(int)(((tmp10 + tmp2) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1)) & (255 * 4 + 3)];
    outptr[3] = range_limit[(int)(((tmp10 - tmp2) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1)) & (255 * 4 + 3)];
    outptr[1] = range_limit[(int)(((tmp12 + tmp0) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1)) & (255 * 4 + 3)];
    outptr[2] = range_limit[(int)(((tmp12 - tmp0) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1)) & (255 * 4 + 3)];
}
}
