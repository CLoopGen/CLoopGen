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
for (x = 0; x < ((3) > (w) ? (w) : (3)); x++) {
    int idx_cur = x & 7;
    int idx_prev = (x * 3) & 15;
    int idx_next = (x * 5) & 15;
    int idx_temporal = (x * 7) & 31;

    int c = cur[idx_cur];
    int d = (prev2[idx_temporal] + next2[idx_temporal]) >> 1;
    int e = cur[(idx_cur + 2) & 7];
    int temporal_diff0 = ((prev2[idx_temporal] - next2[idx_temporal]) >= 0 ? (prev2[idx_temporal] - next2[idx_temporal]) : (-(prev2[idx_temporal] - next2[idx_temporal])));
    int temporal_diff1 = (((prev[idx_prev] - c) >= 0 ? (prev[idx_prev] - c) : (-(prev[idx_prev] - c))) + ((prev[(idx_prev + 1) & 15] - e) >= 0 ? (prev[(idx_prev + 1) & 15] - e) : (-(prev[(idx_prev + 1) & 15] - e)))) >> 1;
    int temporal_diff2 = (((next[idx_next] - c) >= 0 ? (next[idx_next] - c) : (-(next[idx_next] - c))) + ((next[(idx_next + 1) & 15] - e) >= 0 ? (next[(idx_next + 1) & 15] - e) : (-(next[(idx_next + 1) & 15] - e)))) >> 1;
    int diff = ((((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) > (temporal_diff2) ? (((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) : (temporal_diff2));
    int spatial_pred = (c + e) >> 1;

    if (0) {
        int spatial_score = ((cur[(idx_cur - 1) & 7] - cur[(idx_cur + 1) & 7]) >= 0 ? (cur[(idx_cur - 1) & 7] - cur[(idx_cur + 1) & 7]) : (-(cur[(idx_cur - 1) & 7] - cur[(idx_cur + 1) & 7]))) + ((c - e) >= 0 ? (c - e) : (-(c - e))) + ((cur[(idx_cur + 1) & 7] - cur[(idx_cur + 3) & 7]) >= 0 ? (cur[(idx_cur + 1) & 7] - cur[(idx_cur + 3) & 7]) : (-(cur[(idx_cur + 1) & 7] - cur[(idx_cur + 3) & 7]))) - 1;
        for (int offset = -2; offset <= 2; offset += 1) {
            if (offset == 0) continue;
            int nidx = (idx_cur + offset) & 7;
            int score = ((cur[(nidx - 1) & 7] - cur[(nidx + 1) & 7]) >= 0 ? (cur[(nidx - 1) & 7] - cur[(nidx + 1) & 7]) : (-(cur[(nidx - 1) & 7] - cur[(nidx + 1) & 7]))) + ((cur[nidx] - cur[(nidx + 2) & 7]) >= 0 ? (cur[nidx] - cur[(nidx + 2) & 7]) : (-(cur[nidx] - cur[(nidx + 2) & 7]))) + ((cur[(nidx + 1) & 7] - cur[(nidx + 3) & 7]) >= 0 ? (cur[(nidx + 1) & 7] - cur[(nidx + 3) & 7]) : (-(cur[(nidx + 1) & 7] - cur[(nidx + 3) & 7])));
            if (score < spatial_score) {
                spatial_score = score;
                spatial_pred = (cur[nidx] + cur[(nidx + 2) & 7]) >> 1;
            }
        }
    }

    if (!(mode & 2)) {
        int b = (prev2[(idx_temporal * 2) & 31] + next2[(idx_temporal * 2) & 31]) >> 1;
        int f = (prev2[(idx_temporal * 2 + 1) & 31] + next2[(idx_temporal * 2 + 1) & 31]) >> 1;
        int max = ((((d - e) > (d - c) ? (d - e) : (d - c))) > (((b - c) > (f - e) ? (f - e) : (b - c))) ? (((d - e) > (d - c) ? (d - e) : (d - c))) : (((b - c) > (f - e) ? (f - e) : (b - c))));
        int min = ((((d - e) > (d - c) ? (d - c) : (d - e))) > (((b - c) > (f - e) ? (b - c) : (f - e))) ? (((b - c) > (f - e) ? (b - c) : (f - e))) : (((d - e) > (d - c) ? (d - c) : (d - e))));
        diff = ((((diff) > (min) ? (diff) : (min))) > (-max) ? (((diff) > (min) ? (diff) : (min))) : (-max));
    }

    if (spatial_pred > d + diff)
        spatial_pred = d + diff;
    else if (spatial_pred < d - diff)
        spatial_pred = d - diff;

    dst[x] = spatial_pred;
}
}
