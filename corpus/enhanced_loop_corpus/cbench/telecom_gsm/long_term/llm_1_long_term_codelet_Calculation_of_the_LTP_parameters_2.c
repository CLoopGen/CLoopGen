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
    for (lambda = 40; lambda <= 120; lambda += 2) {
        register longword L_result1 = wt[0] * dp[0 - lambda];
        register longword L_result2 = wt[0] * dp[0 - (lambda + 1)];
        for (int i = 1; i < 40; i++) {
            L_result1 += wt[i] * dp[i - lambda];
            if (lambda + 1 <= 120) {
                L_result2 += wt[i] * dp[i - (lambda + 1)];
            }
        }
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
