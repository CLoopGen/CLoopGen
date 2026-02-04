#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp10;
extern JLONG z1;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Pointer-Jumping) Memory Access Pattern
    // Replace constant stride (8*i) with pointer arithmetic using an array of pointers.
    // Simulates irregular access patterns common in sparse data structures.

    JCOEFPTR in_offsets[8];
    ISLOW_MULT_TYPE *quant_offsets[8];
    int *ws_offsets[8];

    // Precompute indirect pointers for non-consecutive access
    for (int i = 0; i < 8; i++) {
        in_offsets[i]   = &inptr[8 * i];
        quant_offsets[i] = &quantptr[8 * i];
        ws_offsets[i]    = &wsptr[8 * i];
    }

    for (ctr = 8; ctr > 0; inptr++, quantptr++, wsptr++, ctr--) {
        int i = 8 - ctr;

        if (i == 2 || i == 4 || i == 6)
            continue;

        if (*(in_offsets[i]) == 0 && *(in_offsets[i+1]) == 0 && *(in_offsets[i+2]) == 0 && *(in_offsets[i+3]) == 0) {
            int dcval = ((JLONG)((unsigned long)((((ISLOW_MULT_TYPE)(*(in_offsets[i]))) * (*(quant_offsets[i])))) << (1)));
            *(ws_offsets[i]) = dcval;
            *(ws_offsets[i]+8) = dcval;
            continue;
        }

        z1 = (((ISLOW_MULT_TYPE)(*(in_offsets[i]))) * (*(quant_offsets[i])));
        tmp10 = ((JLONG)((unsigned long)(z1) << (13 + 2)));

        z1 = (((ISLOW_MULT_TYPE)(*(in_offsets[7]))) * (*(quant_offsets[7])));
        tmp0 = ((z1) * (-((JLONG)5906)));

        z1 = (((ISLOW_MULT_TYPE)(*(in_offsets[5]))) * (*(quant_offsets[5])));
        tmp0 += ((z1) * (((JLONG)6967)));

        z1 = (((ISLOW_MULT_TYPE)(*(in_offsets[3]))) * (*(quant_offsets[3])));
        tmp0 += ((z1) * (-((JLONG)10426)));

        z1 = (((ISLOW_MULT_TYPE)(*(in_offsets[1]))) * (*(quant_offsets[1])));
        tmp0 += ((z1) * (((JLONG)29692)));

        *(ws_offsets[i])     = (int)(((tmp10 + tmp0) + (((JLONG)1) << ((13 - 1 + 2) - 1))) >> (13 - 1 + 2));
        *(ws_offsets[i]+8)   = (int)(((tmp10 - tmp0) + (((JLONG)1) << ((13 - 1 + 2) - 1))) >> (13 - 1 + 2));
    }
}
