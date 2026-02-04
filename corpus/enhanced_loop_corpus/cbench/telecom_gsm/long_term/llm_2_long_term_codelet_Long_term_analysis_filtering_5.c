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
    // Variant 1: Consecutive Memory Access with Reverse Order Traversal
    // Instead of accessing dp[k - Nc], we reverse the loop and adjust indexing to access dp consecutively.
    // This improves cache locality by accessing dp in decreasing but contiguous order.
    for (k = 39; k >= 0; k--) {
        int index_dp = k - Nc;
        dpp[k] = (((((longword)(11469) * (longword)(dp[index_dp]) + 16384)) >> (15)));
        e[k] = ((ltmp = (longword)(d[k]) - (longword)(dpp[k])) >= (32767) ? (32767) : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
    }
}
