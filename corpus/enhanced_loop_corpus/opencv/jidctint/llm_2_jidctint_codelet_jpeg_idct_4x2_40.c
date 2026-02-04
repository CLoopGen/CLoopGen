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
    // Variant 1: Consecutive Memory Access (unrolled and restructured for sequential access)
    // Instead of strided access (8*i), we assume data has been pre-reorganized into consecutive layout
    // Simulate that inptr, quantptr are now accessed with stride 1 but over packed data
    INT32 tmp_values[8];
    JCOEFPTR base_in = inptr - (ctr * 8); // Assume starting point adjusted for new access
    ISLOW_MULT_TYPE *base_quant = quantptr - (ctr * 8);
    INT32 *base_ws = wsptr - (ctr * 4);

    for (ctr = 0; ctr < 4; ctr++) {
        tmp_values[0] = ((ISLOW_MULT_TYPE)(base_in[ctr * 2 + 0])) * (base_quant[ctr * 2 + 0]);
        tmp_values[1] = ((ISLOW_MULT_TYPE)(base_in[ctr * 2 + 1])) * (base_quant[ctr * 2 + 1]);

        base_ws[ctr * 2 + 0] = tmp_values[0] + tmp_values[1];
        base_ws[ctr * 2 + 1] = tmp_values[0] - tmp_values[1];
    }
}
