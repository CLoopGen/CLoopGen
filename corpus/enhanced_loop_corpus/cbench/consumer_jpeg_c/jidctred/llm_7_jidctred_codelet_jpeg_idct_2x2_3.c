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



void loop() {
    // Eliminate loop-carried dependencies entirely and unroll the loop manually
    // Transform into two independent iterations with no shared state between them

    // First "iteration" (ctr = 0)
    {
        outptr = output_buf[0] + output_col;
        if ((wsptr[1] | wsptr[3] | wsptr[5] | wsptr[7]) == 0) {
            JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
            outptr[0] = dcval;
            outptr[1] = dcval;
        } else {
            INT32 local_tmp10 = ((INT32)wsptr[0]) << (13 + 2);
            INT32 local_tmp0 = (((INT32)wsptr[7]) * (-((INT32)5906))) + 
                               (((INT32)wsptr[5]) * (((INT32)6967))) + 
                               (((INT32)wsptr[3]) * (-((INT32)10426))) + 
                               (((INT32)wsptr[1]) * (((INT32)29692)));
            outptr[0] = range_limit[(int)(((local_tmp10 + local_tmp0) + (((INT32)1) << (18 - 1))) >> 18) & (255 * 4 + 3)];
            outptr[1] = range_limit[(int)(((local_tmp10 - local_tmp0) + (((INT32)1) << (18 - 1))) >> 18) & (255 * 4 + 3)];
        }
        wsptr += 8;
    }

    // Second "iteration" (ctr = 1)
    {
        JSAMPROW local_outptr = output_buf[1] + output_col;  // Use local pointer to avoid reuse
        if ((wsptr[1] | wsptr[3] | wsptr[5] | wsptr[7]) == 0) {
            JSAMPLE dcval = range_limit[(int)((((INT32)wsptr[0]) + (((INT32)1) << (4)) >> 5)) & 1023];
            local_outptr[0] = dcval;
            local_outptr[1] = dcval;
        } else {
            INT32 local_tmp10 = ((INT32)wsptr[0]) << 15;
            INT32 local_tmp0 = (((INT32)wsptr[7]) * (-5906)) + 
                               (((INT32)wsptr[5]) * 6967) + 
                               (((INT32)wsptr[3]) * (-10426)) + 
                               (((INT32)wsptr[1]) * 29692);
            INT32 shifted_val = (1 << 17);
            local_outptr[0] = range_limit[(int)(((local_tmp10 + local_tmp0) + shifted_val) >> 18) & 1023];
            local_outptr[1] = range_limit[(int)(((local_tmp10 - local_tmp0) + shifted_val) >> 18) & 1023];
        }
        wsptr += 8;
    }
}
