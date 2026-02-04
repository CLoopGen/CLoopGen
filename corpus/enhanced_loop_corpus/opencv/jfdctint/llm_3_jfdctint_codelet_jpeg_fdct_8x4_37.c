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
    // Variant 2: Strided Access with Reverse Indexing and Fixed Step
    DCTELEM *ptr = dataptr;
    for (ctr = 0; ctr < 8; ctr++) {
        int idx = (7 - ctr) * 8;  // Reverse traversal using computed index with stride of 8

        tmp0 = ptr[idx + 0] + ptr[idx + 24] + (((INT32)1) << (2 - 1));  // 0*8 and 3*8 offset
        tmp1 = ptr[idx + 8] + ptr[idx + 16];                             // 1*8 and 2*8 offset
        tmp10 = ptr[idx + 0] - ptr[idx + 24];
        tmp11 = ptr[idx + 8] - ptr[idx + 16];

        ptr[idx + 0] = (DCTELEM)((tmp0 + tmp1) >> 2);
        ptr[idx + 16] = (DCTELEM)((tmp0 - tmp1) >> 2);  // Writing to [2]

        tmp0 = ((tmp10 + tmp11) * ((INT32)4433));
        tmp0 += ((INT32)1) << (13 + 2 - 1);
        ptr[idx + 8] = (DCTELEM)((tmp0 + (tmp10 * ((INT32)6270))) >> (13 + 2));
        ptr[idx + 24] = (DCTELEM)((tmp0 - (tmp11 * ((INT32)15137))) >> (13 + 2));
    }
}
