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
    // Consecutive memory access: pre-load values from wsptr into local array to enable linear traversal
    int local_wsp[16]; // Double buffer size to support two iterations
    for (int i = 0; i < 16; i++) {
        local_wsp[i] = wsptr[i];
    }

    for (ctr = 0; ctr < 2; ctr++) {
        outptr = output_buf[ctr] + output_col;
        int base = ctr * 8; // Consecutive block access: each iteration uses consecutive 8 elements

        if ((local_wsp[base + 1] | local_wsp[base + 3] | local_wsp[base + 5] | local_wsp[base + 7]) == 0) {
            JSAMPLE dcval = range_limit[(int)((((INT32)local_wsp[base + 0]) + (((INT32)1) << ((2 + 3) - 1))) >> (2 + 3)) & (255 * 4 + 3)];
            outptr[0] = dcval;
            outptr[1] = dcval;
            continue;
        }
        tmp10 = ((INT32)local_wsp[base + 0]) << (13 + 2);
        tmp0 = (((INT32)local_wsp[base + 7]) * (-((INT32)5906))) + 
               (((INT32)local_wsp[base + 5]) * (((INT32)6967))) + 
               (((INT32)local_wsp[base + 3]) * (-((INT32)10426))) + 
               (((INT32)local_wsp[base + 1]) * (((INT32)29692)));
        outptr[0] = range_limit[(int)(((tmp10 + tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
        outptr[1] = range_limit[(int)(((tmp10 - tmp0) + (((INT32)1) << ((13 + 2 + 3 + 2) - 1))) >> (13 + 2 + 3 + 2)) & (255 * 4 + 3)];
    }
}
