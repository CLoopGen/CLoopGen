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
    word temp_dpp;
    longword temp_e;
    for (k = 0; k <= 39; k++) {
        temp_dpp = (((((longword)(32767) * (longword)(dp[k - Nc]) + 16384)) >> (15)));
        dpp[k] = temp_dpp;
        temp_e = (longword)(d[k]) - (longword)(temp_dpp);
        e[k] = (temp_e >= 32767 ? 32767 : temp_e <= (-32768) ? -32768 : temp_e);
    }
}
