#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word *dp;
extern int k;
extern word Nc;
extern longword L_power;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    register longword L_temp1, L_temp2;
    L_temp1 = 0;
    for (k = 0; k <= 39; k += 2) {
        L_temp2 = ((dp[k - Nc]) >> 3);
        L_temp1 += L_temp2 * L_temp2;
        if (k + 1 <= 39) {
            L_temp2 = ((dp[k + 1 - Nc]) >> 3);
            L_temp1 += L_temp2 * L_temp2;
        }
    }
    L_power += L_temp1;
}
