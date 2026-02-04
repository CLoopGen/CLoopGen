#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern INT32 tmp0;
extern INT32 tmp10;
extern INT32 z1;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
INT32 speculative_dcval, accumulated_result;
for (ctr = 8; ctr > 0; inptr++ , quantptr++ , wsptr++ , ctr--) {
    if (ctr == 8 - 2 || ctr == 8 - 4 || ctr == 8 - 6)
        continue;

    INT32 non_zero_check = (inptr[8 * 1] | inptr[8 * 3] | inptr[8 * 5] | inptr[8 * 7]);
    INT32 dc_component = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));

    speculative_dcval = dc_component << 2;

    if (non_zero_check == 0) {
        wsptr[8 * 0] = speculative_dcval;
        wsptr[8 * 1] = speculative_dcval;
        continue;
    }

    accumulated_result = 0;
    accumulated_result += (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7])) * (-((INT32)5906));
    accumulated_result += (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5])) * (((INT32)6967));
    accumulated_result += (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3])) * (-((INT32)10426));
    accumulated_result += (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1])) * (((INT32)29692));

    INT32 tmp10_val = dc_component << (13 + 2);

    wsptr[8 * 0] = (int)(((tmp10_val + accumulated_result) + (((INT32)1) << (13))) >> 13);
    wsptr[8 * 1] = (int)(((tmp10_val - accumulated_result) + (((INT32)1) << (13))) >> 13);
}

}
