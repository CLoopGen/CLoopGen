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
    int index = (k * 3) % 40;
    dpp[index] = (((((longword)(21299) * (longword)(dp[index - Nc]) + 16384)) >> (15)));
    e[index] = ((ltmp = (longword)(d[index]) - (longword)(dpp[index])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
}
}
