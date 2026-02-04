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
extern INT32 tmp12;
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Use strided memory access by reordering element access with fixed stride simulation
    for (ctr = 0; ctr < 3; ctr++) {
        elemptr = sample_data[ctr] + start_col;
        // Simulate strided access: group accesses by offset instead of sequential
        const int indices[] = {0, 1, 2, 3, 4, 5};
        tmp0 = ((int)(elemptr[indices[0]])) + ((int)(elemptr[indices[5]]));
        tmp11 = ((int)(elemptr[indices[1]])) + ((int)(elemptr[indices[4]]));
        tmp2 = ((int)(elemptr[indices[2]])) + ((int)(elemptr[indices[3]]));
        tmp10 = tmp0 + tmp2;
        tmp12 = tmp0 - tmp2;
        tmp0 = ((int)(elemptr[indices[0]])) - ((int)(elemptr[indices[5]]));
        tmp1 = ((int)(elemptr[indices[1]])) - ((int)(elemptr[indices[4]]));
        tmp2 = ((int)(elemptr[indices[2]])) - ((int)(elemptr[indices[3]]));

        // Store results using direct index computation to simulate non-consecutive DCT output layout
        int out_idx[] = {0, 2, 4, 1, 3, 5};
        dataptr[out_idx[0]] = (DCTELEM)((tmp10 + tmp11 - 6 * 128) << (2 + 1));
        dataptr[out_idx[1]] = (DCTELEM)(((((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));
        dataptr[out_idx[2]] = (DCTELEM)(((((tmp10 - tmp11 - tmp11) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));
        tmp10 = (((((tmp0 + tmp2) * (((INT32)((0.366025404) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2 - 1) - 1))) >> (13 - 2 - 1));
        dataptr[out_idx[3]] = (DCTELEM)(tmp10 + ((tmp0 + tmp1) << (2 + 1)));
        dataptr[out_idx[4]] = (DCTELEM)((tmp0 - tmp1 - tmp2) << (2 + 1));
        dataptr[out_idx[5]] = (DCTELEM)(tmp10 + ((tmp2 - tmp1) << (2 + 1)));

        dataptr += 8;
    }
}
