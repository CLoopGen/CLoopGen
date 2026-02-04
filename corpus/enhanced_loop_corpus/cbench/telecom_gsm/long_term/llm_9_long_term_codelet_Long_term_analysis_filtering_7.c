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
    longword temp1, temp2;
    temp1 = (longword)(32767) * (longword)(dp[k - Nc]) + 16384;
    dpp[k] = (short)(temp1 >> 15);
    dpp[k+1] = (short)(((longword)(32767) * (longword)(dp[k+1 - Nc]) + 16384) >> 15);
    temp2 = (longword)(d[k]) - (longword)(dpp[k]);
    e[k] = (temp2 >= 32767) ? 32767 : (temp2 <= -32768) ? -32768 : (short)temp2;
    temp2 = (longword)(d[k+1]) - (longword)(dpp[k+1]);
    e[k+1] = (temp2 >= 32767) ? 32767 : (temp2 <= -32768) ? -32768 : (short)temp2;
}
}
