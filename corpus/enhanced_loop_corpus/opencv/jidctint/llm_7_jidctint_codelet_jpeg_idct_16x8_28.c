#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 8; ctr > 0; ctr--) {
    int local_dcval, skip_computation = 0;
    // Eliminate loop-carried dependencies entirely by using local accumulation
    // All writes to wsptr are now independent across iterations

    if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 && inptr[8 * 4] == 0 && inptr[8 * 5] == 0 && inptr[8 * 6] == 0 && inptr[8 * 7] == 0) {
        local_dcval = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) << 2;
        // Write all outputs at once without any intermediate dependencies
        wsptr[8 * 0] = local_dcval;
        wsptr[8 * 1] = local_dcval;
        wsptr[8 * 2] = local_dcval;
        wsptr[8 * 3] = local_dcval;
        wsptr[8 * 4] = local_dcval;
        wsptr[8 * 5] = local_dcval;
        wsptr[8 * 6] = local_dcval;
        wsptr[8 * 7] = local_dcval;
        skip_computation = 1;
    }

    if (!skip_computation) {
        // Remove potential RAW hazards by ensuring all loads happen early
        INT32 in_0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        INT32 in_4 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
        INT32 in_2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
        INT32 in_6 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
        INT32 in_7 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
        INT32 in_5 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5]));
        INT32 in_3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        INT32 in_1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));

        // Reorder operations to break artificial dependencies and enable parallelism
        z2 = in_0 << 13;
        z3 = in_4 << 13;
        z2 += ((INT32)1) << (13 - 2 - 1);
        tmp0 = z2 + z3;
        tmp1 = z2 - z3;

        z1 = ((in_2 + in_6) * (((INT32)4433)));
        tmp2 = z1 + ((in_2) * (((INT32)6270)));
        tmp3 = z1 - ((in_6) * (((INT32)15137)));

        tmp10 = tmp0 + tmp2;
        tmp13 = tmp0 - tmp2;
        tmp11 = tmp1 + tmp3;
        tmp12 = tmp1 - tmp3;

        z2 = in_7 + in_3;
        z3 = in_5 + in_1;
        z1 = ((z2 + z3) * (((INT32)9633)));
        z2 = (z2 * (-((INT32)16069))) + z1;
        z3 = (z3 * (-((INT32)3196))) + z1;

        z1 = ((in_7 + in_1) * (-((INT32)7373)));
        tmp0 = ((in_7) * (((INT32)2446))) + z1 + z2;
        tmp3 = ((in_1) * (((INT32)12299))) + z1 + z3;

        z1 = ((in_5 + in_3) * (-((INT32)20995)));
        tmp1 = ((in_5) * (((INT32)16819))) + z1 + z3;
        tmp2 = ((in_3) * (((INT32)25172))) + z1 + z2;

        // All stores use computed temporaries with no inter-iteration dependencies
        wsptr[8 * 0] = (int)((tmp10 + tmp3) >> (13 - 2));
        wsptr[8 * 7] = (int)((tmp10 - tmp3) >> (13 - 2));
        wsptr[8 * 1] = (int)((tmp11 + tmp2) >> (13 - 2));
        wsptr[8 * 6] = (int)((tmp11 - tmp2) >> (13 - 2));
        wsptr[8 * 2] = (int)((tmp12 + tmp1) >> (13 - 2));
        wsptr[8 * 5] = (int)((tmp12 - tmp1) >> (13 - 2));
        wsptr[8 * 3] = (int)((tmp13 + tmp0) >> (13 - 2));
        wsptr[8 * 4] = (int)((tmp13 - tmp0) >> (13 - 2));
    }

    // Independent pointer updates (no data dependency on computation result)
    inptr++;
    quantptr++;
    wsptr++;
}

}
