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
for (k = 0; k <= 39; k += 2) {
    for (int j = 0; j <= 1; j++) {
        int idx = k + j;
        if (idx <= 39) {
            dpp[idx] = (((((longword)(11469) * (longword)(dp[idx - Nc]) + 16384)) >> (15)));
            e[idx] = ((ltmp = (longword)(d[idx]) - (longword)(dpp[idx])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
        }
    }
}
}
