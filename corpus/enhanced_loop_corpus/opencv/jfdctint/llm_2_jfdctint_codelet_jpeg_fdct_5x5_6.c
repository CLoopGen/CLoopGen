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
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Array Reindexing
    // Instead of using separate array accesses via sample_data[ctr], we precompute a base pointer
    // and access elements consecutively with fixed offsets, improving spatial locality.
    JSAMPROW base_ptr;
    for (ctr = 0; ctr < 5; ctr++) {
        base_ptr = sample_data[ctr] + start_col;
        // Load all required samples in increasing index order for better cache behavior
        JSAMPLE s0 = base_ptr[0];
        JSAMPLE s1 = base_ptr[1];
        JSAMPLE s2 = base_ptr[2];
        JSAMPLE s3 = base_ptr[3];
        JSAMPLE s4 = base_ptr[4];

        tmp0 = ((int)s0) + ((int)s4);
        tmp1 = ((int)s1) + ((int)s3);
        tmp2 = ((int)s2);
        tmp10 = tmp0 + tmp1;
        tmp11 = tmp0 - tmp1;
        tmp0 = ((int)s0) - ((int)s4);
        tmp1 = ((int)s1) - ((int)s3);

        dataptr[0] = (DCTELEM)((tmp10 + tmp2 - 5 * 128) << (2 + 1));
        
        tmp11 = ((tmp11) * (((INT32)((0.790569415) * (((INT32)1) << 13) + 0.5))));
        tmp10 -= tmp2 << 2;
        tmp10 = ((tmp10) * (((INT32)((0.35355339099999999) * (((INT32)1) << 13) + 0.5))));

        dataptr[2] = (DCTELEM)(((tmp11 + tmp10) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));
        dataptr[4] = (DCTELEM)(((tmp11 - tmp10) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));

        tmp10 = ((tmp0 + tmp1) * (((INT32)((0.831253876) * (((INT32)1) << 13) + 0.5))));
        dataptr[1] = (DCTELEM)(((tmp10 + ((tmp0) * (((INT32)((0.51374314799999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));
        dataptr[3] = (DCTELEM)(((tmp10 - ((tmp1) * (((INT32)((2.1762508989999998) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));

        dataptr += 8;
    }
}
