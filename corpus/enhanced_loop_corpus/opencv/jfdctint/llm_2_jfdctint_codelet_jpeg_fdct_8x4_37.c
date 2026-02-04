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



void loop() {
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    DCTELEM *base_ptr = dataptr;  // Store initial pointer
    for (ctr = 8 - 1; ctr >= 0; ctr--) {
        DCTELEM *row_start = base_ptr + ctr;  // Access columns consecutively by fixing row via offset

        tmp0 = row_start[0*8] + row_start[3*8] + (((INT32)1) << (2 - 1));
        tmp1 = row_start[1*8] + row_start[2*8];
        tmp10 = row_start[0*8] - row_start[3*8];
        tmp11 = row_start[1*8] - row_start[2*8];

        row_start[0*8] = (DCTELEM)((tmp0 + tmp1) >> 2);
        row_start[2*8] = (DCTELEM)((tmp0 - tmp1) >> 2);

        tmp0 = ((tmp10 + tmp11) * ((INT32)4433));
        tmp0 += ((INT32)1) << (13 + 2 - 1);
        row_start[1*8] = (DCTELEM)((tmp0 + (tmp10 * ((INT32)6270))) >> (13 + 2));
        row_start[3*8] = (DCTELEM)((tmp0 - (tmp11 * ((INT32)15137))) >> (13 + 2));
    }
}
