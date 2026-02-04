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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize array accesses to use local stride-1 (consecutive) indexing by precomputing base offsets.
    // This improves cache locality by accessing memory in a more sequential manner.

    int offset = 0;
    for (ctr = 8; ctr > 0; ctr--, offset += 8) {
        if (ctr == 6 || ctr == 4 || ctr == 2)
            continue;

        JCOEFPTR ip = inptr + offset;
        ISLOW_MULT_TYPE *qp = quantptr + offset;
        int *wp = wsptr + offset;

        if ((ip[8] | ip[24] | ip[40] | ip[56]) == 0) {
            int dcval = (((ISLOW_MULT_TYPE)(ip[0])) * (qp[0])) << 2;
            wp[0] = dcval;
            wp[8] = dcval;
            continue;
        }

        z1 = (((ISLOW_MULT_TYPE)(ip[0])) * (qp[0]));
        tmp10 = z1 << (13 + 2);
        z1 = (((ISLOW_MULT_TYPE)(ip[56])) * (qp[56]));
        tmp0 = ((z1) * (-((INT32)5906)));
        z1 = (((ISLOW_MULT_TYPE)(ip[40])) * (qp[40]));
        tmp0 += ((z1) * (((INT32)6967)));
        z1 = (((ISLOW_MULT_TYPE)(ip[24])) * (qp[24]));
        tmp0 += ((z1) * (-((INT32)10426)));
        z1 = (((ISLOW_MULT_TYPE)(ip[8])) * (qp[8]));
        tmp0 += ((z1) * (((INT32)29692)));

        wp[0] = (int)(((tmp10 + tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));
        wp[8] = (int)(((tmp10 - tmp0) + (((INT32)1) << ((13 - 2 + 2) - 1))) >> (13 - 2 + 2));
    }
}
