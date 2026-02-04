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
for (x = offset; x < w; x++) {
    int c = cur[mrefs];
    int d = (prev2[0] + next2[0]) >> 1;
    int e = cur[prefs];
    int temporal_diff0 = ((prev2[0] - next2[0]) >= 0 ? (prev2[0] - next2[0]) : (-(prev2[0] - next2[0])));
    int temporal_diff1 = (((prev[mrefs] - c) >= 0 ? (prev[mrefs] - c) : (-(prev[mrefs] - c))) + ((prev[prefs] - e) >= 0 ? (prev[prefs] - e) : (-(prev[prefs] - e)))) >> 1;
    int temporal_diff2 = (((next[mrefs] - c) >= 0 ? (next[mrefs] - c) : (-(next[mrefs] - c))) + ((next[prefs] - e) >= 0 ? (next[prefs] - e) : (-(next[prefs] - e)))) >> 1;
    int diff = ((((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) > (temporal_diff2) ? (((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) : (temporal_diff2));
    int spatial_pred = (c + e) >> 1;

    // Removed the entire spatial_score refinement block unconditionally
    // Also removed mode-based conditional logic entirely

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
