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



void loop() {
    for (lambda = 40; lambda <= 120; lambda += 2) {
        register longword L_result1 = 0;
        register longword L_result2 = 0;
        word offset1 = -lambda;
        word offset2 = -(lambda + 1);

        L_result1 += (wt[0] * dp[0 + offset1]);
        L_result2 += (wt[0] * dp[0 + offset2]);
        L_result1 += (wt[1] * dp[1 + offset1]);
        L_result2 += (wt[1] * dp[1 + offset2]);
        L_result1 += (wt[2] * dp[2 + offset1]);
        L_result2 += (wt[2] * dp[2 + offset2]);
        L_result1 += (wt[3] * dp[3 + offset1]);
        L_result2 += (wt[3] * dp[3 + offset2]);
        L_result1 += (wt[4] * dp[4 + offset1]);
        L_result2 += (wt[4] * dp[4 + offset2]);
        L_result1 += (wt[5] * dp[5 + offset1]);
        L_result2 += (wt[5] * dp[5 + offset2]);
        L_result1 += (wt[6] * dp[6 + offset1]);
        L_result2 += (wt[6] * dp[6 + offset2]);
        L_result1 += (wt[7] * dp[7 + offset1]);
        L_result2 += (wt[7] * dp[7 + offset2]);
        L_result1 += (wt[8] * dp[8 + offset1]);
        L_result2 += (wt[8] * dp[8 + offset2]);
        L_result1 += (wt[9] * dp[9 + offset1]);
        L_result2 += (wt[9] * dp[9 + offset2]);
        L_result1 += (wt[10] * dp[10 + offset1]);
        L_result2 += (wt[10] * dp[10 + offset2]);
        L_result1 += (wt[11] * dp[11 + offset1]);
        L_result2 += (wt[11] * dp[11 + offset2]);
        L_result1 += (wt[12] * dp[12 + offset1]);
        L_result2 += (wt[12] * dp[12 + offset2]);
        L_result1 += (wt[13] * dp[13 + offset1]);
        L_result2 += (wt[13] * dp[13 + offset2]);
        L_result1 += (wt[14] * dp[14 + offset1]);
        L_result2 += (wt[14] * dp[14 + offset2]);
        L_result1 += (wt[15] * dp[15 + offset1]);
        L_result2 += (wt[15] * dp[15 + offset2]);
        L_result1 += (wt[16] * dp[16 + offset1]);
        L_result2 += (wt[16] * dp[16 + offset2]);
        L_result1 += (wt[17] * dp[17 + offset1]);
        L_result2 += (wt[17] * dp[17 + offset2]);
        L_result1 += (wt[18] * dp[18 + offset1]);
        L_result2 += (wt[18] * dp[18 + offset2]);
        L_result1 += (wt[19] * dp[19 + offset1]);
        L_result2 += (wt[19] * dp[19 + offset2]);
        L_result1 += (wt[20] * dp[20 + offset1]);
        L_result2 += (wt[20] * dp[20 + offset2]);
        L_result1 += (wt[21] * dp[21 + offset1]);
        L_result2 += (wt[21] * dp[21 + offset2]);
        L_result1 += (wt[22] * dp[22 + offset1]);
        L_result2 += (wt[22] * dp[22 + offset2]);
        L_result1 += (wt[23] * dp[23 + offset1]);
        L_result2 += (wt[23] * dp[23 + offset2]);
        L_result1 += (wt[24] * dp[24 + offset1]);
        L_result2 += (wt[24] * dp[24 + offset2]);
        L_result1 += (wt[25] * dp[25 + offset1]);
        L_result2 += (wt[25] * dp[25 + offset2]);
        L_result1 += (wt[26] * dp[26 + offset1]);
        L_result2 += (wt[26] * dp[26 + offset2]);
        L_result1 += (wt[27] * dp[27 + offset1]);
        L_result2 += (wt[27] * dp[27 + offset2]);
        L_result1 += (wt[28] * dp[28 + offset1]);
        L_result2 += (wt[28] * dp[28 + offset2]);
        L_result1 += (wt[29] * dp[29 + offset1]);
        L_result2 += (wt[29] * dp[29 + offset2]);
        L_result1 += (wt[30] * dp[30 + offset1]);
        L_result2 += (wt[30] * dp[30 + offset2]);
        L_result1 += (wt[31] * dp[31 + offset1]);
        L_result2 += (wt[31] * dp[31 + offset2]);
        L_result1 += (wt[32] * dp[32 + offset1]);
        L_result2 += (wt[32] * dp[32 + offset2]);
        L_result1 += (wt[33] * dp[33 + offset1]);
        L_result2 += (wt[33] * dp[33 + offset2]);
        L_result1 += (wt[34] * dp[34 + offset1]);
        L_result2 += (wt[34] * dp[34 + offset2]);
        L_result1 += (wt[35] * dp[35 + offset1]);
        L_result2 += (wt[35] * dp[35 + offset2]);
        L_result1 += (wt[36] * dp[36 + offset1]);
        L_result2 += (wt[36] * dp[36 + offset2]);
        L_result1 += (wt[37] * dp[37 + offset1]);
        L_result2 += (wt[37] * dp[37 + offset2]);
        L_result1 += (wt[38] * dp[38 + offset1]);
        L_result2 += (wt[38] * dp[38 + offset2]);
        L_result1 += (wt[39] * dp[39 + offset1]);
        L_result2 += (wt[39] * dp[39 + offset2]);

        if (L_result1 > L_max) {
            Nc = lambda;
            L_max = L_result1;
        }
        if (lambda + 1 <= 120 && L_result2 > L_max) {
            Nc = lambda + 1;
            L_max = L_result2;
        }
    }
}
