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
for (x = offset; x < w - 7; x++) {
    int c = cur[mrefs];
    int e = cur[prefs];
    int d = (prev2[0] + next2[0]) >> 1;

    // Simplified temporal differences with reduced branching via ABS-like macro
    #define ABS(x) ((x) < 0 ? -(x) : (x))
    int temporal_diff0 = ABS(prev2[0] - next2[0]);
    int temporal_diff1 = (ABS(prev[mrefs] - c) + ABS(prev[prefs] - e)) >> 1;
    int temporal_diff2 = (ABS(next[mrefs] - c) + ABS(next[prefs] - e)) >> 1;
    int diff = temporal_diff0 >> 1;
    diff = diff > temporal_diff1 ? diff : temporal_diff1;
    diff = diff > temporal_diff2 ? diff : temporal_diff2;

    int spatial_pred = (c + e) >> 1;

    // Reduced spatial prediction search: only check one offset instead of multiple
    int spatial_score = ABS(cur[mrefs - 1] - cur[prefs - 1]) +
                        ABS(c - e) +
                        ABS(cur[mrefs + 1] - cur[prefs + 1]) - 1;

    // Only test offset +1, skip others to reduce complexity
    int score_shift1 = ABS(cur[mrefs - 1 + 1] - cur[prefs - 1 - 1]) +
                       ABS(cur[mrefs + 1] - cur[prefs - 1]) +
                       ABS(cur[mrefs + 1 + 1] - cur[prefs + 1 - 1]);
    if (score_shift1 < spatial_score) {
        spatial_score = score_shift1;
        spatial_pred = (cur[mrefs + 1] + cur[prefs - 1]) >> 1;
    }

    // Skip mode-dependent block entirely for higher performance
    // (simulating a simplified processing path)

    // Clamping with conditional ternary
    spatial_pred = spatial_pred > (d + diff) ? (d + diff) :
                   spatial_pred < (d - diff) ? (d - diff) : spatial_pred;

    dst[0] = spatial_pred;

    // Advance pointers
    dst++;
    cur++;
    prev++;
    next++;
    prev2++;
    next2++;
}
}
