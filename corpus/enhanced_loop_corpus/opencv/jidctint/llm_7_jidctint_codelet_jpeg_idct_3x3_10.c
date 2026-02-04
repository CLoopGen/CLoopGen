#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp12;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT32 temp_storage[3]; // Introduce local storage to alter data dependencies
for (ctr = 0; ctr < 3; ctr++, inptr++, quantptr++, wsptr++) {
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp0 <<= 13;
    tmp0 += ((INT32)1) << (13 - 2 - 1);

    tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp12 = ((tmp2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));

    // Break WAW dependency on tmp10 and tmp2 by using temporaries first
    INT32 local_tmp10 = tmp0 + tmp12;
    INT32 local_tmp2 = tmp0 - tmp12 - tmp12;

    tmp12 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp0 = ((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));

    // Store intermediate results to break RAW dependency with subsequent iterations
    temp_storage[0] = local_tmp10 + tmp0;
    temp_storage[1] = local_tmp10 - tmp0;
    temp_storage[2] = local_tmp2;

    // Final write with shifted values — introduces intra-loop dependency via temp_storage
    wsptr[3 * 0] = (int)(temp_storage[0] >> (13 - 2));
    wsptr[3 * 2] = (int)(temp_storage[1] >> (13 - 2));
    wsptr[3 * 1] = (int)(temp_storage[2] >> (13 - 2));
}
}
