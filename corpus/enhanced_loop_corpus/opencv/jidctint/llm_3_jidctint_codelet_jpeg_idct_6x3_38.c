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
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 6; ctr++, inptr++, quantptr++, wsptr += 2) {
    int index_in = (ctr & 1) ? 4 : 2;
    int index_quant = (ctr & 1) ? 6 : 1;
    int offset_wsptr = (ctr % 2) * 3;

    tmp0 = (((ISLOW_MULT_TYPE)(inptr[index_in])) * (quantptr[index_quant]));
    tmp0 <<= 13;
    tmp0 += ((INT32)1) << (13 - 2 - 1);
    tmp2 = (((ISLOW_MULT_TYPE)(inptr[index_in + 4])) * (quantptr[index_quant + 2]));
    tmp12 = ((tmp2) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))));
    tmp10 = tmp0 + tmp12;
    tmp2 = tmp0 - tmp12 - tmp12;
    tmp12 = (((ISLOW_MULT_TYPE)(inptr[index_in + 1])) * (quantptr[index_quant + 1]));
    tmp0 = ((tmp12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))));
    wsptr[offset_wsptr + 0] = (int)((tmp10 + tmp0) >> (13 - 2));
    wsptr[offset_wsptr + 2] = (int)((tmp10 - tmp0) >> (13 - 2));
    wsptr[offset_wsptr + 1] = (int)((tmp2) >> (13 - 2));
}
}
