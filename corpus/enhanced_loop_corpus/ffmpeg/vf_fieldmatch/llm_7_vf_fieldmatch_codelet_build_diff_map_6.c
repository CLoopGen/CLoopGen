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
    uint8_t local_dst[width];
    for (int i = 0; i < width; i++)
        local_dst[i] = 0;

    for (x = 1; x < width - 1; x++) {
        diff = dp[x];
        if (diff > 3) {
            count = 0;
            for (u = x - 1; u <= x + 1 && count < 2; u++) {
                count += (dp[u - tpitch] > 3);
                count += (dp[u] > 3);
                count += (dp[u + tpitch] > 3);
            }
            if (count > 1) {
                local_dst[x] = 1;
                if (diff > 19) {
                    int strong_count = 0, has_upper = 0, has_lower = 0;
                    for (u = x - 1; u <= x + 1 && strong_count < 6; u++) {
                        if (dp[u - tpitch] > 19) {
                            strong_count++;
                            has_upper = 1;
                        }
                        if (dp[u] > 19)
                            strong_count++;
                        if (dp[u + tpitch] > 19) {
                            strong_count++;
                            has_lower = 1;
                        }
                    }
                    if (strong_count > 3) {
                        if (has_upper && has_lower) {
                            local_dst[x] |= 1 << 1;
                        } else {
                            int extended_upper = 0, extended_lower = 0;
                            int start_u = (x - 4 > 0) ? x - 4 : 0;
                            int end_u = (x + 5 < width) ? x + 5 : width;
                            for (u = start_u; u < end_u; u++) {
                                if (y != 2 && dp[u - 2 * tpitch] > 19)
                                    extended_upper = 1;
                                if (dp[u - tpitch] > 19)
                                    has_upper = 1;
                                if (dp[u + tpitch] > 19)
                                    has_lower = 1;
                                if (y != height - 4 && dp[u + 2 * tpitch] > 19)
                                    extended_lower = 1;
                            }
                            if ((has_upper && (has_lower || extended_upper)) || (has_lower && (has_upper || extended_lower)))
                                local_dst[x] |= 1 << 1;
                            else if (strong_count > 5)
                                local_dst[x] |= 1 << 2;
                        }
                    }
                }
            }
        }
    }

    for (x = 0; x < width; x++) {
        dstp[x] = local_dst[x];
    }

    dp += tpitch;
    dstp += dst_linesize;
}
}
