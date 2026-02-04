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
    for (k = 39; k >= 0; k--) {
        longword computed_val = (longword)(d[k]) - (longword)(((longword)(32767) * (longword)(dp[k - Nc]) + 16384) >> 15);
        e[k] = (computed_val >= 32767 ? 32767 : computed_val <= (-32768) ? -32768 : computed_val);
        dpp[k] = (((longword)(32767) * (longword)(dp[k - Nc]) + 16384) >> 15);
    }
}
