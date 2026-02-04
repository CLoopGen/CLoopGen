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
extern INT32 tmp10;
extern int *wsptr;
extern JSAMPROW outptr;
extern JSAMPLE *range_limit;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT32 local_tmp0 = 0, local_tmp10 = 0;
JSAMPROW local_outptr[2];
JDIMENSION local_output_col = output_col;

for (ctr = 0; ctr < 2; ctr++) {
    local_outptr[ctr] = output_buf[ctr] + local_output_col;
}

for (ctr = 0; ctr < 2; ctr++) {
    JSAMPROW current_outptr = local_outptr[ctr];
    int offset = ctr * 8;
    if ((wsptr[offset + 1] | wsptr[offset + 3] | wsptr[offset + 5] | wsptr[offset + 7]) == 0) {
        JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[offset + 0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
        current_outptr[0] = dcval;
        current_outptr[1] = dcval;
        continue;
    }
    local_tmp10 = ((INT32)wsptr[offset + 0]) << (13 + 2);
    local_tmp0 = (((INT32)wsptr[offset + 7]) * (-((INT32)5906))) + 
                 (((INT32)wsptr[offset + 5]) * (((INT32)6967))) + 
                 (((INT32)wsptr[offset + 3]) * (-((INT32)10426))) + 
                 (((INT32)wsptr[offset + 1]) * (((INT32)29692)));
    current_outptr[0] = range_limit[(int)(((local_tmp10 + local_tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
    current_outptr[1] = range_limit[(int)(((local_tmp10 - local_tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
}

wsptr += 16; 
}
