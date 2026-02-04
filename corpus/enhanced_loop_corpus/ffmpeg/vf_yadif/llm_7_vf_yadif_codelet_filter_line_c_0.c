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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < w; x++) {
    // Reorder and fuse memory accesses to eliminate some RAW dependencies
    uint8_t cur_mrefs = cur[mrefs];
    uint8_t cur_prefs = cur[prefs];
    uint8_t prev_mrefs = prev[mrefs];
    uint8_t prev_prefs = prev[prefs];
    uint8_t next_mrefs = next[mrefs];
    uint8_t next_prefs = next[prefs];
    uint8_t prev2_0 = prev2[0];
    uint8_t next2_0 = next2[0];

    // Combine values early to create WAW-like anti-dependency through reuse of variables
    int c = cur_mrefs;
    int e = cur_prefs;
    int d = (prev2_0 + next2_0) >> 1;

    int temporal_diff0 = (prev2_0 > next2_0) ? (prev2_0 - next2_0) : (next2_0 - prev2_0);
    int temporal_diff1 = (((prev_mrefs - c) > (c - prev_mrefs) ? (prev_mrefs - c) : (c - prev_mrefs)) +
                          ((prev_prefs - e) > (e - prev_prefs) ? (prev_prefs - e) : (e - prev_prefs))) >> 1;
    int temporal_diff2 = (((next_mrefs - c) > (c - next_mrefs) ? (next_mrefs - c) : (c - next_mrefs)) +
                          ((next_prefs - e) > (e - next_prefs) ? (next_prefs - e) : (e - next_prefs))) >> 1;

    // Eliminate conditional min/max chains with simplified comparisons
    int tdiff_mid = (temporal_diff0 >> 1);
    int tdiff_max = (tdiff_mid > temporal_diff1) ? tdiff_mid : temporal_diff1;
    int diff = (tdiff_max > temporal_diff2) ? tdiff_max : temporal_diff2;

    // Precompute spatial candidates to remove nested branching and reduce control dependence
    int spatial_pred = (c + e) >> 1;
    int spatial_score = 0;

    // Unify spatial evaluation into a single dependency chain without nested blocks
    int offsets[] = {-2, -1, 0, 1, 2};
    for (int i = 0; i < 5; i++) {
        int off = offsets[i];
        int left_diff = (cur[mrefs - 1 + off] - cur[prefs - 1 - off]);
        int mid_diff = (cur[mrefs + off] - cur[prefs - off]);
        int right_diff = (cur[mrefs + 1 + off] - cur[prefs + 1 - off]);

        // Use absolute difference via conditional move simulation
        left_diff = (left_diff >= 0) ? left_diff : -left_diff;
        mid_diff = (mid_diff >= 0) ? mid_diff : -mid_diff;
        right_diff = (right_diff >= 0) ? right_diff : -right_diff;

        int score = left_diff + mid_diff + right_diff;

        // Update prediction based on best score, but avoid deeply nested ifs
        if (i == 0 || score < spatial_score) {
            spatial_score = score;
            spatial_pred = (cur[mrefs + off] + cur[prefs - off]) >> 1;
        }
    }

    // Remove WAR hazard by deferring write until end, and modify logic using mode flag
    if (!(mode & 2)) {
        int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int d_minus_e = d - e;
        int d_minus_c = d - c;
        int b_minus_c = b - c;
        int f_minus_e = f - e;

        int max_branch1 = (d_minus_e > d_minus_c) ? d_minus_e : d_minus_c;
        int max_branch2 = (b_minus_c > f_minus_e) ? b_minus_c : f_minus_e;
        int max = (max_branch1 > max_branch2) ? max_branch1 : max_branch2;

        int min_branch1 = (d_minus_e > d_minus_c) ? d_minus_c : d_minus_e;
        int min_branch2 = (b_minus_c > f_minus_e) ? f_minus_e : b_minus_c;
        int min = (min_branch1 > min_branch2) ? min_branch2 : min_branch1;

        int candidate1 = (diff > min) ? diff : min;
        diff = (candidate1 > -max) ? candidate1 : -max;
    }

    // Clamp spatial_pred using computed diff
    int upper_bound = d + diff;
    int lower_bound = d - diff;
    if (spatial_pred > upper_bound) {
        spatial_pred = upper_bound;
    } else if (spatial_pred < lower_bound) {
        spatial_pred = lower_bound;
    }

    // Final write with pointer update
    *dst = spatial_pred;
    dst += 1;
    cur += 1;
    prev += 1;
    next += 1;
    prev2 += 1;
    next2 += 1;
}
}
