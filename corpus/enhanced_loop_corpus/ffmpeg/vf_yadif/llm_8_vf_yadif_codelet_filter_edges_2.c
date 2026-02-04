#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int prefs;
extern int mrefs;
extern int mode;
extern uint8_t *dst;
extern uint8_t *prev;
extern uint8_t *cur;
extern uint8_t *next;
extern int x;
extern uint8_t *prev2;
extern uint8_t *next2;
extern int offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = offset; x < w - 7; x += 2) {
    int c0 = cur[mrefs];
    int d0 = (prev2[0] + next2[0]) >> 1;
    int e0 = cur[prefs];
    int temporal_diff0_0 = (prev2[0] - next2[0]) >= 0 ? (prev2[0] - next2[0]) : (-(prev2[0] - next2[0]));
    int temporal_diff1_0 = (((prev[mrefs] - c0) >= 0 ? (prev[mrefs] - c0) : (-(prev[mrefs] - c0))) +
                           ((prev[prefs] - e0) >= 0 ? (prev[prefs] - e0) : (-(prev[prefs] - e0)))) >> 1;
    int temporal_diff2_0 = (((next[mrefs] - c0) >= 0 ? (next[mrefs] - c0) : (-(next[mrefs] - c0))) +
                            ((next[prefs] - e0) >= 0 ? (next[prefs] - e0) : (-(next[prefs] - e0)))) >> 1;
    int diff0 = (temporal_diff0_0 >> 1);
    if (temporal_diff1_0 > diff0) diff0 = temporal_diff1_0;
    if (temporal_diff2_0 > diff0) diff0 = temporal_diff2_0;

    int spatial_pred0 = (c0 + e0) >> 1;
    int spatial_score0 = abs(cur[mrefs - 1] - cur[prefs - 1]) + abs(c0 - e0) + abs(cur[mrefs + 1] - cur[prefs + 1]) - 1;

    for (int off = -2; off <= 2; off++) {
        if (off == 0) continue;
        int score = abs(cur[mrefs - 1 + off] - cur[prefs - 1 - off]) +
                    abs(cur[mrefs + off] - cur[prefs - off]) +
                    abs(cur[mrefs + 1 + off] - cur[prefs + 1 - off]);
        if (score < spatial_score0) {
            spatial_score0 = score;
            spatial_pred0 = (cur[mrefs + off] + cur[prefs - off]) >> 1;
        }
    }

    if (!(mode & 2)) {
        int b0 = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f0 = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int max0 = (d0 - e0) > (d0 - c0) ? (d0 - e0) : (d0 - c0);
        if ((b0 - c0) > (f0 - e0)) max0 = (max0 > (b0 - c0)) ? max0 : (b0 - c0);
        else max0 = (max0 > (f0 - e0)) ? max0 : (f0 - e0);

        int min0 = (d0 - e0) < (d0 - c0) ? (d0 - e0) : (d0 - c0);
        int temp_min = (b0 - c0) < (f0 - e0) ? (b0 - c0) : (f0 - e0);
        min0 = (min0 < temp_min) ? min0 : temp_min;

        diff0 = (diff0 > min0) ? diff0 : min0;
        diff0 = (diff0 < -max0) ? -max0 : diff0;
    }

    if (spatial_pred0 > d0 + diff0)
        spatial_pred0 = d0 + diff0;
    else if (spatial_pred0 < d0 - diff0)
        spatial_pred0 = d0 - diff0;

    dst[0] = spatial_pred0;
    dst++;

    // Second iteration unrolled
    cur += 2;
    prev += 2;
    next += 2;
    prev2 += 2;
    next2 += 2;

    int c1 = cur[mrefs];
    int d1 = (prev2[0] + next2[0]) >> 1;
    int e1 = cur[prefs];
    int temporal_diff0_1 = (prev2[0] - next2[0]) >= 0 ? (prev2[0] - next2[0]) : (-(prev2[0] - next2[0]));
    int temporal_diff1_1 = (((prev[mrefs] - c1) >= 0 ? (prev[mrefs] - c1) : (-(prev[mrefs] - c1))) +
                           ((prev[prefs] - e1) >= 0 ? (prev[prefs] - e1) : (-(prev[prefs] - e1)))) >> 1;
    int temporal_diff2_1 = (((next[mrefs] - c1) >= 0 ? (next[mrefs] - c1) : (-(next[mrefs] - c1))) +
                            ((next[prefs] - e1) >= 0 ? (next[prefs] - e1) : (-(next[prefs] - e1)))) >> 1;
    int diff1 = (temporal_diff0_1 >> 1);
    if (temporal_diff1_1 > diff1) diff1 = temporal_diff1_1;
    if (temporal_diff2_1 > diff1) diff1 = temporal_diff2_1;

    int spatial_pred1 = (c1 + e1) >> 1;
    int spatial_score1 = abs(cur[mrefs - 1] - cur[prefs - 1]) + abs(c1 - e1) + abs(cur[mrefs + 1] - cur[prefs + 1]) - 1;

    for (int off = -2; off <= 2; off++) {
        if (off == 0) continue;
        int score = abs(cur[mrefs - 1 + off] - cur[prefs - 1 - off]) +
                    abs(cur[mrefs + off] - cur[prefs - off]) +
                    abs(cur[mrefs + 1 + off] - cur[prefs + 1 - off]);
        if (score < spatial_score1) {
            spatial_score1 = score;
            spatial_pred1 = (cur[mrefs + off] + cur[prefs - off]) >> 1;
        }
    }

    if (!(mode & 2)) {
        int b1 = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f1 = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int max1 = (d1 - e1) > (d1 - c1) ? (d1 - e1) : (d1 - c1);
        if ((b1 - c1) > (f1 - e1)) max1 = (max1 > (b1 - c1)) ? max1 : (b1 - c1);
        else max1 = (max1 > (f1 - e1)) ? max1 : (f1 - e1);

        int min1 = (d1 - e1) < (d1 - c1) ? (d1 - e1) : (d1 - c1);
        int temp_min1 = (b1 - c1) < (f1 - e1) ? (b1 - c1) : (f1 - e1);
        min1 = (min1 < temp_min1) ? min1 : temp_min1;

        diff1 = (diff1 > min1) ? diff1 : min1;
        diff1 = (diff1 < -max1) ? -max1 : diff1;
    }

    if (spatial_pred1 > d1 + diff1)
        spatial_pred1 = d1 + diff1;
    else if (spatial_pred1 < d1 - diff1)
        spatial_pred1 = d1 - diff1;

    dst[0] = spatial_pred1;
    dst++;
}
}
