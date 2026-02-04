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
word indices[40];
for (k = 0; k < 40; k++) {
    indices[k] = 39 - k;
}
for (k = 0; k < 40; k++) {
    word i = indices[k];
    dpp[i] = (((((longword)(3277) * (longword)(dp[i - Nc]) + 16384)) >> (15)));
    e[i] = ((ltmp = (longword)(d[i]) - (longword)(dpp[i])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
}
}
