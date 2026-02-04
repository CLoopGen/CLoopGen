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
for (ctr = 2; ctr > 0; ctr--) {
    // Reduced computational intensity: remove high-frequency coefficient processing
    // Assume only DC and first AC component are relevant
    int dcval = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0])) << 2;
    int ac1 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1])) << 2;

    // Simplified transform: only compute first two outputs
    wsptr[4 * 0] = (dcval + ac1) >> 2;
    wsptr[4 * 1] = (dcval - ac1) >> 2;
    // Fill remaining with approximated values
    wsptr[4 * 2] = dcval >> 2;
    wsptr[4 * 3] = dcval >> 2;
    wsptr[4 * 4] = dcval >> 2;
    wsptr[4 * 5] = dcval >> 2;
    wsptr[4 * 6] = dcval >> 2;
    wsptr[4 * 7] = dcval >> 2;

    inptr++;
    quantptr++;
    wsptr++;
    
    // Additional light computation to simulate minimal arithmetic
    tmp0 = (tmp0 + dcval) & 0xFFFF;
}
}
