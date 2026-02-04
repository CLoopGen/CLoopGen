#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp1;
extern JLONG tmp10;
extern JLONG tmp11;
extern JLONG tmp12;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity with lower trip count and simplified operations
for (ctr = 0; ctr < 3; ctr++, inptr += 2, quantptr += 2, wsptr += 2) {
    tmp12 = (((ISLOW_MULT_TYPE)(inptr[0])) * (quantptr[0]));
    tmp12 = ((JLONG)(tmp12 << 13)) + ((JLONG)1 << 11); // Simplified shift and add

    tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    tmp1 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    z1 = (tmp0 + tmp1) * 6472; // Approximation of 0.790569415 * (1<<13)
    z2 = (tmp0 - tmp1) * 2900; // Approximation of 0.35355339 * (1<<13)
    z3 = tmp12 + z2;
    tmp10 = z3 + z1;
    tmp11 = z3 - z1;

    // Skip full cross-term computation; reduce to minimal output
    wsptr[0] = (int)(tmp10 >> 12);
    wsptr[4] = (int)(tmp11 >> 12);
    wsptr[2] = (int)(tmp12 >> 12);
}
}
