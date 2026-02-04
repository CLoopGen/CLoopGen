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
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ctr = 0; ctr < 8; ctr++, inptr++, quantptr++, wsptr++) {
        // Eliminate some temporary reuse and reorganize expressions to remove write-after-write (WAW) and read-after-write (RAW) dependencies
        // All computations are now expressed inline without intermediate overwrites

        INT32 local_tmp10 = ((((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) + 
                             (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]))) << 2;

        INT32 local_tmp12 = ((((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) - 
                             (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]))) << 2;

        INT32 local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
        INT32 local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
        INT32 local_z1 = ((local_z2 + local_z3) * (((INT32)4433))) + (((INT32)1) << (13 - 2 - 1));

        // Compute final values directly without reusing tmp0/tmp2 names, avoiding WAW hazards
        wsptr[8 * 0] = (int)(local_tmp10 + ((local_z1 + (local_z2 * 6270)) >> (13 - 2)));
        wsptr[8 * 3] = (int)(local_tmp10 - ((local_z1 + (local_z2 * 6270)) >> (13 - 2)));
        wsptr[8 * 1] = (int)(local_tmp12 + ((local_z1 - (local_z3 * 15137)) >> (13 - 2)));
        wsptr[8 * 2] = (int)(local_tmp12 - ((local_z1 - (local_z3 * 15137)) >> (13 - 2)));
    }
}
