#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp12;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Eliminate loop-carried dependencies by unrolling and using independent accumulators per iteration
    // Use local temporaries to break potential RAW/WAR hazards across iterations

    int local_ctr = 8;
    JCOEFPTR local_inptr = inptr;
    ISLOW_MULT_TYPE *local_quantptr = quantptr;
    int *local_wsptr = wsptr;

    for (; local_ctr > 0; local_inptr++, local_quantptr++, local_wsptr++, local_ctr--) {
        if (local_ctr == 8 - 4)
            continue;

        // Use local computation variables to remove cross-iteration dependencies on global temps
        INT32 t0, t2, t10, t12, y1, y2, y3, y4;

        if ((local_inptr[8 * 1] | local_inptr[8 * 2] | local_inptr[8 * 3] | 
             local_inptr[8 * 5] | local_inptr[8 * 6] | local_inptr[8 * 7]) == 0) {
            int dcval = (((ISLOW_MULT_TYPE)(local_inptr[8 * 0])) * (*local_quantptr)) << 2;
            local_wsptr[8 * 0] = dcval;
            local_wsptr[8 * 1] = dcval;
            local_wsptr[8 * 2] = dcval;
            local_wsptr[8 * 3] = dcval;
            continue;
        }

        t0 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 0])) * (*local_quantptr));
        t0 <<= (13 + 1);
        y2 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 2])) * (local_quantptr[8 * 2]));
        y3 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 6])) * (local_quantptr[8 * 6]));
        t2 = ((y2) * (((INT32)15137))) + ((y3) * (-((INT32)6270)));
        t10 = t0 + t2;
        t12 = t0 - t2;
        y1 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 7])) * (local_quantptr[8 * 7]));
        y2 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 5])) * (local_quantptr[8 * 5]));
        y3 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 3])) * (local_quantptr[8 * 3]));
        y4 = (((ISLOW_MULT_TYPE)(local_inptr[8 * 1])) * (local_quantptr[8 * 1]));

        t0 = ((y1) * (-((INT32)1730))) + ((y2) * (((INT32)11893))) + ((y3) * (-((INT32)17799))) + ((y4) * (((INT32)8697)));
        t2 = ((y1) * (-((INT32)4176))) + ((y2) * (-((INT32)4926))) + ((y3) * (((INT32)7373))) + ((y4) * (((INT32)20995)));

        // All computations use local temporaries — no interference with other iterations
        local_wsptr[8 * 0] = (int)(((t10 + t2) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
        local_wsptr[8 * 3] = (int)(((t10 - t2) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
        local_wsptr[8 * 1] = (int)(((t12 + t0) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
        local_wsptr[8 * 2] = (int)(((t12 - t0) + (((INT32)1) << ((13 - 2 + 1) - 1))) >> (13 - 2 + 1));
    }

    // Update global pointers after loop (if needed elsewhere, though not visible here)
    inptr = local_inptr;
    quantptr = local_quantptr;
    wsptr = local_wsptr;
}
