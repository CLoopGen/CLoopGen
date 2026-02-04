#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef short JCOEF;

typedef JCOEF *JCOEFPTR;

typedef int ISLOW_MULT_TYPE;

extern JLONG tmp0;
extern JLONG tmp2;
extern JLONG tmp10;
extern JLONG tmp12;
extern JLONG z1;
extern JLONG z2;
extern JLONG z3;
extern JLONG z4;
extern JCOEFPTR inptr;
extern ISLOW_MULT_TYPE *quantptr;
extern int *wsptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
JLONG local_tmp0, local_tmp2, local_tmp10, local_tmp12, local_z1, local_z2, local_z3, local_z4;
for (ctr = 8; ctr > 0; inptr++ , quantptr++ , wsptr++ , ctr--) {
    if (ctr == 8 - 4)
        continue;
    if (inptr[8 * 1] == 0 && inptr[8 * 2] == 0 && inptr[8 * 3] == 0 && inptr[8 * 5] == 0 && inptr[8 * 6] == 0 && inptr[8 * 7] == 0) {
        int dcval = ((JLONG)((unsigned long)((((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]))) << (1)));
        wsptr[8 * 0] = dcval;
        wsptr[8 * 1] = dcval;
        wsptr[8 * 2] = dcval;
        wsptr[8 * 3] = dcval;
        continue;
    }
    local_tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    local_tmp0 = ((JLONG)((unsigned long)(local_tmp0) << (13 + 1)));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 6])) * (quantptr[8 * 6]));
    local_tmp2 = ((local_z2) * (((JLONG)15137))) + ((local_z3) * (-((JLONG)6270)));
    local_tmp10 = local_tmp0 + local_tmp2;
    local_tmp12 = local_tmp0 - local_tmp2;
    local_z1 = (((ISLOW_MULT_TYPE)(inptr[8 * 7])) * (quantptr[8 * 7]));
    local_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 5])) * (quantptr[8 * 5])); // Reuse local_z2 without affecting prior use
    local_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    local_z4 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    local_tmp0 = ((local_z1) * (-((JLONG)1730))) + ((local_z2) * (((JLONG)11893))) + ((local_z3) * (-((JLONG)17799))) + ((local_z4) * (((JLONG)8697)));
    local_tmp2 = ((local_z1) * (-((JLONG)4176))) + ((local_z2) * (-((JLONG)4926))) + ((local_z3) * (((JLONG)7373))) + ((local_z4) * (((JLONG)20995)));
    wsptr[8 * 0] = (int)(((local_tmp10 + local_tmp2) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
    wsptr[8 * 3] = (int)(((local_tmp10 - local_tmp2) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
    wsptr[8 * 1] = (int)(((local_tmp12 + local_tmp0) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
    wsptr[8 * 2] = (int)(((local_tmp12 - local_tmp0) + (((JLONG)1) << ((13 - 1 + 1) - 1))) >> (13 - 1 + 1));
}

}
