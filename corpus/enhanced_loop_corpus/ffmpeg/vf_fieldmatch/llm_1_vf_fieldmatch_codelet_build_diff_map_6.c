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
    x = 1;
    while (x < width - 1) {
        diff = dp[x];
        if (diff > 3) {
            for (count = 0, u = x - 1; u < x + 2 && count < 2; u++) {
                count += dp[u - tpitch] > 3;
                count += dp[u] > 3;
                count += dp[u + tpitch] > 3;
            }
            if (count > 1) {
                dstp[x] = 1;
                if (diff > 19) {
                    int upper = 0, lower = 0;
                    for (count = 0, u = x - 1; u < x + 2 && count < 6; u++) {
                        if (dp[u - tpitch] > 19) {
                            count++;
                            upper = 1;
                        }
                        if (dp[u] > 19)
                            count++;
                        if (dp[u + tpitch] > 19) {
                            count++;
                            lower = 1;
                        }
                    }
                    if (count > 3) {
                        if (upper && lower) {
                            dstp[x] |= 1 << 1;
                        } else {
                            int upper2 = 0, lower2 = 0;
                            for (u = ((x - 4) > (0) ? (x - 4) : (0)); u < ((x + 5) > (width) ? (width) : (x + 5)); u++) {
                                if (y != 2 && dp[u - 2 * tpitch] > 19)
                                    upper2 = 1;
                                if (dp[u - tpitch] > 19)
                                    upper = 1;
                                if (dp[u + tpitch] > 19)
                                    lower = 1;
                                if (y != height - 4 && dp[u + 2 * tpitch] > 19)
                                    lower2 = 1;
                            }
                            if ((upper && (lower || upper2)) || (lower && (upper || lower2)))
                                dstp[x] |= 1 << 1;
                            else if (count > 5)
                                dstp[x] |= 1 << 2;
                        }
                    }
                }
            }
        }
        x++;
    }
    dp += tpitch;
    dstp += dst_linesize;
}
}
