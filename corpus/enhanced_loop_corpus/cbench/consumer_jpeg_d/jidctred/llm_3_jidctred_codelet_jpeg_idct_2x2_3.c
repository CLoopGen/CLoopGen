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
    // Variant 2: Strided access using pointer arithmetic with fixed stride over shared buffer
    int *base_wsptr = wsptr;
    JSAMPROW out_rows[2] = { output_buf[0] + output_col, output_buf[1] + output_col };

    // Access pattern: treat wsptr as a 2D strided buffer with fixed 8-element rows
    for (int i = 0; i < 2; i++) {
        int *current_wsptr = base_wsptr + (i * 8); // Stride of 8 between iterations
        JSAMPROW outptr = out_rows[i];

        if ((current_wsptr[1] | current_wsptr[3] | current_wsptr[5] | current_wsptr[7]) == 0) {
            JSAMPLE dcval = range_limit[(int)((((INT32)current_wsptr[0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
            outptr[0] = dcval;
            outptr[1] = dcval;
            continue;
        }
        tmp10 = ((INT32)current_wsptr[0]) << (13 + 2);
        tmp0 = (((INT32)current_wsptr[7]) * (-((INT32)5906))) + 
               (((INT32)current_wsptr[5]) * (((INT32)6967))) + 
               (((INT32)current_wsptr[3]) * (-((INT32)10426))) + 
               (((INT32)current_wsptr[1]) * (((INT32)29692)));
        outptr[0] = range_limit[(int)(((tmp10 + tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)(((tmp10 - tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
    }
    wsptr += 16; // Update global pointer after strided processing
}
