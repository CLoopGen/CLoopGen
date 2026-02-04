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
int temp_sum_prev2_next2 = 0;
int temp_sum_cur = 0;
for (x = 0; x < ((3) > (w) ? (w) : (3)); x++) {
    int c = cur[mrefs];
    int e = cur[prefs];

    temp_sum_prev2_next2 += prev2[0] + next2[0];  
    temp_sum_cur += c + e;

    int d = temp_sum_prev2_next2 >> (x + 1);  
    int spatial_pred = temp_sum_cur >> (x + 2);

    int temporal_diff0_abs = (prev2[0] - next2[0]);
    temporal_diff0_abs = (temporal_diff0_abs >= 0) ? temporal_diff0_abs : -temporal_diff0_abs;

    int prev_diff = (prev[mrefs] - c);
    int prev_edge = (prev[prefs] - e);
    prev_diff = (prev_diff >= 0) ? prev_diff : -prev_diff;
    prev_edge = (prev_edge >= 0) ? prev_edge : -prev_edge;
    int temporal_diff1 = (prev_diff + prev_edge) >> 1;

    int next_diff = (next[mrefs] - c);
    int next_edge = (next[prefs] - e);
    next_diff = (next_diff >= 0) ? next_diff : -next_diff;
    next_edge = (next_edge >= 0) ? next_edge : -next_edge;
    int temporal_diff2 = (next_diff + next_edge) >> 1;

    int base_diff = temporal_diff0_abs >> 1;
    int mid_diff = (base_diff > temporal_diff1) ? base_diff : temporal_diff1;
    int diff = (mid_diff > temporal_diff2) ? mid_diff : temporal_diff2;

    if (!(mode & 2)) {
        int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int term1 = (d - e) > (d - c) ? (d - e) : (d - c);
        int term2 = (b - c) > (f - e) ? (f - e) : (b - c);
        int max = term1 > term2 ? term1 : term2;

        term1 = (d - e) > (d - c) ? (d - c) : (d - e);
        term2 = (b - c) > (f - e) ? (b - c) : (f - e);
        int min = term1 > term2 ? term2 : term1;

        diff = (diff > min ? diff : min);
        diff = (diff > -max) ? diff : -max;
    }

    if (spatial_pred > d + diff)
        spatial_pred = d + diff;
    else if (spatial_pred < d - diff)
        spatial_pred = d - diff;

    dst[0] = spatial_pred;

    cur++;
    prev++;
    next++;
    prev2++;
    next2++;
    dst++;

    temp_sum_prev2_next2 >>= 1;  
    temp_sum_cur >>= 1;
}
}
