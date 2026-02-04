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
for (x = offset; x < w - 3; x++) {
    int c = cur[mrefs];
    int d = (prev2[0] + next2[0]) >> 1;
    int e = cur[prefs];
    int temporal_diff0 = (prev2[0] - next2[0]);
    if (temporal_diff0 < 0) temporal_diff0 = -temporal_diff0;
    int temporal_diff1 = (prev[mrefs] - c);
    if (temporal_diff1 < 0) temporal_diff1 = -temporal_diff1;
    int temp_diff_prev = (prev[prefs] - e);
    if (temp_diff_prev < 0) temp_diff_prev = -temp_diff_prev;
    temporal_diff1 = (temporal_diff1 + temp_diff_prev) >> 1;
    int temporal_diff2 = (next[mrefs] - c);
    if (temporal_diff2 < 0) temporal_diff2 = -temporal_diff2;
    int temp_diff_next = (next[prefs] - e);
    if (temp_diff_next < 0) temp_diff_next = -temp_diff_next;
    temporal_diff2 = (temporal_diff2 + temp_diff_next) >> 1;
    int candidate1 = (temporal_diff0 >> 1) > temporal_diff1 ? (temporal_diff0 >> 1) : temporal_diff1;
    int diff = candidate1 > temporal_diff2 ? candidate1 : temporal_diff2;
    int spatial_pred = (c + e) >> 1;

    int spatial_score = (cur[mrefs - 1] - cur[prefs - 1]);
    if (spatial_score < 0) spatial_score = -spatial_score;
    int term2 = (c - e);
    if (term2 < 0) term2 = -term2;
    spatial_score += term2;
    int term3 = (cur[mrefs + 1] - cur[prefs + 1]);
    if (term3 < 0) term3 = -term3;
    spatial_score += term3 - 1;

    for (int offset_val = -2; offset_val <= 2; offset_val += 1) {
        if (offset_val == 0) continue;
        int score = (cur[mrefs - 1 + offset_val] - cur[prefs - 1 - offset_val]);
        if (score < 0) score = -score;
        int mid_term = (cur[mrefs + offset_val] - cur[prefs - offset_val]);
        if (mid_term < 0) mid_term = -mid_term;
        score += mid_term;
        int end_term = (cur[mrefs + 1 + offset_val] - cur[prefs + 1 - offset_val]);
        if (end_term < 0) end_term = -end_term;
        score += end_term;

        if (score < spatial_score) {
            spatial_score = score;
            spatial_pred = (cur[mrefs + offset_val] + cur[prefs - offset_val]) >> 1;
        }
    }

    if (!(mode & 2)) {
        int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int max = (d - e) > (d - c) ? (d - e) : (d - c);
        int alt_max = (b - c) > (f - e) ? (b - c) : (f - e);
        max = max > alt_max ? max : alt_max;
        int min = (d - e) < (d - c) ? (d - e) : (d - c);
        int alt_min = (b - c) < (f - e) ? (b - c) : (f - e);
        min = min < alt_min ? min : alt_min;
        int adjusted_diff = diff > min ? diff : min;
        diff = adjusted_diff > -max ? adjusted_diff : -max;
    }

    if (spatial_pred > d + diff)
        spatial_pred = d + diff;
    else if (spatial_pred < d - diff)
        spatial_pred = d - diff;

    dst[0] = spatial_pred;
    dst++;
    cur++;
    prev++;
    next++;
    prev2++;
    next2++;
}
}
