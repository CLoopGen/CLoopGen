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



void loop() {
    // Variant 2: Eliminate loop-carried dependencies entirely by unrolling and redefining independent computations
    // Each iteration uses only local, non-overlapping data — no RAW, WAR, or WAW across iterations
    // Assume Nc is known and large enough so that all dp[k-Nc] accesses are disjoint and safe

    #pragma unroll
    for (k = 0; k <= 39; k += 4) {
        // Process 4 iterations independently to expose parallelism
        if (k + 0 <= 39) {
            dpp[k+0] = (((((longword)(21299) * (longword)(dp[k+0 - Nc]) + 16384)) >> (15)));
            e[k+0] = ((ltmp = (longword)(d[k+0]) - (longword)(dpp[k+0])) >= (32767)
                         ? (32767)
                         : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
        }
        if (k + 1 <= 39) {
            dpp[k+1] = (((((longword)(21299) * (longword)(dp[k+1 - Nc]) + 16384)) >> (15)));
            e[k+1] = ((ltmp = (longword)(d[k+1]) - (longword)(dpp[k+1])) >= (32767)
                         ? (32767)
                         : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
        }
        if (k + 2 <= 39) {
            dpp[k+2] = (((((longword)(21299) * (longword)(dp[k+2 - Nc]) + 16384)) >> (15)));
            e[k+2] = ((ltmp = (longword)(d[k+2]) - (longword)(dpp[k+2])) >= (32767)
                         ? (32767)
                         : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
        }
        if (k + 3 <= 39) {
            dpp[k+3] = (((((longword)(21299) * (longword)(dp[k+3 - Nc]) + 16384)) >> (15)));
            e[k+3] = ((ltmp = (longword)(d[k+3]) - (longword)(dpp[k+3])) >= (32767)
                         ? (32767)
                         : ltmp <= ((-32767) - 1) ? ((-32767) - 1) : ltmp);
        }
    }
}
