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
for (k = 0; k <= 79; k += 2) {
    longword temp1 = (longword)(3277) * (longword)(dp[k - Nc]);
    longword temp2 = (longword)(3277) * (longword)(dp[k - Nc + 1]);
    dpp[k] = (temp1 + 16384) >> 15;
    dpp[k + 1] = (temp2 + 16384) >> 15;
    ltmp = (longword)(d[k]) - dpp[k];
    e[k] = (ltmp >= 32767) ? 32767 : (ltmp <= -32768) ? -32768 : ltmp;
    ltmp = (longword)(d[k + 1]) - dpp[k + 1];
    e[k + 1] = (ltmp >= 32767) ? 32767 : (ltmp <= -32768) ? -32768 : ltmp;
}
}
