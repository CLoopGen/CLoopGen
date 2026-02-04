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
for (x = 0; x < w; x++) {
    int c = cur[mrefs];
    int d = (prev2[0] + next2[0]) >> 1;
    int e = cur[prefs];

    int t_diff_prev = (prev[mrefs] - c);
    int t_diff_next = (next[mrefs] - c);
    int t_diff_prev_abs = t_diff_prev >= 0 ? t_diff_prev : -t_diff_prev;
    int t_diff_next_abs = t_diff_next >= 0 ? t_diff_next : -t_diff_next;

    int t_diff_prev_s = (prev[prefs] - e);
    int t_diff_next_s = (next[prefs] - e);
    int t_diff_prev_s_abs = t_diff_prev_s >= 0 ? t_diff_prev_s : -t_diff_prev_s;
    int t_diff_next_s_abs = t_diff_next_s >= 0 ? t_diff_next_s : -t_diff_next_s;

    int temporal_diff1 = (t_diff_prev_abs + t_diff_prev_s_abs) >> 1;
    int temporal_diff2 = (t_diff_next_abs + t_diff_next_s_abs) >> 1;
    int temporal_diff0 = (prev2[0] - next2[0]);
    temporal_diff0 = temporal_diff0 >= 0 ? temporal_diff0 : -temporal_diff0;

    int base_diff = temporal_diff0 >> 1;
    int mid_diff = base_diff > temporal_diff1 ? base_diff : temporal_diff1;
    int diff = mid_diff > temporal_diff2 ? mid_diff : temporal_diff2;

    int spatial_pred = (c + e) >> 1;

    if (1) {
        int left_diff = cur[mrefs - 1] - cur[prefs - 1];
        int center_diff = c - e;
        int right_diff = cur[mrefs + 1] - cur[prefs + 1];
        int spatial_score = (left_diff >= 0 ? left_diff : -left_diff) +
                            (center_diff >= 0 ? center_diff : -center_diff) +
                            (right_diff >= 0 ? right_diff : -right_diff) - 1;

        for (int off = -2; off <= 2; off++) {
            if (off == 0) continue;
            int n_left = cur[mrefs - 1 + off] - cur[prefs - 1 - off];
            int n_center = cur[mrefs + off] - cur[prefs - off];
            int n_right = cur[mrefs + 1 + off] - cur[prefs + 1 - off];
            int score = (n_left >= 0 ? n_left : -n_left) +
                        (n_center >= 0 ? n_center : -n_center) +
                        (n_right >= 0 ? n_right : -n_right);

            if (score < spatial_score) {
                spatial_score = score;
                spatial_pred = (cur[mrefs + off] + cur[prefs - off]) >> 1;
            }
        }
    }

    if (!(mode & 2)) {
        int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;

        int part1_high = (d - e) > (d - c) ? (d - e) : (d - c);
        int part2_high = (b - c) > (f - e) ? (b - c) : (f - e);
        int max = part1_high > part2_high ? part1_high : part2_high;

        int part1_low = (d - e) > (d - c) ? (d - c) : (d - e);
        int part2_low = (b - c) > (f - e) ? (f - e) : (b - c);
        int min = part1_low > part2_low ? part2_low : part1_low;

        diff = (diff > min ? diff : min);
        diff = diff > -max ? diff : -max;
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
