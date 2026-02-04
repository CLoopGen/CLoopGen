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
for (ctr = 0; ctr < 4; ctr++) {
    outptr = output_buf[ctr] + output_col;
    if ((wsptr[1] == 0) && (wsptr[2] == 0) && (wsptr[3] == 0) && 
        (wsptr[5] == 0) && (wsptr[6] == 0) && (wsptr[7] == 0)) {
        JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[0]) + (((INT32)1) << (4))) >> 5) & 1023];
        outptr[0] = dcval;
        outptr[1] = dcval;
        outptr[2] = dcval;
        outptr[3] = dcval;
        wsptr += 8;
        continue;
    }
    if ((wsptr[0] & 1) == 0) {
        tmp0 = ((INT32)wsptr[0]) << 14;
        tmp2 = (((INT32)wsptr[2]) * 15137) + (((INT32)wsptr[6]) * (-6270));
        tmp10 = tmp0 + tmp2;
        tmp12 = tmp0 - tmp2;
    } else {
        tmp10 = ((INT32)wsptr[0]) << 14;
        tmp12 = tmp10;
    }
    z1 = (INT32)wsptr[7];
    z2 = (INT32)wsptr[5];
    z3 = (INT32)wsptr[3];
    z4 = (INT32)wsptr[1];
    tmp0 = (z1 * (-1730)) + (z2 * 11893) + (z3 * (-17799)) + (z4 * 8697);
    tmp2 = (z1 * (-4176)) + (z2 * (-4926)) + (z3 * 7373) + (z4 * 20995);
    INT32 const_offset = ((INT32)1) << 18;
    outptr[0] = range_limit[(int)(((tmp10 + tmp2) + const_offset) >> 19) & 1023];
    outptr[3] = range_limit[(int)(((tmp10 - tmp2) + const_offset) >> 19) & 1023];
    outptr[1] = range_limit[(int)(((tmp12 + tmp0) + const_offset) >> 19) & 1023];
    outptr[2] = range_limit[(int)(((tmp12 - tmp0) + const_offset) >> 19) & 1023];
    wsptr += 8;
}
}
