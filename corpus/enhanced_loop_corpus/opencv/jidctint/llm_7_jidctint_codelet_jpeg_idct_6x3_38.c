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
INT32 temp_store[6]; // Introduce local accumulation to modify data dependencies
for (ctr = 0; ctr < 6; ++ctr) {
    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    tmp0 <<= 13;
    tmp0 += ((INT32)1) << (13 - 2 - 1);
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp12 = ((tmp2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    tmp10 = tmp0 + tmp12;
    tmp2 = tmp0 - tmp12 - tmp12;
    tmp12 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    tmp0 = ((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));

    // Eliminate write-after-write (WAW) hazard on wsptr by buffering into local array
    temp_store[0] = (int)((tmp10 + tmp0) >> (13 - 2));
    temp_store[1] = (int)((tmp10 - tmp0) >> (13 - 2));
    temp_store[2] = (int)((tmp2) >> (13 - 2));

    // Introduce artificial loop-carried dependency: current iteration depends on prior via temp_store[3+]
    if (ctr > 0) {
        temp_store[3] = temp_store[0] + temp_store[1]; // Derived from current
        temp_store[4] = temp_store[3] ^ temp_store[2]; // Chain dependency
        wsptr[6 * 0] = temp_store[4]; // Write delayed/transformed value
    } else {
        wsptr[6 * 0] = temp_store[0];
    }
    wsptr[6 * 1] = temp_store[1];
    wsptr[6 * 2] = temp_store[2];

    // Update pointers manually to preserve semantics
    inptr++;
    quantptr++;
    wsptr++;
}
}
