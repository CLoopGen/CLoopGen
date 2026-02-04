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
    // Reorder memory accesses to eliminate some false dependencies and reorganize evaluation order
    uint8_t cur_mrefs = cur[mrefs];
    uint8_t cur_prefs = cur[prefs];
    uint8_t prev2_0 = prev2[0];
    uint8_t next2_0 = next2[0];
    uint8_t prev_mrefs = prev[mrefs];
    uint8_t prev_prefs = prev[prefs];
    uint8_t next_mrefs = next[mrefs];
    uint8_t next_prefs = next[prefs];

    int c = cur_mrefs;
    int e = cur_prefs;
    int d = (prev2_0 + next2_0) >> 1;
    int temporal_diff0 = prev2_0 > next2_0 ? prev2_0 - next2_0 : next2_0 - prev2_0;
    int temporal_diff1 = ((prev_mrefs > c ? prev_mrefs - c : c - prev_mrefs) + (prev_prefs > e ? prev_prefs - e : e - prev_prefs)) >> 1;
    int temporal_diff2 = ((next_mrefs > c ? next_mrefs - c : c - next_mrefs) + (next_prefs > e ? next_prefs - e : e - next_prefs)) >> 1;

    // Combine comparisons into single expressions without nested ternary depth
    int mid_diff = temporal_diff1 > (temporal_diff0 >> 1) ? temporal_diff1 : (temporal_diff0 >> 1);
    int diff = mid_diff > temporal_diff2 ? mid_diff : temporal_diff2;

    int spatial_pred = (c + e) >> 1;

    // Remove the entire spatial refinement block (dead code due to `if (0)`), eliminating its data dependencies
    // This reduces RAW/WAR hazards from array indexing with variable offsets

    if (!(mode & 2)) {
        // Load non-byte-aligned indices early
        int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;

        // Restructure min/max logic using temporary variables for clarity and dependency control
        int term1 = d - e;
        int term2 = d - c;
        int term3 = b - c;
        int term4 = f - e;

        int max_term_left = term1 > term2 ? term1 : term2;
        int max_term_right = term3 > term4 ? term3 : term4;
        int max_val = max_term_left > max_term_right ? max_term_left : max_term_right;

        int min_term_left = term1 < term2 ? term1 : term2;
        int min_term_right = term3 < term4 ? term3 : term4;
        int min_val = min_term_left < min_term_right ? min_term_left : min_term_right;

        diff = diff > min_val ? diff : min_val;
        diff = diff > -max_val ? diff : -max_val;
    }

    // Clamp spatial_pred using simplified conditional logic
    int upper_bound = d + diff;
    int lower_bound = d - diff;
    if (spatial_pred > upper_bound) spatial_pred = upper_bound;
    else if (spatial_pred < lower_bound) spatial_pred = lower_bound;

    // Store result and advance pointers — no interleaved computation
    *dst = (uint8_t)spatial_pred;
    dst++; cur++; prev++; next++; prev2++; next2++;
}
}
