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
    // Variant 2: Strided Memory Access with Step Size 2
    // Split the original loop into two passes with stride-2 access to interleave memory accesses.
    // This can help reduce cache conflicts or align with hardware prefetching patterns.
    // First pass: even indices
    for (k = 0; k <= 39; k += 2) {
        dpp[k] = (((((longword)(11469) * (longword)(dp[k - Nc]) + 16384)) >> (15)));
        e[k] = ((ltmp = (longword)(d[k]) - (longword)(dpp[k])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
    }
    // Second pass: odd indices
    for (k = 1; k <= 39; k += 2) {
        dpp[k] = (((((longword)(11469) * (longword)(dp[k - Nc]) + 16384)) >> (15)));
        e[k] = ((ltmp = (longword)(d[k]) - (longword)(dpp[k])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
    }
}
