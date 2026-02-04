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
for (ctr = 0; ctr < 5; ctr++ , inptr++ , quantptr++ , wsptr++) {
    // Eliminate some loop-carried dependencies by localizing variables
    JLONG local_tmp12, local_tmp0, local_tmp1, local_z1, local_z2, local_z3;
    JLONG local_tmp10, local_tmp11;

    local_tmp12 = (((ISLOW_MULT_TYPE)(inptr[8 * 0])) * (quantptr[8 * 0]));
    local_tmp12 = ((JLONG)((unsigned long)(local_tmp12) << (13)));
    local_tmp12 += ((JLONG)1) << (13 - 1 - 1);

    local_tmp0 = (((ISLOW_MULT_TYPE)(inptr[8 * 2])) * (quantptr[8 * 2]));
    local_tmp1 = (((ISLOW_MULT_TYPE)(inptr[8 * 4])) * (quantptr[8 * 4]));
    local_z1 = ((local_tmp0 + local_tmp1) * (((JLONG)((0.790569415) * (((JLONG)1) << 13) + 0.5))));
    local_z2 = ((local_tmp0 - local_tmp1) * (((JLONG)((0.35355339099999999) * (((JLONG)1) << 13) + 0.5))));
    local_z3 = local_tmp12 + local_z2;
    local_tmp10 = local_z3 + local_z1;
    local_tmp11 = local_z3 - local_z1;
    local_tmp12 -= ((JLONG)((unsigned long)(local_z2) << (2)));

    // Reorder independent computations to remove potential false dependencies
    JLONG next_z2 = (((ISLOW_MULT_TYPE)(inptr[8 * 1])) * (quantptr[8 * 1]));
    JLONG next_z3 = (((ISLOW_MULT_TYPE)(inptr[8 * 3])) * (quantptr[8 * 3]));
    JLONG next_z1 = ((next_z2 + next_z3) * (((JLONG)((0.831253876) * (((JLONG)1) << 13) + 0.5))));
    JLONG next_tmp0 = next_z1 + ((next_z2) * (((JLONG)((0.51374314799999998) * (((JLONG)1) << 13) + 0.5))));
    JLONG next_tmp1 = next_z1 - ((next_z3) * (((JLONG)((2.1762508989999998) * (((JLONG)1) << 13) + 0.5))));

    // Use computed values without external interference — all locals prevent RAW/WAR/WAW with globals
    wsptr[5 * 0] = (int)((local_tmp10 + next_tmp0) >> (13 - 1));
    wsptr[5 * 4] = (int)((local_tmp10 - next_tmp0) >> (13 - 1));
    wsptr[5 * 1] = (int)((local_tmp11 + next_tmp1) >> (13 - 1));
    wsptr[5 * 3] = (int)((local_tmp11 - next_tmp1) >> (13 - 1));
    wsptr[5 * 2] = (int)((local_tmp12) >> (13 - 1));
}
}
