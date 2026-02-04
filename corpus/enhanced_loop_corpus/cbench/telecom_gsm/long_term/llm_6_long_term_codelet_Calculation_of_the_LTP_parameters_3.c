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
    register longword L_temp;
    for (k = Nc; k <= 39 + Nc; k++) {
        L_temp = ((dp[k - Nc]) >> (3));
        L_power += L_temp * L_temp;
    }
}
