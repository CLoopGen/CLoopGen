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
    int temporal_diff0 = (prev2[0] > next2[0]) ? (prev2[0] - next2[0]) : (next2[0] - prev2[0]);
    int temporal_diff1 = ((prev[mrefs] > c ? prev[mrefs] - c : c - prev[mrefs]) + (prev[prefs] > e ? prev[prefs] - e : e - prev[prefs])) >> 1;
    int temporal_diff2 = ((next[mrefs] > c ? next[mrefs] - c : c - next[mrefs]) + (next[prefs] > e ? next[prefs] - e : e - next[prefs])) >> 1;
    int diff = (temporal_diff0 >> 1);
    if (temporal_diff1 > diff) diff = temporal_diff1;
    if (temporal_diff2 > diff) diff = temporal_diff2;

    int spatial_pred = (c + e) >> 1;

    // Introduce early skip condition based on mode bits to alter control path
    if (!(mode & 1)) {
        // Use a more aggressive spatial search over multiple offsets with explicit branches
        int best_score = 1000000;
        
        // Check offset -2
        int score = ((cur[mrefs - 1 - 2] > cur[prefs - 1 + 2] ? cur[mrefs - 1 - 2] - cur[prefs - 1 + 2] : cur[prefs - 1 + 2] - cur[mrefs - 1 - 2])) +
                    ((cur[mrefs - 2] > cur[prefs + 2] ? cur[mrefs - 2] - cur[prefs + 2] : cur[prefs + 2] - cur[mrefs - 2])) +
                    ((cur[mrefs + 1 - 2] > cur[prefs + 1 + 2] ? cur[mrefs + 1 - 2] - cur[prefs + 1 + 2] : cur[prefs + 1 + 2] - cur[mrefs + 1 - 2]));
        if (score < best_score) {
            best_score = score;
            spatial_pred = (cur[mrefs - 2] + cur[prefs + 2]) >> 1;
        }

        // Check offset -1
        score = ((cur[mrefs - 1 - 1] > cur[prefs - 1 + 1] ? cur[mrefs - 1 - 1] - cur[prefs - 1 + 1] : cur[prefs - 1 + 1] - cur[mrefs - 1 - 1])) +
                ((cur[mrefs - 1] > cur[prefs + 1] ? cur[mrefs - 1] - cur[prefs + 1] : cur[prefs + 1] - cur[mrefs - 1])) +
                ((cur[mrefs + 1 - 1] > cur[prefs + 1 + 1] ? cur[mrefs + 1 - 1] - cur[prefs + 1 + 1] : cur[prefs + 1 + 1] - cur[mrefs + 1 - 1]));
        if (score < best_score) {
            best_score = score;
            spatial_pred = (cur[mrefs - 1] + cur[prefs + 1]) >> 1;
        }

        // Check center (offset 0) — already computed as initial value
        score = ((cur[mrefs - 1] > cur[prefs - 1] ? cur[mrefs - 1] - cur[prefs - 1] : cur[prefs - 1] - cur[mrefs - 1])) +
                ((c > e ? c - e : e - c)) +
                ((cur[mrefs + 1] > cur[prefs + 1] ? cur[mrefs + 1] - cur[prefs + 1] : cur[prefs + 1] - cur[mrefs + 1]));
        if (score < best_score) {
            best_score = score;
            spatial_pred = (c + e) >> 1;
        }

        // Check offset +1
        score = ((cur[mrefs - 1 + 1] > cur[prefs - 1 - 1] ? cur[mrefs - 1 + 1] - cur[prefs - 1 - 1] : cur[prefs - 1 - 1] - cur[mrefs - 1 + 1])) +
                ((cur[mrefs + 1] > cur[prefs - 1] ? cur[mrefs + 1] - cur[prefs - 1] : cur[prefs - 1] - cur[mrefs + 1])) +
                ((cur[mrefs + 1 + 1] > cur[prefs + 1 - 1] ? cur[mrefs + 1 + 1] - cur[prefs + 1 - 1] : cur[prefs + 1 - 1] - cur[mrefs + 1 + 1]));
        if (score < best_score) {
            best_score = score;
            spatial_pred = (cur[mrefs + 1] + cur[prefs - 1]) >> 1;
        }

        // Check offset +2
        score = ((cur[mrefs - 1 + 2] > cur[prefs - 1 - 2] ? cur[mrefs - 1 + 2] - cur[prefs - 1 - 2] : cur[prefs - 1 - 2] - cur[mrefs - 1 + 2])) +
                ((cur[mrefs + 2] > cur[prefs - 2] ? cur[mrefs + 2] - cur[prefs - 2] : cur[prefs - 2] - cur[mrefs + 2])) +
                ((cur[mrefs + 1 + 2] > cur[prefs + 1 - 2] ? cur[mrefs + 1 + 2] - cur[prefs + 1 - 2] : cur[prefs + 1 - 2] - cur[mrefs + 1 + 2]));
        if (score < best_score) {
            spatial_pred = (cur[mrefs + 2] + cur[prefs - 2]) >> 1;
        }
    } else {
        // Alternative path: skip spatial refinement and use temporal median
        spatial_pred = d;
    }

    // Apply mode-dependent clamping logic with modified control
    if (mode & 2) {
        int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int max = (d - e) > (d - c) ? (d - e) : (d - c);
        max = (b - c) > (f - e) ? (b - c) : (f - e);
        if (max > ((d - e) > (d - c) ? (d - e) : (d - c)))
            max = (d - e) > (d - c) ? (d - e) : (d - c);

        int min = (d - e) < (d - c) ? (d - e) : (d - c);
        min = (b - c) < (f - e) ? (b - c) : (f - e);
        if (min < ((d - e) < (d - c) ? (d - e) : (d - c)))
            min = (d - e) < (d - c) ? (d - e) : (d - c);

        diff = (diff > min) ? diff : min;
        diff = (-max > diff) ? -max : diff;
    }

    // Final clamping
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
