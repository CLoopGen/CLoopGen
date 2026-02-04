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
    uint8_t *dp_line = dp;
    uint8_t *dst_line = dstp;
    for (x = 1; x < width - 1; x++) {
        diff = dp_line[x];
        if (diff > 3) {
            count = 0;
            for (u = x - 1; u <= x + 1 && count < 2; u++) {
                count += (dp_line[u - tpitch] > 3) + (dp_line[u] > 3) + (dp_line[u + tpitch] > 3);
            }
            if (count > 1) {
                dst_line[x] = 1;
                if (diff > 19) {
                    int upper = 0, lower = 0;
                    count = 0;
                    for (u = x - 1; u <= x + 1 && count < 6; u++) {
                        if (dp_line[u - tpitch] > 19) {
                            count++;
                            upper = 1;
                        }
                        if (dp_line[u] > 19)
                            count++;
                        if (dp_line[u + tpitch] > 19) {
                            count++;
                            lower = 1;
                        }
                    }
                    if (count > 3) {
                        if (upper && lower) {
                            dst_line[x] |= 1 << 1;
                        } else {
                            int upper2 = 0, lower2 = 0;
                            int start = (x - 4) > 0 ? x - 4 : 0;
                            int end = (x + 5) < width ? x + 5 : width;
                            for (u = start; u < end; u++) {
                                if (y != 2 && dp_line[u - 2 * tpitch] > 19)
                                    upper2 = 1;
                                if (dp_line[u - tpitch] > 19)
                                    upper = 1;
                                if (dp_line[u + tpitch] > 19)
                                    lower = 1;
                                if (y != height - 4 && dp_line[u + 2 * tpitch] > 19)
                                    lower2 = 1;
                            }
                            if ((upper && (lower || upper2)) || (lower && (upper || lower2)))
                                dst_line[x] |= 1 << 1;
                            else if (count > 5)
                                dst_line[x] |= 1 << 2;
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
