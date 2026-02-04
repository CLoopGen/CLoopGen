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
for (k = 0; k <= 39; k++) {
    register longword L_temp;
    L_temp = ((dp[k - Nc]) >> (3));
    if (L_temp != 0) {
        L_power += L_temp * L_temp;
    }
}
}
