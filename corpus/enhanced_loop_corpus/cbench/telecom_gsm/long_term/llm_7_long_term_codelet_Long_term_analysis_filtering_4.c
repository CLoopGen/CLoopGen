#include <stdio.h>

#include <inttypes.h>

typedef short word;

typedef long longword;

extern word Nc;
extern word *dp;
extern word *d;
extern word *dpp;
extern word *e;
extern int k;
extern longword ltmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word prev_dpp = 0;
    for (k = 0; k <= 39; k++) {
        longword computed_val = (((longword)(3277) * (longword)(dp[k - Nc]) + 16384)) >> 15;
        dpp[k] = (k == 0) ? computed_val : (word)((computed_val + prev_dpp) & 0xFFFF); // Introduce WAW and loop-carried dependency
        prev_dpp = dpp[k];
        e[k] = ((ltmp = (longword)(d[k]) - (longword)(dpp[k])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
    }
}
