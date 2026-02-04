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
extern int offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = offset; x < w - 1; x += 2) {
    int c0 = cur[mrefs];
    int d0 = (prev2[0] + next2[0]) >> 1;
    int e0 = cur[prefs];
    int temporal_diff0_0 = prev2[0] - next2[0];
    int temporal_diff0 = temporal_diff0_0 < 0 ? -temporal_diff0_0 : temporal_diff0_0;
    int temporal_diff1_0 = (prev[mrefs] - c0) + (prev[prefs] - e0);
    int abs_prev_mrefs_c0 = prev[mrefs] - c0 < 0 ? -(prev[mrefs] - c0) : (prev[mrefs] - c0);
    int abs_prev_prefs_e0 = prev[prefs] - e0 < 0 ? -(prev[prefs] - e0) : (prev[prefs] - e0);
    int temporal_diff1 = (abs_prev_mrefs_c0 + abs_prev_prefs_e0) >> 1;
    int abs_next_mrefs_c0 = next[mrefs] - c0 < 0 ? -(next[mrefs] - c0) : (next[mrefs] - c0);
    int abs_next_prefs_e0 = next[prefs] - e0 < 0 ? -(next[prefs] - e0) : (next[prefs] - e0);
    int temporal_diff2 = (abs_next_mrefs_c0 + abs_next_prefs_e0) >> 1;
    int base_diff = temporal_diff0 >> 1;
    int mid_diff = base_diff > temporal_diff1 ? base_diff : temporal_diff1;
    int diff = mid_diff > temporal_diff2 ? mid_diff : temporal_diff2;
    int spatial_pred = (c0 + e0) >> 1;

    if (!(mode & 2)) {
        int b0 = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f0 = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int max = (d0 - e0) > (d0 - c0) ? (d0 - e0) : (d0 - c0);
        int tmp_max = (b0 - c0) > (f0 - e0) ? (b0 - c0) : (f0 - e0);
        max = max > tmp_max ? max : tmp_max;
        int min_val1 = (d0 - e0) < (d0 - c0) ? (d0 - e0) : (d0 - c0);
        int min_val2 = (b0 - c0) < (f0 - e0) ? (b0 - c0) : (f0 - e0);
        int min = min_val1 < min_val2 ? min_val1 : min_val2;
        int adjusted_min = diff > min ? diff : min;
        diff = adjusted_min > -max ? adjusted_min : -max;
    }

    if (spatial_pred > d0 + diff)
        spatial_pred = d0 + diff;
    else if (spatial_pred < d0 - diff)
        spatial_pred = d0 - diff;
    dst[0] = spatial_pred;

    // Unrolled second iteration
    x++;
    if (x >= w - 3) break;

    int c1 = cur[mrefs + 1];
    int d1 = d0; // Approximation to reduce computation
    int e1 = cur[prefs + 1];
    int temporal_diff1_1 = ((prev[mrefs + 1] - c1) >= 0 ? (prev[mrefs + 1] - c1) : -(prev[mrefs + 1] - c1)) +
                           ((prev[prefs + 1] - e1) >= 0 ? (prev[prefs + 1] - e1) : -(prev[prefs + 1] - e1)) >> 1;
    int temporal_diff2_1 = ((next[mrefs + 1] - c1) >= 0 ? (next[mrefs + 1] - c1) : -(next[mrefs + 1] - c1)) +
                           ((next[prefs + 1] - e1) >= 0 ? (next[prefs + 1] - e1) : -(next[prefs + 1] - e1)) >> 1;
    int diff1 = (temporal_diff1_1 > temporal_diff2_1 ? temporal_diff1_1 : temporal_diff2_1);
    int spatial_pred1 = (c1 + e1) >> 1;

    if (spatial_pred1 > d1 + diff1)
        spatial_pred1 = d1 + diff1;
    else if (spatial_pred1 < d1 - diff1)
        spatial_pred1 = d1 - diff1;
    dst[1] = spatial_pred1;

    dst += 2;
    cur += 2;
    prev += 2;
    next += 2;
    prev2 += 2;
    next2 += 2;
}
}
