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
for (k = 0; k <= 39; k++) {
    dpp[k] = (((((longword)(21299) * (longword)(dp[k - Nc]) + 16384)) >> (15)));
    e[k] = ((ltmp = (longword)(d[k]) - (longword)(dpp[k])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
}

}
