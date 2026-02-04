#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

typedef int DCTELEM;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp11;
extern DCTELEM workspace[16];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic with pre-increment
    JSAMPROW base_ptr;
    DCTELEM *outptr = dataptr;
    for (;;) {
        base_ptr = sample_data[ctr] + start_col;
        // Load all required elements consecutively into temporaries
        JSAMPLE e0 = base_ptr[0], e1 = base_ptr[1], e2 = base_ptr[2], e3 = base_ptr[3], e4 = base_ptr[4];
        
        tmp0 = ((int)e0) + ((int)e4);
        tmp1 = ((int)e1) + ((int)e3);
        tmp2 = ((int)e2);
        tmp10 = tmp0 + tmp1;
        tmp11 = tmp0 - tmp1;
        tmp0 = ((int)e0) - ((int)e4);
        tmp1 = ((int)e1) - ((int)e3);
        
        outptr[0] = (DCTELEM)((tmp10 + tmp2 - 5 * 128) << 2);
        
        tmp11 = ((tmp11) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
        tmp10 -= tmp2 << 2;
        tmp10 = ((tmp10) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));
        
        outptr[2] = (DCTELEM)(((tmp11 + tmp10) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        outptr[4] = (DCTELEM)(((tmp11 - tmp10) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        
        tmp10 = ((tmp0 + tmp1) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
        outptr[1] = (DCTELEM)(((tmp10 + ((tmp0) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        outptr[3] = (DCTELEM)(((tmp10 - ((tmp1) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
        
        ctr++;
        if (ctr != 8) {
            if (ctr == 10)
                break;
            outptr += 8;
        } else
            outptr = workspace;
    }
}
