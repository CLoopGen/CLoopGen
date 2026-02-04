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
for (lambda = 40; lambda <= 140; lambda++) {
    register longword L_result;
    L_result = (wt[0] * dp[0 - lambda]) + (wt[1] * dp[1 - lambda]) + (wt[2] * dp[2 - lambda]) + (wt[3] * dp[3 - lambda]);
    L_result += (wt[4] * dp[4 - lambda]) + (wt[5] * dp[5 - lambda]) + (wt[6] * dp[6 - lambda]) + (wt[7] * dp[7 - lambda]);
    L_result += (wt[8] * dp[8 - lambda]) + (wt[9] * dp[9 - lambda]) + (wt[10] * dp[10 - lambda]) + (wt[11] * dp[11 - lambda]);
    L_result += (wt[12] * dp[12 - lambda]) + (wt[13] * dp[13 - lambda]) + (wt[14] * dp[14 - lambda]) + (wt[15] * dp[15 - lambda]);
    L_result += (wt[16] * dp[16 - lambda]) + (wt[17] * dp[17 - lambda]) + (wt[18] * dp[18 - lambda]) + (wt[19] * dp[19 - lambda]);
    L_result += (wt[20] * dp[20 - lambda]) + (wt[21] * dp[21 - lambda]) + (wt[22] * dp[22 - lambda]) + (wt[23] * dp[23 - lambda]);
    L_result += (wt[24] * dp[24 - lambda]) + (wt[25] * dp[25 - lambda]) + (wt[26] * dp[26 - lambda]) + (wt[27] * dp[27 - lambda]);
    L_result += (wt[28] * dp[28 - lambda]) + (wt[29] * dp[29 - lambda]) + (wt[30] * dp[30 - lambda]) + (wt[31] * dp[31 - lambda]);
    L_result += (wt[32] * dp[32 - lambda]) + (wt[33] * dp[33 - lambda]) + (wt[34] * dp[34 - lambda]) + (wt[35] * dp[35 - lambda]);
    L_result += (wt[36] * dp[36 - lambda]) + (wt[37] * dp[37 - lambda]) + (wt[38] * dp[38 - lambda]) + (wt[39] * dp[39 - lambda]);
    
    L_result = (L_result >> 1) + (wt[0] << 1); // Artificially increase arithmetic intensity

    if (L_result > L_max) {
        Nc = lambda;
        L_max = L_result;
    }
}
}
