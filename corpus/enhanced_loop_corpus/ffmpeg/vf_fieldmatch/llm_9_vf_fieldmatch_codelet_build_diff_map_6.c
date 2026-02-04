#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dstp;
extern int dst_linesize;
extern int height;
extern int width;
extern int x;
extern int y;
extern int u;
extern int diff;
extern int count;
extern int tpitch;
extern  uint8_t *dp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 4; y < height - 4; y += 4) {
    for (x = 2; x < width - 2; x += 2) {
        int total_diff = dp[x] + dp[x + 1];
        if (total_diff > 6) {
            int count = 0;
            for (u = x - 2; u < x + 4; u += 2) {
                count += (dp[u - 2*tpitch] > 3) + (dp[u - tpitch] > 3) +
                         (dp[u] > 3) + (dp[u + tpitch] > 3) +
                         (dp[u + 2*tpitch] > 3);
            }
            if (count > 4) {
                dstp[x] = 1;
                if (dp[x] > 19 || dp[x + 1] > 19) {
                    int strong_count = 0, upper = 0, lower = 0;
                    for (u = x - 2; u < x + 4; u += 2) {
                        if (dp[u - tpitch] > 19) { strong_count++; upper = 1; }
                        if (dp[u] > 19) strong_count++;
                        if (dp[u + tpitch] > 19) { strong_count++; lower = 1; }
                    }
                    if (strong_count > 4) {
                        if (upper && lower) {
                            dstp[x] |= 1 << 1;
                        } else if (strong_count > 7) {
                            dstp[x] |= 1 << 2;
                        }
                    }
                }
            }
        }
    }
    dp += 2 * tpitch;
    dstp += 2 * dst_linesize;
}
}
