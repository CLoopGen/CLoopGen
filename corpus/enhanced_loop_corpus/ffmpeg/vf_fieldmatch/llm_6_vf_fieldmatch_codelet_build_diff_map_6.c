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
            count = 0;
            for (u = x - 1; u <= x + 1 && count < 2; u++) {
                count += (dp[u - tpitch] > 3) + (dp[u] > 3) + (dp[u + tpitch] > 3);
            }
            if (count > 1) {
                dstp[x] = 1;
                if (diff > 19) {
                    int total = 0, upper = 0, lower = 0;
                    for (u = x - 1; u <= x + 1 && total < 6; u++) {
                        if (dp[u - tpitch] > 19) {
                            total++;
                            upper = 1;
                        }
                        if (dp[u] > 19)
                            total++;
                        if (dp[u + tpitch] > 19) {
                            total++;
                            lower = 1;
                        }
                    }
                    if (total > 3) {
                        if (upper && lower) {
                            dstp[x] |= 1 << 1;
                        } else {
                            int far_upper = 0, far_lower = 0;
                            for (u = (x - 4 > 0 ? x - 4 : 0); u < (x + 5 < width ? x + 5 : width); u++) {
                                if (y > 2 && dp[u - 2 * tpitch] > 19)
                                    far_upper = 1;
                                if (dp[u - tpitch] > 19)
                                    upper = 1;
                                if (dp[u + tpitch] > 19)
                                    lower = 1;
                                if (y < height - 4 && dp[u + 2 * tpitch] > 19)
                                    far_lower = 1;
                            }
                            if ((upper && (lower || far_upper)) || (lower && (upper || far_lower)))
                                dstp[x] |= 1 << 1;
                            else if (total > 5)
                                dstp[x] |= 1 << 2;
                        }
                    }
                }
            }
        }
    }
    dp += tpitch;
    dstp += dst_linesize;
}
}
