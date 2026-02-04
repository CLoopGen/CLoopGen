#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *dp;
extern int lambda;
extern word Nc;
extern word wt[40];
extern longword L_max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (lambda = 40; lambda <= 120; lambda++) {
    register longword L_result = 0;
    // Memory Access Pattern Modification: Consecutive forward access by reindexing dp with base pointer offset
    word *dp_offset = &dp[-lambda];
    L_result += (wt[0] * dp_offset[0]);
    L_result += (wt[1] * dp_offset[1]);
    L_result += (wt[2] * dp_offset[2]);
    L_result += (wt[3] * dp_offset[3]);
    L_result += (wt[4] * dp_offset[4]);
    L_result += (wt[5] * dp_offset[5]);
    L_result += (wt[6] * dp_offset[6]);
    L_result += (wt[7] * dp_offset[7]);
    L_result += (wt[8] * dp_offset[8]);
    L_result += (wt[9] * dp_offset[9]);
    L_result += (wt[10] * dp_offset[10]);
    L_result += (wt[11] * dp_offset[11]);
    L_result += (wt[12] * dp_offset[12]);
    L_result += (wt[13] * dp_offset[13]);
    L_result += (wt[14] * dp_offset[14]);
    L_result += (wt[15] * dp_offset[15]);
    L_result += (wt[16] * dp_offset[16]);
    L_result += (wt[17] * dp_offset[17]);
    L_result += (wt[18] * dp_offset[18]);
    L_result += (wt[19] * dp_offset[19]);
    L_result += (wt[20] * dp_offset[20]);
    L_result += (wt[21] * dp_offset[21]);
    L_result += (wt[22] * dp_offset[22]);
    L_result += (wt[23] * dp_offset[23]);
    L_result += (wt[24] * dp_offset[24]);
    L_result += (wt[25] * dp_offset[25]);
    L_result += (wt[26] * dp_offset[26]);
    L_result += (wt[27] * dp_offset[27]);
    L_result += (wt[28] * dp_offset[28]);
    L_result += (wt[29] * dp_offset[29]);
    L_result += (wt[30] * dp_offset[30]);
    L_result += (wt[31] * dp_offset[31]);
    L_result += (wt[32] * dp_offset[32]);
    L_result += (wt[33] * dp_offset[33]);
    L_result += (wt[34] * dp_offset[34]);
    L_result += (wt[35] * dp_offset[35]);
    L_result += (wt[36] * dp_offset[36]);
    L_result += (wt[37] * dp_offset[37]);
    L_result += (wt[38] * dp_offset[38]);
    L_result += (wt[39] * dp_offset[39]);
    if (L_result > L_max) {
        Nc = lambda;
        L_max = L_result;
    }
}
}
