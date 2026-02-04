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
for (x = offset; x < w; x++) {
    int c = cur[mrefs];
    int e = cur[prefs];
    int d = (prev2[0] + next2[0]) >> 1;

    int tdiff_prev = (prev[mrefs] - c);
    int tdiff_prev_sign = tdiff_prev ^ (tdiff_prev >> 31);
    tdiff_prev_sign -= (tdiff_prev >> 31);

    int tdiff_prev_p = (prev[prefs] - e);
    int tdiff_prev_p_sign = tdiff_prev_p ^ (tdiff_prev_p >> 31);
    tdiff_prev_p_sign -= (tdiff_prev_p >> 31);

    int tdiff_next = (next[mrefs] - c);
    int tdiff_next_sign = tdiff_next ^ (tdiff_next >> 31);
    tdiff_next_sign -= (tdiff_next >> 31);

    int tdiff_next_p = (next[prefs] - e);
    int tdiff_next_p_sign = tdiff_next_p ^ (tdiff_next_p >> 31);
    tdiff_next_p_sign -= (tdiff_next_p >> 31);

    int temporal_diff1 = (tdiff_prev_sign + tdiff_prev_p_sign) >> 1;
    int temporal_diff2 = (tdiff_next_sign + tdiff_next_p_sign) >> 1;
    int temporal_diff0 = (prev2[0] - next2[0]);
    temporal_diff0 = (temporal_diff0 ^ (temporal_diff0 >> 31)) - (temporal_diff0 >> 31);

    int mid_diff = (temporal_diff0 >> 1);
    int diff = mid_diff;
    if (temporal_diff1 > diff) diff = temporal_diff1;
    if (temporal_diff2 > diff) diff = temporal_diff2;

    int spatial_pred = (c + e) >> 1;

    if (!(mode & 2)) {
        int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;

        int max_val = (d - e);
        if (d - c > max_val) max_val = d - c;
        if (b - c > max_val) max_val = b - c;
        if (f - e > max_val) max_val = f - e;

        int min_val = (d - e);
        if (d - c < min_val) min_val = d - c;
        if (b - c < min_val) min_val = b - c;
        if (f - e < min_val) min_val = f - e;

        diff = (diff > min_val) ? diff : min_val;
        diff = (diff > -max_val) ? -max_val : diff;
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
