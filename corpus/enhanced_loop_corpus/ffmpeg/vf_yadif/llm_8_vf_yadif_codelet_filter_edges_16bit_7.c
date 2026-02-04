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
for (x = offset; x < w; x += 2) {
    int c0 = cur[mrefs];
    int d0 = (prev2[0] + next2[0]) >> 1;
    int e0 = cur[prefs];
    int temporal_diff0_0 = prev2[0] - next2[0];
    int temporal_diff0 = temporal_diff0_0 >= 0 ? temporal_diff0_0 : -temporal_diff0_0;
    int temporal_diff1_0 = (prev[mrefs] - c0);
    int temporal_diff1_1 = (prev[prefs] - e0);
    int temporal_diff1 = ((temporal_diff1_0 >= 0 ? temporal_diff1_0 : -temporal_diff1_0) + 
                          (temporal_diff1_1 >= 0 ? temporal_diff1_1 : -temporal_diff1_1)) >> 1;
    int temporal_diff2_0 = (next[mrefs] - c0);
    int temporal_diff2_1 = (next[prefs] - e0);
    int temporal_diff2 = ((temporal_diff2_0 >= 0 ? temporal_diff2_0 : -temporal_diff2_0) + 
                          (temporal_diff2_1 >= 0 ? temporal_diff2_1 : -temporal_diff2_1)) >> 1;
    int diff = (temporal_diff0 >> 1);
    if (temporal_diff1 > diff) diff = temporal_diff1;
    if (temporal_diff2 > diff) diff = temporal_diff2;
    int spatial_pred = (c0 + e0) >> 1;
    if (!(mode & 2)) {
        int b0 = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f0 = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int max = (d0 - e0);
        if ((d0 - c0) > max) max = (d0 - c0);
        int temp_max = (b0 - c0);
        if ((f0 - e0) > temp_max) temp_max = (f0 - e0);
        if (temp_max > max) max = temp_max;
        int min = (d0 - c0);
        if ((d0 - e0) < min) min = (d0 - e0);
        int temp_min = (b0 - c0);
        if ((f0 - e0) < temp_min) temp_min = (f0 - e0);
        if (temp_min < min) min = temp_min;
        diff = diff > min ? diff : min;
        if (-max > diff) diff = -max;
    }
    if (spatial_pred > d0 + diff)
        spatial_pred = d0 + diff;
    else if (spatial_pred < d0 - diff)
        spatial_pred = d0 - diff;
    dst[0] = spatial_pred;

    if (x + 1 >= w) break;

    int c1 = cur[mrefs + 1];
    int d1 = (prev2[1] + next2[1]) >> 1;
    int e1 = cur[prefs + 1];
    int temporal_diff0_1 = prev2[1] - next2[1];
    temporal_diff0_1 = temporal_diff0_1 >= 0 ? temporal_diff0_1 : -temporal_diff0_1;
    int td1_part1 = (prev[mrefs + 1] - c1);
    int td1_part2 = (prev[prefs + 1] - e1);
    int temporal_diff1_val = ((td1_part1 >= 0 ? td1_part1 : -td1_part1) + 
                              (td1_part2 >= 0 ? td1_part2 : -td1_part2)) >> 1;
    int td2_part1 = (next[mrefs + 1] - c1);
    int td2_part2 = (next[prefs + 1] - e1);
    int temporal_diff2_val = ((td2_part1 >= 0 ? td2_part1 : -td2_part1) + 
                              (td2_part2 >= 0 ? td2_part2 : -td2_part2)) >> 1;
    int diff1 = (temporal_diff0_1 >> 1);
    if (temporal_diff1_val > diff1) diff1 = temporal_diff1_val;
    if (temporal_diff2_val > diff1) diff1 = temporal_diff2_val;
    int spatial_pred1 = (c1 + e1) >> 1;
    if (!(mode & 2)) {
        int b1 = (prev2[2*mrefs+2] + next2[2*mrefs+2]) >> 1;
        int f1 = (prev2[2*prefs+2] + next2[2*prefs+2]) >> 1;
        int max1 = (d1 - e1) > (d1 - c1) ? (d1 - e1) : (d1 - c1);
        int inner_max = (b1 - c1) > (f1 - e1) ? (b1 - c1) : (f1 - e1);
        max1 = max1 > inner_max ? max1 : inner_max;
        int min1 = (d1 - e1) < (d1 - c1) ? (d1 - e1) : (d1 - c1);
        int inner_min = (b1 - c1) < (f1 - e1) ? (b1 - c1) : (f1 - e1);
        min1 = min1 < inner_min ? min1 : inner_min;
        diff1 = diff1 > min1 ? diff1 : min1;
        diff1 = -max1 > diff1 ? -max1 : diff1;
    }
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
