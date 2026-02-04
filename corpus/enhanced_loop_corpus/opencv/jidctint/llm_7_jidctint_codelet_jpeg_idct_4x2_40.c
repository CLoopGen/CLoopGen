#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp10;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern INT32 *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 local_tmp0, local_tmp10;
    for (ctr = 0; ctr < 4; ctr++, inptr++, quantptr++, wsptr++) {
        // Eliminate potential RAW/WAR by using local temporaries and reordering independent computations
        local_tmp10 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
        local_tmp0  = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));

        // Break loop-carried dependency on global tmp0/tmp10 by using locals
        // No dependency between iterations now (more amenable to unrolling/parallelization)
        wsptr[4 * 0] = local_tmp10 + local_tmp0;
        wsptr[4 * 1] = local_tmp10 - local_tmp0;
    }
    // Final write to globals to preserve some side effect (if needed externally)
    tmp0 = local_tmp0;
    tmp10 = local_tmp10;
}
