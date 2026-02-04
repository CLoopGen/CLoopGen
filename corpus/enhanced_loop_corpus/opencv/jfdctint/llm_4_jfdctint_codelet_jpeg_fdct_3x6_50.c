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
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Strided memory access: process every second element in a transposed manner
for (ctr = 0; ctr < 6; ctr += 2) {
    // Handle two rows at once with strided pointer updates
    JSAMPROW row0 = sample_data[ctr] + start_col;
    JSAMPROW row1 = (ctr + 1 < 6) ? sample_data[ctr + 1] + start_col : row0;
    
    // Process row0
    tmp0 = ((int)(row0[0])) + ((int)(row0[2]));
    tmp1 = ((int)(row0[1]));
    tmp2 = ((int)(row0[0])) - ((int)(row0[2]));
    dataptr[0] = (DCTELEM)((tmp0 + tmp1 - 3 * 128) << 3);
    dataptr[2] = (DCTELEM)((((tmp0 - 2*tmp1) * (INT32)(0.707106781 * (1<<13) + 0.5)) + (1 << 10)) >> 11);
    dataptr[1] = (DCTELEM)(((tmp2 * (INT32)(1.224744871 * (1<<13) + 0.5)) + (1 << 10)) >> 11);

    // Process row1 if valid
    if (ctr + 1 < 6) {
        tmp0 = ((int)(row1[0])) + ((int)(row1[2]));
        tmp1 = ((int)(row1[1]));
        tmp2 = ((int)(row1[0])) - ((int)(row1[2]));
        dataptr[8] = (DCTELEM)((tmp0 + tmp1 - 3 * 128) << 3);
        dataptr[10] = (DCTELEM)((((tmp0 - 2*tmp1) * (INT32)(0.707106781 * (1<<13) + 0.5)) + (1 << 10)) >> 11);
        dataptr[9] = (DCTELEM)(((tmp2 * (INT32)(1.224744871 * (1<<13) + 0.5)) + (1 << 10)) >> 11);
    }
    dataptr += 16; // Advance by two blocks of 8
}
}
