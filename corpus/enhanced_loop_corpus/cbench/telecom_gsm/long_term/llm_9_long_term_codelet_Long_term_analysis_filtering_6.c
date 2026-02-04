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
for (k = 0; k <= 59; k += 3) {
    dpp[k] = (((((longword)(21299) * (longword)(dp[k - Nc]) + 16384)) >> (15)));
    if (k+1 <= 59) {
        dpp[k+1] = (((((longword)(21299) * (longword)(dp[k+1 - Nc]) + 16384)) >> (15)));
    }
    if (k+2 <= 59) {
        dpp[k+2] = (((((longword)(21299) * (longword)(dp[k+2 - Nc]) + 16384)) >> (15)));
    }
    e[k] = ((ltmp = (longword)(d[k]) - (longword)(dpp[k])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
    if (k+1 <= 59) {
        e[k+1] = ((ltmp = (longword)(d[k+1]) - (longword)(dpp[k+1])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
    }
    if (k+2 <= 59) {
        e[k+2] = ((ltmp = (longword)(d[k+2]) - (longword)(dpp[k+2])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
    }
}
}
