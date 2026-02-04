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
for (k = 0; k <= 39; k += 2) {
    register longword L_temp1, L_temp2;
    int idx1 = k - Nc;
    int idx2 = k + 1 - Nc;
    
    L_temp1 = ((dp[idx1]) >> 3);
    L_power += L_temp1 * L_temp1;
    
    if (k + 1 <= 39) {
        L_temp2 = ((dp[idx2]) >> 3);
        L_power += L_temp2 * L_temp2;
    }
}
}
