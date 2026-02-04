#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp10;
extern INT32 z1;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect (Indexed) Memory Access Pattern
    // Replace direct strided access with indirect access via index arrays.
    // This simulates scenarios where data layout is non-contiguous or scattered.

    const int indices[] = {0, 8, 16, 24, 32, 40, 48, 56};
    for (ctr = 8; ctr > 0; ctr--) {
        int idx = indices[8 - ctr];  // Current row index

        if (ctr == 6 || ctr == 4 || ctr == 2) {
            inptr++; quantptr++; wsptr++;
            continue;
        }

        if ((inptr[indices[1]] | inptr[indices[3]] | inptr[indices[5]] | inptr[indices[7]]) == 0) {
            int dcval = (((ISLOW_MULT_TYPE)(inptr[indices[0]])) * (quantptr[indices[0]])) << 2;
            wsptr[indices[0]] = dcval;
            wsptr[indices[1]] = dcval;
            inptr++; quantptr++; wsptr++;
            continue;
        }

        z1 = (((ISLOW_MULT_TYPE)(inptr[indices[0]])) * (quantptr[indices[0]]));
        tmp10 = z1 << (13 + 2);

        z1 = (((ISLOW_MULT_TYPE)(inptr[indices[7]])) * (quantptr[indices[7]]));
        tmp0 = ((z1) * (-((INT32)5906)));

        z1 = (((ISLOW_MULT_TYPE)(inptr[indices[5]])) * (quantptr[indices[5]]));
        tmp0 += ((z1) * (((INT32)6967)));

        z1 = (((ISLOW_MULT_TYPE)(inptr[indices[3]])) * (quantptr[indices[3]]));
        tmp0 += ((z1) * (-((INT32)10426)));

        z1 = (((ISLOW_MULT_TYPE)(inptr[indices[1]])) * (quantptr[indices[1]]));
        tmp0 += ((z1) * (((INT32)29692)));

        wsptr[indices[0]] = (int)(((tmp10 + tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));
        wsptr[indices[1]] = (int)(((tmp10 - tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));

        inptr++; quantptr++; wsptr++;
    }
}
