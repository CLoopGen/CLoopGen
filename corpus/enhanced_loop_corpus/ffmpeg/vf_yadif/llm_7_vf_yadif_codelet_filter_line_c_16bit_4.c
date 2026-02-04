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
for (x = 0; x < w; x++) {
    // Reorder computations to eliminate some redundant address calculations and flatten dependencies
    uint16_t cur_mrefs = cur[mrefs];
    uint16_t cur_prefs = cur[prefs];
    uint16_t prev2_0 = prev2[0];
    uint16_t next2_0 = next2[0];
    uint16_t prev_mrefs = prev[mrefs];
    uint16_t prev_prefs = prev[prefs];
    uint16_t next_mrefs = next[mrefs];
    uint16_t next_prefs = next[prefs];

    int c = cur_mrefs;
    int e = cur_prefs;
    int d = (prev2_0 + next2_0) >> 1;
    int temporal_diff0 = (prev2_0 > next2_0) ? (prev2_0 - next2_0) : (next2_0 - prev2_0);
    int temporal_diff1 = (((prev_mrefs - c) > 0 ? (prev_mrefs - c) : (c - prev_mrefs)) + ((prev_prefs - e) > 0 ? (prev_prefs - e) : (e - prev_prefs))) >> 1;
    int temporal_diff2 = (((next_mrefs - c) > 0 ? (next_mrefs - c) : (c - next_mrefs)) + ((next_prefs - e) > 0 ? (next_prefs - e) : (e - next_prefs))) >> 1;
    int base_diff = (temporal_diff0 >> 1);
    int mid_diff = (base_diff > temporal_diff1) ? base_diff : temporal_diff1;
    int diff = (mid_diff > temporal_diff2) ? mid_diff : temporal_diff2;
    int spatial_pred = (c + e) >> 1;

    // Remove nested conditional blocks and inline comparisons to reduce control dependencies
    int spatial_score = ((cur[mrefs - 1] - cur[prefs - 1]) > 0 ? (cur[mrefs - 1] - cur[prefs - 1]) : (cur[prefs - 1] - cur[mrefs - 1])) +
                        ((c - e) > 0 ? (c - e) : (e - c)) +
                        ((cur[mrefs + 1] - cur[prefs + 1]) > 0 ? (cur[mrefs + 1] - cur[prefs + 1]) : (cur[prefs + 1] - cur[mrefs + 1])) - 1;

    // Unroll spatial search over offsets -2 to +2 explicitly without nested scopes
    const int offsets[] = {-2, -1, 1, 2};
    for (int i = 0; i < 4; i++) {
        int off = offsets[i];
        int score = ((cur[mrefs - 1 + off] - cur[prefs - 1 - off]) > 0 ? (cur[mrefs - 1 + off] - cur[prefs - 1 - off]) : (cur[prefs - 1 - off] - cur[mrefs - 1 + off])) +
                   ((cur[mrefs + off] - cur[prefs - off]) > 0 ? (cur[mrefs + off] - cur[prefs - off]) : (cur[prefs - off] - cur[mrefs + off])) +
                   ((cur[mrefs + 1 + off] - cur[prefs + 1 - off]) > 0 ? (cur[mrefs + 1 + off] - cur[prefs + 1 - off]) : (cur[prefs + 1 - off] - cur[mrefs + 1 + off]));
        if (score < spatial_score) {
            spatial_score = score;
            spatial_pred = (cur[mrefs + off] + cur[prefs - off]) >> 1;
        }
    }

    // Modify conditional logic in mode block to remove complex nesting and simplify WAW hazards
    if (!(mode & 2)) {
        uint16_t prev2_2mrefs = prev2[2 * mrefs];
        uint16_t next2_2mrefs = next2[2 * mrefs];
        uint16_t prev2_2prefs = prev2[2 * prefs];
        uint16_t next2_2prefs = next2[2 * prefs];
        int b = (prev2_2mrefs + next2_2mrefs) >> 1;
        int f = (prev2_2prefs + next2_2prefs) >> 1;

        int term1 = (d - e) > (d - c) ? (d - e) : (d - c);
        int term2 = (b - c) > (f - e) ? (f - e) : (b - c);
        int max = term1 > term2 ? term1 : term2;

        int term3 = (d - e) > (d - c) ? (d - c) : (d - e);
        int term4 = (b - c) > (f - e) ? (b - c) : (f - e);
        int min = term3 > term4 ? term4 : term3;

        diff = (diff > min ? diff : min);
        diff = (diff > -max ? diff : -max);
    }

    // Clamp spatial_pred using simplified branching
    if (spatial_pred > d + diff)
        spatial_pred = d + diff;
    else if (spatial_pred < d - diff)
        spatial_pred = d - diff;

    dst[0] = spatial_pred;

    // Eliminate pointer arithmetic overlap by updating all pointers at the end
    dst += 1;
    cur += 1;
    prev += 1;
    next += 1;
    prev2 += 1;
    next2 += 1;
}
}
