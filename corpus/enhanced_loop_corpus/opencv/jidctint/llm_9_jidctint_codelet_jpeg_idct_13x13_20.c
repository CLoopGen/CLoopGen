#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 tmp14;
extern INT32 tmp15;
extern INT32 tmp20;
extern INT32 tmp21;
extern INT32 tmp22;
extern INT32 tmp23;
extern INT32 tmp24;
extern INT32 tmp25;
extern INT32 tmp26;
extern INT32 z1;
extern INT32 z2;
extern INT32 z3;
extern INT32 z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 16; ctr++) {
    // Reduced operation variant: skip every other element, simplify computation
    int idx = (ctr % 8);
    inptr = (JCOEFPTR)(((char*)inptr) + (ctr == 0 ? 0 : 8 * sizeof(short)));
    quantptr = (ISLOW_MULT_TYPE*)(((char*)quantptr) + (ctr == 0 ? 0 : 8 * sizeof(int)));
    wsptr = (int*)(((char*)wsptr) + (ctr == 0 ? 0 : 8 * sizeof(int)));

    z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    z1 <<= 13;
    z1 += ((INT32)1) << (13 - 2 - 1);

    z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));

    tmp10 = z3;
    tmp11 = z3;
    tmp12 = ((tmp10) * (((INT32)((1.155388986) * (((INT32)1) << 13) + 0.5))));
    tmp13 = tmp12 + z1;

    tmp20 = ((z2) * (((INT32)((1.373119086) * (((INT32)1) << 13) + 0.5)))) + tmp12 + tmp13;
    tmp22 = ((z2) * (((INT32)((0.50148704099999997) * (((INT32)1) << 13) + 0.5)))) - tmp12 + tmp13;

    // Skip complex butterfly stages and use simplified outputs
    tmp21 = tmp20 >> 1;
    tmp23 = tmp22 >> 1;
    tmp24 = tmp20 >> 2;
    tmp25 = tmp22 >> 2;
    tmp26 = z1;

    // Write only even indices to reduce memory writes
    wsptr[8 * 0] = (int)((tmp20 + tmp21) >> (13 - 2));
    wsptr[8 * 2] = (int)((tmp22 + tmp23) >> (13 - 2));
    wsptr[8 * 4] = (int)((tmp24) >> (13 - 2));
    wsptr[8 * 6] = (int)((tmp26) >> (13 - 2));

    // Zero out odd positions less frequently
    if (ctr % 2 == 0) {
        wsptr[8 * 1] = (int)(tmp21 >> (13 - 2));
        wsptr[8 * 3] = (int)(tmp23 >> (13 - 2));
        wsptr[8 * 5] = (int)(tmp25 >> (13 - 2));
        wsptr[8 * 7] = (int)(tmp24 >> (13 - 2));
    }
}
}
