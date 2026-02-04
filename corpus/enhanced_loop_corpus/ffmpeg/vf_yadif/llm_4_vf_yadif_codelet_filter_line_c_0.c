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
    int c = cur[mrefs];
    int d = (prev2[0] + next2[0]) >> 1;
    int e = cur[prefs];
    int temporal_diff0 = ((prev2[0] - next2[0]) >= 0 ? (prev2[0] - next2[0]) : (-(prev2[0] - next2[0])));
    int temporal_diff1 = (((prev[mrefs] - c) >= 0 ? (prev[mrefs] - c) : (-(prev[mrefs] - c))) + ((prev[prefs] - e) >= 0 ? (prev[prefs] - e) : (-(prev[prefs] - e)))) >> 1;
    int temporal_diff2 = (((next[mrefs] - c) >= 0 ? (next[mrefs] - c) : (-(next[mrefs] - c))) + ((next[prefs] - e) >= 0 ? (next[prefs] - e) : (-(next[prefs] - e)))) >> 1;
    int diff = ((((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) > (temporal_diff2) ? (((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) : (temporal_diff2));
    int spatial_pred = (c + e) >> 1;

    // Removed nested conditional structure and replaced with simplified scoring using fixed offset
    int spatial_score = ((cur[mrefs - 1] - cur[prefs - 1]) >= 0 ? (cur[mrefs - 1] - cur[prefs - 1]) : (-(cur[mrefs - 1] - cur[prefs - 1]))) +
                        ((c - e) >= 0 ? (c - e) : (-(c - e))) +
                        ((cur[mrefs + 1] - cur[prefs + 1]) >= 0 ? (cur[mrefs + 1] - cur[prefs + 1]) : (-(cur[mrefs + 1] - cur[prefs + 1])));

    // Evaluate only the +1 offset unconditionally
    int score_plus1 = ((cur[mrefs - 1 + 1] - cur[prefs - 1 - 1]) >= 0 ? (cur[mrefs - 1 + 1] - cur[prefs - 1 - 1]) : (-(cur[mrefs - 1 + 1] - cur[prefs - 1 - 1]))) +
                      ((cur[mrefs + 1] - cur[prefs - 1]) >= 0 ? (cur[mrefs + 1] - cur[prefs - 1]) : (-(cur[mrefs + 1] - cur[prefs - 1]))) +
                      ((cur[mrefs + 1 + 1] - cur[prefs + 1 - 1]) >= 0 ? (cur[mrefs + 1 + 1] - cur[prefs + 1 - 1]) : (-(cur[mrefs + 1 + 1] - cur[prefs + 1 - 1])));

    if (score_plus1 < spatial_score) {
        spatial_score = score_plus1;
        spatial_pred = (cur[mrefs + 1] + cur[prefs - 1]) >> 1;
    }

    // Skip mode-based adjustment entirely to simplify control flow
    // Instead, directly clamp spatial_pred using basic bounds derived from d and diff

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
