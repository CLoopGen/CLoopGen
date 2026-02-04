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
    // Eliminate some RAW dependencies by reordering independent computations
    int temp_offset = mrefs;
    int prefetch_prev2 = prev2[0];
    int prefetch_next2 = next2[0];

    // Precompute values not directly dependent on `cur` early to reduce apparent RAW chain
    int d = (prefetch_prev2 + prefetch_next2) >> 1;
    int temporal_diff0 = ((prefetch_prev2 - prefetch_next2) >= 0 ? (prefetch_prev2 - prefetch_next2) : (-(prefetch_prev2 - prefetch_next2)));

    // Now load cur and other data — reordered to break strict sequential dependency
    int c = cur[temp_offset];
    int e = cur[prefs];

    int temporal_diff1 = (((prev[temp_offset] - c) >= 0 ? (prev[temp_offset] - c) : (-(prev[temp_offset] - c))) + 
                          ((prev[prefs] - e) >= 0 ? (prev[prefs] - e) : (-(prev[prefs] - e)))) >> 1;
    int temporal_diff2 = (((next[temp_offset] - c) >= 0 ? (next[temp_offset] - c) : (-(next[temp_offset] - c))) + 
                          ((next[prefs] - e) >= 0 ? (next[prefs] - e) : (-(next[prefs] - e)))) >> 1;

    int diff = ((((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) > (temporal_diff2) ? 
                (((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) : (temporal_diff2));

    int spatial_pred = (c + e) >> 1;

    // Removed unused spatial score block entirely (dead code elimination mimicking compiler optimization)
    // This reduces memory access dependencies and removes WAR/WAW hazards from shadowed variables

    if (!(mode & 2)) {
        // Modify indexing pattern to remove multiplicative offset in address calculation
        // Use precomputed base indices to change data flow
        int idx_m = 2 * mrefs;
        int idx_p = 2 * prefs;
        int b = (prev2[idx_m] + next2[idx_m]) >> 1;
        int f = (prev2[idx_p] + next2[idx_p]) >> 1;

        int branch1 = (d - e) > (d - c) ? (d - e) : (d - c);
        int branch2 = (b - c) > (f - e) ? (f - e) : (b - c);
        int max = branch1 > branch2 ? branch1 : branch2;

        int min_branch1 = (d - e) > (d - c) ? (d - c) : (d - e);
        int min_branch2 = (b - c) > (f - e) ? (b - c) : (f - e);
        int min = min_branch1 > min_branch2 ? min_branch2 : min_branch1;

        diff = ((diff > min ? diff : min) > (-max)) ? ((diff > min ? diff : min)) : (-max);
    }

    // Clamp spatial_pred using updated bounds
    if (spatial_pred > d + diff)
        spatial_pred = d + diff;
    else if (spatial_pred < d - diff)
        spatial_pred = d - diff;

    // Store result via pointer
    *dst = spatial_pred;

    // Increment all pointers — maintain original semantics
    dst++;
    cur++;
    prev++;
    next++;
    prev2++;
    next2++;
}
}
