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
    int d_val = (prev2[0] + next2[0]) >> 1;
    int e = cur[prefs];
    int temporal_diff0 = (prev2[0] - next2[0]) >= 0 ? (prev2[0] - next2[0]) : (-(prev2[0] - next2[0]));
    int prev_mref_diff = (prev[mrefs] - c) >= 0 ? (prev[mrefs] - c) : (-(prev[mrefs] - c));
    int prev_pref_diff = (prev[prefs] - e) >= 0 ? (prev[prefs] - e) : (-(prev[prefs] - e));
    int temporal_diff1 = (prev_mref_diff + prev_pref_diff) >> 1;
    int next_mref_diff = (next[mrefs] - c) >= 0 ? (next[mrefs] - c) : (-(next[mrefs] - c));
    int next_pref_diff = (next[prefs] - e) >= 0 ? (next[prefs] - e) : (-(next[prefs] - e));
    int temporal_diff2 = (next_mref_diff + next_pref_diff) >> 1;
    int base_diff = temporal_diff0 >> 1;
    int mid_diff = base_diff > temporal_diff1 ? base_diff : temporal_diff1;
    int diff = mid_diff > temporal_diff2 ? mid_diff : temporal_diff2;
    int spatial_pred = (c + e) >> 1;

    if (1) {
        int left_diff = (cur[mrefs - 1] - cur[prefs - 1]) >= 0 ? (cur[mrefs - 1] - cur[prefs - 1]) : (-(cur[mrefs - 1] - cur[prefs - 1]));
        int center_diff = (c - e) >= 0 ? (c - e) : (-(c - e));
        int right_diff = (cur[mrefs + 1] - cur[prefs + 1]) >= 0 ? (cur[mrefs + 1] - cur[prefs + 1]) : (-(cur[mrefs + 1] - cur[prefs + 1]));
        int spatial_score = left_diff + center_diff + right_diff - 1;

        for (int offset_val = -2; offset_val <= 2; offset_val++) {
            if (offset_val == 0) continue;
            int new_left = (cur[mrefs - 1 + offset_val] - cur[prefs - 1 - offset_val]) >= 0 ? 
                (cur[mrefs - 1 + offset_val] - cur[prefs - 1 - offset_val]) : 
                (-(cur[mrefs - 1 + offset_val] - cur[prefs - 1 - offset_val]));
            int new_center = (cur[mrefs + offset_val] - cur[prefs - offset_val]) >= 0 ? 
                (cur[mrefs + offset_val] - cur[prefs - offset_val]) : 
                (-(cur[mrefs + offset_val] - cur[prefs - offset_val]));
            int new_right = (cur[mrefs + 1 + offset_val] - cur[prefs + 1 - offset_val]) >= 0 ? 
                (cur[mrefs + 1 + offset_val] - cur[prefs + 1 - offset_val]) : 
                (-(cur[mrefs + 1 + offset_val] - cur[prefs + 1 - offset_val]));
            int score = new_left + new_center + new_right;
            if (score < spatial_score) {
                spatial_score = score;
                spatial_pred = (cur[mrefs + offset_val] + cur[prefs - offset_val]) >> 1;
            }
        }
    }

    if (!(mode & 2)) {
        int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int d_minus_e = d_val - e;
        int d_minus_c = d_val - c;
        int f_minus_e = f - e;
        int b_minus_c = b - c;
        int max_branch1 = d_minus_e > d_minus_c ? d_minus_e : d_minus_c;
        int max_branch2 = b_minus_c > f_minus_e ? b_minus_c : f_minus_e;
        int max = max_branch1 > max_branch2 ? max_branch1 : max_branch2;
        int min_branch1 = d_minus_e > d_minus_c ? d_minus_c : d_minus_e;
        int min_branch2 = b_minus_c > f_minus_e ? f_minus_e : b_minus_c;
        int min = min_branch1 > min_branch2 ? min_branch2 : min_branch1;
        diff = diff > min ? diff : min;
        diff = diff > -max ? diff : -max;
    }

    if (spatial_pred > d_val + diff)
        spatial_pred = d_val + diff;
    else if (spatial_pred < d_val - diff)
        spatial_pred = d_val - diff;

    dst[0] = spatial_pred;
    dst++;
    cur++;
    prev++;
    next++;
    prev2++;
    next2++;
}
}
