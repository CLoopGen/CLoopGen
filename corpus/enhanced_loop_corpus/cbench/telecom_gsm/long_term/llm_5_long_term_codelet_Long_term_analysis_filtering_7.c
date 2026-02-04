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
    if (k >= Nc) {
        dpp[k] = (((((longword)(32767) * (longword)(dp[k - Nc]) + 16384)) >> (15)));
        ltmp = (longword)(d[k]) - (longword)(dpp[k]);
        if (ltmp >= 32767) {
            e[k] = 32767;
        } else if (ltmp <= (-32767) - 1) {
            e[k] = (-32767) - 1;
        } else {
            e[k] = ltmp;
        }
    } else {
        dpp[k] = 0;
        e[k] = d[k];
    }
}
}
