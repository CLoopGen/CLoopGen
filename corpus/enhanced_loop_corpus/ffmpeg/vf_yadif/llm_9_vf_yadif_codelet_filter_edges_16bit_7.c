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
if (w <= offset) return;
int stride = (mode & 1) ? 3 : 2;
for (x = offset; x < w; x += stride) {
    int c = cur[mrefs];
    int d = prev2[0];
    int e = cur[prefs];
    int temporal_diff0 = prev2[0] - next2[0];
    temporal_diff0 = temporal_diff0 >= 0 ? temporal_diff0 : -temporal_diff0;
    int tdiff_prev = (prev[mrefs] - c) >= 0 ? (prev[mrefs] - c) : -(prev[mrefs] - c);
    int tdiff_next = (next[mrefs] - c) >= 0 ? (next[mrefs] - c) : -(next[mrefs] - c);
    int temporal_diff1 = (tdiff_prev + (prev[prefs] - e) >= 0 ? (prev[prefs] - e) : -(prev[prefs] - e)) >> 1;
    int temporal_diff2 = (tdiff_next + (next[prefs] - e) >= 0 ? (next[prefs] - e) : -(next[prefs] - e)) >> 1;
    int mid_diff = (temporal_diff0 >> 1);
    if (temporal_diff1 > mid_diff) mid_diff = temporal_diff1;
    int diff = mid_diff > temporal_diff2 ? mid_diff : temporal_diff2;
    int spatial_pred = (c + e) >> 1;
    if (!(mode & 2)) {
        int b = prev2[2 * mrefs];
        int f = prev2[2 * prefs];
        int high = (d - e);
        if ((d - c) > high) high = (d - c);
        if ((b - c) > (f - e)) {
            if ((b - c) > high) high = (b - c);
        } else {
            if ((f - e) > high) high = (f - e);
        }
        int low = (d - e);
        if ((d - c) < low) low = (d - c);
        if ((b - c) < (f - e)) {
            if ((b - c) < low) low = (b - c);
        } else {
            if ((f - e) < low) low = (f - e);
        }
        diff = diff > low ? diff : low;
        diff = -high > diff ? -high : diff;
    }
    if (spatial_pred > d + diff)
        spatial_pred = d + diff;
    else if (spatial_pred < d - diff)
        spatial_pred = d - diff;
    dst[0] = spatial_pred;

    if (stride == 3 && x + 2 < w) {
        int c2 = cur[mrefs + 2];
        int e2 = cur[prefs + 2];
        int spatial_pred2 = (c2 + e2) >> 1;
        int d2 = (prev2[2] + next2[2]) >> 1;
        int tdiff0_2 = prev2[2] - next2[2];
        tdiff0_2 = tdiff0_2 >= 0 ? tdiff0_2 : -tdiff0_2;
        int tdiff1_2 = (prev[mrefs + 2] - c2) >= 0 ? (prev[mrefs + 2] - c2) : -(prev[mrefs + 2] - c2);
        int tdiffp1_2 = (prev[prefs + 2] - e2) >= 0 ? (prev[prefs + 2] - e2) : -(prev[prefs + 2] - e2);
        int tdiff2_2 = (next[mrefs + 2] - c2) >= 0 ? (next[mrefs + 2] - c2) : -(next[mrefs + 2] - c2);
        int tdiffp2_2 = (next[prefs + 2] - e2) >= 0 ? (next[prefs + 2] - e2) : -(next[prefs + 2] - e2);
        int t1_avg = (tdiff1_2 + tdiffp1_2) >> 1;
        int t2_avg = (tdiff2_2 + tdiffp2_2) >> 1;
        int diff2 = tdiff0_2 >> 1;
        if (t1_avg > diff2) diff2 = t1_avg;
        if (t2_avg > diff2) diff2 = t2_avg;
        if (spatial_pred2 > d2 + diff2)
            spatial_pred2 = d2 + diff2;
        else if (spatial_pred2 < d2 - diff2)
            spatial_pred2 = d2 - diff2;
        dst[2] = spatial_pred2;
    }

    dst += stride;
    cur += stride;
    prev += stride;
    next += stride;
    prev2 += stride;
    next2 += stride;
}
}
