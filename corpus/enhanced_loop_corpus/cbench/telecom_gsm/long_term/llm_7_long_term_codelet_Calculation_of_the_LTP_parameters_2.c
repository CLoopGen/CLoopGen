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
    longword temp_L_max = L_max;
    word temp_Nc = Nc;

    for (lambda = 40; lambda <= 120; lambda++) {
        register longword L_result = 0;
        word base_index = -lambda;

        #pragma unroll
        for (word k = 0; k < 40; k++) {
            L_result += (wt[k] * dp[k + base_index]);
        }

        if (L_result > temp_L_max) {
            temp_Nc = lambda;
            temp_L_max = L_result;
        }
    }

    // Introduce WAW dependency: write back only at the end
    Nc = temp_Nc;
    L_max = temp_L_max;
}
