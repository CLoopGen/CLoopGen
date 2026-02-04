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
for (y = 2; y < height - 2; y += 2) {
    for (x = 1; x < width - 1; x++) {
        diff = dp[x];
        if (diff > 3) {
            int count1 = 0;
            for (u = x - 1; u <= x + 1; u++) {
                count1 += (dp[u - tpitch] > 3) + (dp[u] > 3) + (dp[u + tpitch] > 3);
            }
            if (count1 > 1) {
                dstp[x] = 1;
                if (diff > 19) {
                    int count2 = 0, upper = 0, lower = 0;
                    for (u = x - 1; u <= x + 1; u++) {
                        if (dp[u - tpitch] > 19) { count2++; upper = 1; }
                        if (dp[u] > 19) count2++;
                        if (dp[u + tpitch] > 19) { count2++; lower = 1; }
                    }
                    if (count2 > 3 && upper && lower) {
                        dstp[x] |= 1 << 1;
                    } else if (count2 > 5) {
                        dstp[x] |= 1 << 2;
                    }
                }
            }
        }
    }
    dp += tpitch;
    dstp += dst_linesize;
}
}
