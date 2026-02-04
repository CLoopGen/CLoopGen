#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int prefs;
extern int mrefs;
extern int mode;
extern uint16_t *dst;
extern uint16_t *prev;
extern uint16_t *cur;
extern uint16_t *next;
extern int x;
extern uint16_t *prev2;
extern uint16_t *next2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < w; x += 2) {
    int c0 = cur[mrefs];
    int d0 = (prev2[0] + next2[0]) >> 1;
    int e0 = cur[prefs];
    int temporal_diff0_0 = ((prev2[0] - next2[0]) >= 0 ? (prev2[0] - next2[0]) : (-(prev2[0] - next2[0])));
    int temporal_diff1_0 = (((prev[mrefs] - c0) >= 0 ? (prev[mrefs] - c0) : (-(prev[mrefs] - c0))) + ((prev[prefs] - e0) >= 0 ? (prev[prefs] - e0) : (-(prev[prefs] - e0)))) >> 1;
    int temporal_diff2_0 = (((next[mrefs] - c0) >= 0 ? (next[mrefs] - c0) : (-(next[mrefs] - c0))) + ((next[prefs] - e0) >= 0 ? (next[prefs] - e0) : (-(next[prefs] - e0)))) >> 1;
    int diff0 = ((((temporal_diff0_0 >> 1) > (temporal_diff1_0) ? (temporal_diff0_0 >> 1) : (temporal_diff1_0))) > (temporal_diff2_0) ? (((temporal_diff0_0 >> 1) > (temporal_diff1_0) ? (temporal_diff0_0 >> 1) : (temporal_diff1_0))) : (temporal_diff2_0));
    int spatial_pred0 = (c0 + e0) >> 1;

    if (1) {
        int spatial_score0 = ((cur[mrefs - 1] - cur[prefs - 1]) >= 0 ? (cur[mrefs - 1] - cur[prefs - 1]) : (-(cur[mrefs - 1] - cur[prefs - 1]))) +
                            ((c0 - e0) >= 0 ? (c0 - e0) : (-(c0 - e0))) +
                            ((cur[mrefs + 1] - cur[prefs + 1]) >= 0 ? (cur[mrefs + 1] - cur[prefs + 1]) : (-(cur[mrefs + 1] - cur[prefs + 1]))) - 1;

        for (int offset = -2; offset <= 2; offset++) {
            if (offset == 0) continue;
            int score = ((cur[mrefs - 1 + offset] - cur[prefs - 1 - offset]) >= 0 ? (cur[mrefs - 1 + offset] - cur[prefs - 1 - offset]) : (-(cur[mrefs - 1 + offset] - cur[prefs - 1 - offset]))) +
                        ((cur[mrefs + offset] - cur[prefs - offset]) >= 0 ? (cur[mrefs + offset] - cur[prefs - offset]) : (-(cur[mrefs + offset] - cur[prefs - offset]))) +
                        ((cur[mrefs + 1 + offset] - cur[prefs + 1 - offset]) >= 0 ? (cur[mrefs + 1 + offset] - cur[prefs + 1 - offset]) : (-(cur[mrefs + 1 + offset] - cur[prefs + 1 - offset])));
            if (score < spatial_score0) {
                spatial_score0 = score;
                spatial_pred0 = (cur[mrefs + offset] + cur[prefs - offset]) >> 1;
            }
        }
    }

    if (!(mode & 2)) {
        int b0 = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f0 = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int max0 = ((d0 - e0) > (d0 - c0) ? (d0 - e0) : (d0 - c0));
        int temp_max_part = (b0 - c0) > (f0 - e0) ? (b0 - c0) : (f0 - e0);
        max0 = max0 > temp_max_part ? max0 : temp_max_part;

        int min_part1 = (d0 - e0) > (d0 - c0) ? (d0 - c0) : (d0 - e0);
        int min_part2 = (b0 - c0) > (f0 - e0) ? (f0 - e0) : (b0 - c0);
        int min0 = min_part1 > min_part2 ? min_part2 : min_part1;

        diff0 = (diff0 > min0 ? diff0 : min0);
        diff0 = diff0 > -max0 ? diff0 : -max0;
    }

    spatial_pred0 = spatial_pred0 > (d0 + diff0) ? (d0 + diff0) : spatial_pred0;
    spatial_pred0 = spatial_pred0 < (d0 - diff0) ? (d0 - diff0) : spatial_pred0;
    dst[0] = spatial_pred0;
    dst++;

    if (x + 1 < w) {
        int c1 = cur[mrefs + 1];
        int d1 = (prev2[1] + next2[1]) >> 1;
        int e1 = cur[prefs + 1];
        int temporal_diff0_1 = ((prev2[1] - next2[1]) >= 0 ? (prev2[1] - next2[1]) : (-(prev2[1] - next2[1])));
        int temporal_diff1_1 = (((prev[mrefs + 1] - c1) >= 0 ? (prev[mrefs + 1] - c1) : (-(prev[mrefs + 1] - c1))) + ((prev[prefs + 1] - e1) >= 0 ? (prev[prefs + 1] - e1) : (-(prev[prefs + 1] - e1)))) >> 1;
        int temporal_diff2_1 = (((next[mrefs + 1] - c1) >= 0 ? (next[mrefs + 1] - c1) : (-(next[mrefs + 1] - c1))) + ((next[prefs + 1] - e1) >= 0 ? (next[prefs + 1] - e1) : (-(next[prefs + 1] - e1)))) >> 1;
        int diff1 = ((((temporal_diff0_1 >> 1) > (temporal_diff1_1) ? (temporal_diff0_1 >> 1) : (temporal_diff1_1))) > (temporal_diff2_1) ? (((temporal_diff0_1 >> 1) > (temporal_diff1_1) ? (temporal_diff0_1 >> 1) : (temporal_diff1_1))) : (temporal_diff2_1));
        int spatial_pred1 = (c1 + e1) >> 1;

        if (1) {
            int spatial_score1 = ((cur[mrefs] - cur[prefs]) >= 0 ? (cur[mrefs] - cur[prefs]) : (-(cur[mrefs] - cur[prefs]))) +
                                ((c1 - e1) >= 0 ? (c1 - e1) : (-(c1 - e1))) +
                                ((cur[mrefs + 2] - cur[prefs + 2]) >= 0 ? (cur[mrefs + 2] - cur[prefs + 2]) : (-(cur[mrefs + 2] - cur[prefs + 2]))) - 1;

            for (int offset = -2; offset <= 2; offset++) {
                if (offset == 0) continue;
                int score = ((cur[mrefs - 1 + offset + 1] - cur[prefs - 1 - offset + 1]) >= 0 ? (cur[mrefs - 1 + offset + 1] - cur[prefs - 1 - offset + 1]) : (-(cur[mrefs - 1 + offset + 1] - cur[prefs - 1 - offset + 1]))) +
                            ((cur[mrefs + offset + 1] - cur[prefs - offset + 1]) >= 0 ? (cur[mrefs + offset + 1] - cur[prefs - offset + 1]) : (-(cur[mrefs + offset + 1] - cur[prefs - offset + 1]))) +
                            ((cur[mrefs + 1 + offset + 1] - cur[prefs + 1 - offset + 1]) >= 0 ? (cur[mrefs + 1 + offset + 1] - cur[prefs + 1 - offset + 1]) : (-(cur[mrefs + 1 + offset + 1] - cur[prefs + 1 - offset + 1])));
                if (score < spatial_score1) {
                    spatial_score1 = score;
                    spatial_pred1 = (cur[mrefs + offset + 1] + cur[prefs - offset + 1]) >> 1;
                }
            }
        }

        if (!(mode & 2)) {
            int b1 = (prev2[2 * mrefs + 2] + next2[2 * mrefs + 2]) >> 1;
            int f1 = (prev2[2 * prefs + 2] + next2[2 * prefs + 2]) >> 1;
            int max1 = ((d1 - e1) > (d1 - c1) ? (d1 - e1) : (d1 - c1));
            int temp_max_part1 = (b1 - c1) > (f1 - e1) ? (b1 - c1) : (f1 - e1);
            max1 = max1 > temp_max_part1 ? max1 : temp_max_part1;

            int min_part1_1 = (d1 - e1) > (d1 - c1) ? (d1 - c1) : (d1 - e1);
            int min_part2_1 = (b1 - c1) > (f1 - e1) ? (f1 - e1) : (b1 - c1);
            int min1 = min_part1_1 > min_part2_1 ? min_part2_1 : min_part1_1;

            diff1 = (diff1 > min1 ? diff1 : min1);
            diff1 = diff1 > -max1 ? diff1 : -max1;
        }

        spatial_pred1 = spatial_pred1 > (d1 + diff1) ? (d1 + diff1) : spatial_pred1;
        spatial_pred1 = spatial_pred1 < (d1 - diff1) ? (d1 - diff1) : spatial_pred1;
        dst[0] = spatial_pred1;
        dst++;
    }

    cur += 2;
    prev += 2;
    next += 2;
    prev2 += 2;
    next2 += 2;
}
}
