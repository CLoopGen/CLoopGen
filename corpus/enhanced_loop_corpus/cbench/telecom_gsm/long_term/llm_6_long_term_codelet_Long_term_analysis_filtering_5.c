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
    word temp_dpp[40];
    for (k = 0; k <= 39; k++) {
        temp_dpp[k] = (((((longword)(11469) * (longword)(dp[k - Nc]) + 16384)) >> (15)));
    }
    for (k = 0; k <= 39; k++) {
        e[k] = ((ltmp = (longword)(d[k]) - (longword)(temp_dpp[k])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
    }
}
