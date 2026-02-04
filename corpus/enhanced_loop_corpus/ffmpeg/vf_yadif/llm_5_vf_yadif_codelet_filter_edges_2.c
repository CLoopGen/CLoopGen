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
    int tdiff0 = prev2[0] - next2[0];
    int temporal_diff0 = tdiff0 >= 0 ? tdiff0 : -tdiff0;
    int tdiff1a = prev[mrefs] - c, tdiff1b = prev[prefs] - e;
    tdiff1a = tdiff1a >= 0 ? tdiff1a : -tdiff1a;
    tdiff1b = tdiff1b >= 0 ? tdiff1b : -tdiff1b;
    int temporal_diff1 = (tdiff1a + tdiff1b) >> 1;
    int tdiff2a = next[mrefs] - c, tdiff2b = next[prefs] - e;
    tdiff2a = tdiff2a >= 0 ? tdiff2a : -tdiff2a;
    tdiff2b = tdiff2b >= 0 ? tdiff2b : -tdiff2b;
    int temporal_diff2 = (tdiff2a + tdiff2b) >> 1;
    int edge_diff = temporal_diff0 >> 1;
    int mid_max = edge_diff > temporal_diff1 ? edge_diff : temporal_diff1;
    int diff = mid_max > temporal_diff2 ? mid_max : temporal_diff2;
    int spatial_pred = (c + e) >> 1;

    int base_score_terms = (cur[mrefs - 1] - cur[prefs - 1]);
    base_score_terms = base_score_terms >= 0 ? base_score_terms : -base_score_terms;
    int center_diff = c - e;
    center_diff = center_diff >= 0 ? center_diff : -center_diff;
    base_score_terms += center_diff;
    int right_diff = (cur[mrefs + 1] - cur[prefs + 1]);
    right_diff = right_diff >= 0 ? right_diff : -right_diff;
    int spatial_score = base_score_terms + right_diff - 1;

    int try_offsets[4] = {-2, -1, 1, 2};
    for (int i = 0; i < 4; i++) {
        int ofs = try_offsets[i];
        int score = (cur[mrefs - 1 + ofs] - cur[prefs - 1 - ofs]);
        score = score >= 0 ? score : -score;
        int mid_part = (cur[mrefs + ofs] - cur[prefs - ofs]);
        mid_part = mid_part >= 0 ? mid_part : -mid_part;
        score += mid_part;
        int end_part = (cur[mrefs + 1 + ofs] - cur[prefs + 1 - ofs]);
        end_part = end_part >= 0 ? end_part : -end_part;
        score += end_part;

        if (score < spatial_score) {
            spatial_score = score;
            spatial_pred = (cur[mrefs + ofs] + cur[prefs - ofs]) >> 1;
        }
    }

    if ((mode & 2) == 0) {
        int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int delta_d_c = d - c, delta_d_e = d - e;
        int delta_b_c = b - c, delta_f_e = f - e;
        int max1 = delta_d_e > delta_d_c ? delta_d_e : delta_d_c;
        int max2 = delta_b_c > delta_f_e ? delta_b_c : delta_f_e;
        int max = max1 > max2 ? max1 : max2;
        int min1 = delta_d_e < delta_d_c ? delta_d_e : delta_d_c;
        int min2 = delta_b_c < delta_f_e ? delta_b_c : delta_f_e;
        int min = min1 < min2 ? min1 : min2;
        int candidate_diff = diff > min ? diff : min;
        diff = candidate_diff > -max ? candidate_diff : -max;
    }

    if (spatial_pred - (d - diff) > 0)
        spatial_pred = d - diff;
    else if ((d + diff) - spatial_pred > 0)
        spatial_pred = d + diff;

    dst[0] = spatial_pred;
    dst += 1;
    cur += 1;
    prev += 1;
    next += 1;
    prev2 += 1;
    next2 += 1;
}
}
