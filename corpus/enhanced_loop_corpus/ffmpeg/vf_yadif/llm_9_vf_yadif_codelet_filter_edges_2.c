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
for (x = offset; x < w - 1; x++) {
    int c = cur[mrefs];
    int d = (prev2[0] + next2[0]) >> 1;
    int e = cur[prefs];

    int tdiff_prev = abs(prev[mrefs] - c) + abs(prev[prefs] - e);
    int tdiff_next = abs(next[mrefs] - c) + abs(next[prefs] - e);
    int temporal_diff1 = tdiff_prev >> 1;
    int temporal_diff2 = tdiff_next >> 1;
    int temporal_diff0 = abs(prev2[0] - next2[0]);

    int base_diff = temporal_diff0 >> 1;
    int diff = base_diff > temporal_diff1 ? base_diff : temporal_diff1;
    diff = diff > temporal_diff2 ? diff : temporal_diff2;

    int spatial_pred = (c + e) >> 1;
    int spatial_score = abs(cur[mrefs - 1] - cur[prefs - 1]) + abs(c - e) + abs(cur[mrefs + 1] - cur[prefs + 1]) - 1;

    // Reduced search range: only check offsets -1 and +1
    for (int offset_dir = -1; offset_dir <= 1; offset_dir += 2) {
        int score = abs(cur[mrefs - 1 + offset_dir] - cur[prefs - 1 - offset_dir]) +
                    abs(cur[mrefs + offset_dir] - cur[prefs - offset_dir]) +
                    abs(cur[mrefs + 1 + offset_dir] - cur[prefs + 1 - offset_dir]);
        if (score < spatial_score) {
            spatial_score = score;
            spatial_pred = (cur[mrefs + offset_dir] + cur[prefs - offset_dir]) >> 1;
        }
    }

    if (!(mode & 2)) {
        int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int max_val = (d - e) > (d - c) ? (d - e) : (d - c);
        int alt_max = (b - c) > (f - e) ? (b - c) : (f - e);
        max_val = max_val > alt_max ? max_val : alt_max;

        int min_val = (d - e) < (d - c) ? (d - e) : (d - c);
        int alt_min = (b - c) < (f - e) ? (b - c) : (f - e);
        min_val = min_val < alt_min ? min_val : alt_min;

        diff = (diff > min_val) ? diff : min_val;
        diff = (diff < -max_val) ? -max_val : diff;
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
