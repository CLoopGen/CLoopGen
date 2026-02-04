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
    int skip_update = 0;
    
    if (lambda < 60) {
        L_result = (wt[20] * dp[20 - lambda]) + (wt[21] * dp[21 - lambda]);
        skip_update = 1;
    }

    if (!skip_update) {
        L_result = (wt[0] * dp[0 - lambda]);
        L_result += (wt[1] * dp[1 - lambda]);
        L_result += (wt[2] * dp[2 - lambda]);
        L_result += (wt[3] * dp[3 - lambda]);
        L_result += (wt[4] * dp[4 - lambda]);
        L_result += (wt[5] * dp[5 - lambda]);
        L_result += (wt[6] * dp[6 - lambda]);
        L_result += (wt[7] * dp[7 - lambda]);
        L_result += (wt[8] * dp[8 - lambda]);
        L_result += (wt[9] * dp[9 - lambda]);
        L_result += (wt[10] * dp[10 - lambda]);
        L_result += (wt[11] * dp[11 - lambda]);
        L_result += (wt[12] * dp[12 - lambda]);
        L_result += (wt[13] * dp[13 - lambda]);
        L_result += (wt[14] * dp[14 - lambda]);
        L_result += (wt[15] * dp[15 - lambda]);
        L_result += (wt[16] * dp[16 - lambda]);
        L_result += (wt[17] * dp[17 - lambda]);
        L_result += (wt[18] * dp[18 - lambda]);
        L_result += (wt[19] * dp[19 - lambda]);
        L_result += (wt[20] * dp[20 - lambda]);
        L_result += (wt[21] * dp[21 - lambda]);
        L_result += (wt[22] * dp[22 - lambda]);
        L_result += (wt[23] * dp[23 - lambda]);
        L_result += (wt[24] * dp[24 - lambda]);
        L_result += (wt[25] * dp[25 - lambda]);
        L_result += (wt[26] * dp[26 - lambda]);
        L_result += (wt[27] * dp[27 - lambda]);
        L_result += (wt[28] * dp[28 - lambda]);
        L_result += (wt[29] * dp[29 - lambda]);
        L_result += (wt[30] * dp[30 - lambda]);
        L_result += (wt[31] * dp[31 - lambda]);
        L_result += (wt[32] * dp[32 - lambda]);
        L_result += (wt[33] * dp[33 - lambda]);
        L_result += (wt[34] * dp[34 - lambda]);
        L_result += (wt[35] * dp[35 - lambda]);
        L_result += (wt[36] * dp[36 - lambda]);
        L_result += (wt[37] * dp[37 - lambda]);
        L_result += (wt[38] * dp[38 - lambda]);
        L_result += (wt[39] * dp[39 - lambda]);
    }

    if (L_result > L_max && !skip_update) {
        Nc = lambda;
        L_max = L_result;
    }
}
}
