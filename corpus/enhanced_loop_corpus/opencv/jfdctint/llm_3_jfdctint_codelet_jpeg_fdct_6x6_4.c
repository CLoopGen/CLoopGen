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



void loop(){
// Use indirect memory access via index array to simulate non-sequential, scattered read pattern
static const int idx_map[6][6] = {
    {0, 5, 1, 4, 2, 3},
    {1, 4, 2, 3, 0, 5},
    {2, 3, 0, 5, 1, 4},
    {3, 2, 4, 1, 5, 0},
    {4, 1, 5, 0, 3, 2},
    {5, 0, 3, 2, 4, 1}
};
for (ctr = 0; ctr < 6; ctr++) {
    elemptr = sample_data[ctr] + start_col;
    const int* idx = idx_map[ctr];
    tmp0 = ((int)(elemptr[idx[0]])) + ((int)(elemptr[idx[1]]));
    tmp11 = ((int)(elemptr[idx[2]])) + ((int)(elemptr[idx[3]]));
    tmp2 = ((int)(elemptr[idx[4]])) + ((int)(elemptr[idx[5]]));
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    tmp0 = ((int)(elemptr[idx[0]])) - ((int)(elemptr[idx[1]]));
    tmp1 = ((int)(elemptr[idx[2]])) - ((int)(elemptr[idx[3]]));
    tmp2 = ((int)(elemptr[idx[4]])) - ((int)(elemptr[idx[5]]));
    dataptr[0] = (DCTELEM)((tmp10 + tmp11 - 6 * 128) << 2);
    dataptr[2] = (DCTELEM)(((((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[4] = (DCTELEM)(((((tmp10 - tmp11 - tmp11) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    tmp10 = (((((tmp0 + tmp2) * (((INT32)((0.366025404) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[1] = (DCTELEM)(tmp10 + ((tmp0 + tmp1) << 2));
    dataptr[3] = (DCTELEM)((tmp0 - tmp1 - tmp2) << 2);
    dataptr[5] = (DCTELEM)(tmp10 + ((tmp2 - tmp1) << 2));
    dataptr += 8;
}
}
