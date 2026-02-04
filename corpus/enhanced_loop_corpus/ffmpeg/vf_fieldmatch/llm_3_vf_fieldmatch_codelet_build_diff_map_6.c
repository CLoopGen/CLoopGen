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
    uint8_t *dp_base = dp;
    uint8_t *dst_base = dstp;
    ptrdiff_t offset;
    for (x = 1; x < width - 1; x++) {
        offset = x;
        diff = dp_base[offset];
        if (diff > 3) {
            count = 0;
            for (u = x - 1; u <= x + 1 && count < 2; u++) {
                ptrdiff_t off_u = u;
                count += (dp_base[off_u - tpitch] > 3);
                count += (dp_base[off_u] > 3);
                count += (dp_base[off_u + tpitch] > 3);
            }
            if (count > 1) {
                dst_base[offset] = 1;
                if (diff > 19) {
                    int upper = 0, lower = 0;
                    count = 0;
                    for (u = x - 1; u <= x + 1 && count < 6; u++) {
                        ptrdiff_t off_u = u;
                        if (dp_base[off_u - tpitch] > 19) {
                            count++;
                            upper = 1;
                        }
                        if (dp_base[off_u] > 19)
                            count++;
                        if (dp_base[off_u + tpitch] > 19) {
                            count++;
                            lower = 1;
                        }
                    }
                    if (count > 3) {
                        if (upper && lower) {
                            dst_base[offset] |= 1 << 1;
                        } else {
                            int upper2 = 0, lower2 = 0;
                            int start = (x - 4) > 0 ? x - 4 : 0;
                            int end = (x + 5) < width ? x + 5 : width;
                            for (u = start; u < end; u++) {
                                ptrdiff_t off_u = u;
                                if (y != 2 && dp_base[off_u - 2 * tpitch] > 19)
                                    upper2 = 1;
                                if (dp_base[off_u - tpitch] > 19)
                                    upper = 1;
                                if (dp_base[off_u + tpitch] > 19)
                                    lower = 1;
                                if (y != height - 4 && dp_base[off_u + 2 * tpitch] > 19)
                                    lower2 = 1;
                            }
                            if ((upper && (lower || upper2)) || (lower && (upper || lower2)))
                                dst_base[offset] |= 1 << 1;
                            else if (count > 5)
                                dst_base[offset] |= 1 << 2;
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
