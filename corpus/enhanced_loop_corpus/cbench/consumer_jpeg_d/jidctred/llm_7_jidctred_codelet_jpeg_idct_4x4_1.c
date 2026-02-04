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
INT32 temp_vals[4][4]; // Introduce local storage to break WAW and WAR dependencies
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr] + output_col;
    if ((wsptr[1] | wsptr[2] | wsptr[3] | wsptr[5] | wsptr[6] | wsptr[7]) == 0) {
        JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
        temp_vals[ctr][0] = dcval;
        temp_vals[ctr][1] = dcval;
        temp_vals[ctr][2] = dcval;
        temp_vals[ctr][3] = dcval;
        wsptr += 8;
        continue;
    }
    tmp0 = ((INT32)wsptr[0]) << (13 + 1);
    tmp2 = (((INT32)wsptr[2]) * (((INT32)15137))) + (((INT32)wsptr[6]) * (-((INT32)6270)));
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    z1 = (INT32)wsptr[7];
    z2 = (INT32)wsptr[5];
    z3 = (INT32)wsptr[3];
    z4 = (INT32)wsptr[1];
    INT32 local_tmp0 = ((z1) * (-((INT32)1730))) + ((z2) * (((INT32)11893))) + ((z3) * (-((INT32)17799))) + ((z4) * (((INT32)8697)));
    INT32 local_tmp2 = ((z1) * (-((INT32)4176))) + ((z2) * (-((INT32)4926))) + ((z3) * (((INT32)7373))) + ((z4) * (((INT32)20995)));
    temp_vals[ctr][0] = ((tmp10 + local_tmp2) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1);
    temp_vals[ctr][3] = ((tmp10 - local_tmp2) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1);
    temp_vals[ctr][1] = ((tmp12 + local_tmp0) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1);
    temp_vals[ctr][2] = ((tmp12 - local_tmp0) + (((INT32)1) << ((13 + 2 + 3 + 1) - 1))) >> (13 + 2 + 3 + 1);
    wsptr += 8;
}
// Second loop to remove loop-carried dependency and write results
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr] + output_col;
    outptr[0] = range_limit[temp_vals[ctr][0] & (255 * 4 + 3)];
    outptr[1] = range_limit[temp_vals[ctr][1] & (255 * 4 + 3)];
    outptr[2] = range_limit[temp_vals[ctr][2] & (255 * 4 + 3)];
    outptr[3] = range_limit[temp_vals[ctr][3] & (255 * 4 + 3)];
}
}
