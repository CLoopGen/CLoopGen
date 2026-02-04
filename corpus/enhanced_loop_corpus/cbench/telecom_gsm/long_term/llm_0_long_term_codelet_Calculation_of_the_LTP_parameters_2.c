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
        for (int i = 0; i < 40; i++) {
            L_result += (wt[i] * dp[i - lambda]);
        }
        if (L_result > L_max) {
            Nc = lambda;
            L_max = L_result;
        }
    }
}
