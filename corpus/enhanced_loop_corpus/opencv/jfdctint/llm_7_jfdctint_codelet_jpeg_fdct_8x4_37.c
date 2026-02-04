#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp10;
extern INT32 tmp11;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Introduce loop-carried dependency via cumulative variable
INT32 carry = 0;
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    // Modify data flow: make current iteration depend on previous via 'carry'
    tmp0 = (dataptr[8 * 0] + dataptr[8 * 3] + carry + (((INT32)1) << (2 - 1)));
    tmp1 = dataptr[8 * 1] + dataptr[8 * 2];
    tmp10 = dataptr[8 * 0] - dataptr[8 * 3];
    tmp11 = dataptr[8 * 1] - dataptr[8 * 2];

    // Update carry for next iteration (creates RAW loop-carried dependency)
    carry = (tmp0 & 0xF) << 2;  // Trivial but valid dependency

    dataptr[8 * 0] = (DCTELEM)((tmp0 + tmp1) >> 2);
    dataptr[8 * 2] = (DCTELEM)((tmp0 - tmp1) >> 2);

    tmp0 = ((tmp10 + tmp11) * (((INT32)4433)));
    tmp0 += ((INT32)1) << (13 + 2 - 1);

    // Reorder operations slightly and use updated tmp0 after modification
    dataptr[8 * 1] = (DCTELEM)((tmp0 + (tmp10 * ((INT32)6270))) >> (13 + 2));
    dataptr[8 * 3] = (DCTELEM)((tmp0 - (tmp11 * ((INT32)15137))) >> (13 + 2));

    dataptr++;
}
}
