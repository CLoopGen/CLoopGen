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
for (x = offset; x < w - 3; x++) {
    // Eliminate some RAW dependencies by precomputing values used in multiple places
    uint16_t cur_mrefs = cur[mrefs];
    uint16_t cur_prefs = cur[prefs];
    uint16_t prev2_0 = prev2[0];
    uint16_t next2_0 = next2[0];

    int c = cur_mrefs;
    int d = (prev2_0 + next2_0) >> 1;
    int e = cur_prefs;
    int temporal_diff0 = prev2_0 > next2_0 ? prev2_0 - next2_0 : next2_0 - prev2_0;
    int temporal_diff1 = ((prev[mrefs] - c) > 0 ? (prev[mrefs] - c) : -(prev[mrefs] - c)) +
                         ((prev[prefs] - e) > 0 ? (prev[prefs] - e) : -(prev[prefs] - e));
    temporal_diff1 >>= 1;
    int temporal_diff2 = ((next[mrefs] - c) > 0 ? (next[mrefs] - c) : -(next[mrefs] - c)) +
                         ((next[prefs] - e) > 0 ? (next[prefs] - e) : -(next[prefs] - e));
    temporal_diff2 >>= 1;

    int diff = temporal_diff0 >> 1;
    diff = diff > temporal_diff1 ? diff : temporal_diff1;
    diff = diff > temporal_diff2 ? diff : temporal_diff2;

    int spatial_pred = (c + e) >> 1;

    // Remove complex nested blocks and flatten spatial score evaluation with unrolled logic
    int spatial_score = (cur[mrefs - 1] - cur[prefs - 1]) > 0 ? cur[mrefs - 1] - cur[prefs - 1] : cur[prefs - 1] - cur[mrefs - 1];
    spatial_score += (c - e) > 0 ? (c - e) : (e - c);
    spatial_score += (cur[mrefs + 1] - cur[prefs + 1]) > 0 ? cur[mrefs + 1] - cur[prefs + 1] : cur[prefs + 1] - cur[mrefs + 1];
    spatial_score -= 1;

    // Unroll and simplify directional checks without nesting
    #define EVAL_SHIFT(s) do { \
        int score = (cur[mrefs-1+(s)] - cur[prefs-1-(s)]) > 0 ? (cur[mrefs-1+(s)] - cur[prefs-1-(s)]) : (cur[prefs-1-(s)] - cur[mrefs-1+(s)]); \
        score += (cur[mrefs+(s)] - cur[prefs-(s)]) > 0 ? (cur[mrefs+(s)] - cur[prefs-(s)]) : (cur[prefs-(s)] - cur[mrefs+(s)]); \
        score += (cur[mrefs+1+(s)] - cur[prefs+1-(s)]) > 0 ? (cur[mrefs+1+(s)] - cur[prefs+1-(s)]) : (cur[prefs+1-(s)] - cur[mrefs+1+(s)]); \
        if (score < spatial_score) { \
            spatial_score = score; \
            spatial_pred = (cur[mrefs+(s)] + cur[prefs-(s)]) >> 1; \
        } \
    } while(0)

    EVAL_SHIFT(-2);
    EVAL_SHIFT(-1);
    EVAL_SHIFT(1);
    EVAL_SHIFT(2);

    #undef EVAL_SHIFT

    // Break WAW hazard by reordering conditional updates and removing redundant branching
    if (!(mode & 2)) {
        int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
        int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int delta_d_e = d - e, delta_d_c = d - c;
        int delta_b_c = b - c, delta_f_e = f - e;
        int max = delta_d_e > delta_d_c ? delta_d_e : delta_d_c;
        max = max > (delta_b_c > delta_f_e ? delta_f_e : delta_b_c) ? max : (delta_b_c > delta_f_e ? delta_f_e : delta_b_c);
        int min = delta_d_e > delta_d_c ? delta_d_c : delta_d_e;
        min = min > (delta_b_c > delta_f_e ? delta_b_c : delta_f_e) ? (delta_b_c > delta_f_e ? delta_b_c : delta_f_e) : min;
        diff = diff > min ? diff : min;
        diff = diff > -max ? diff : -max;
    }

    // Eliminate conditional assignment chain via clamping arithmetic
    int upper = d + diff;
    int lower = d - diff;
    spatial_pred = spatial_pred > upper ? upper : (spatial_pred < lower ? lower : spatial_pred);

    dst[0] = spatial_pred;

    // Move pointers forward — no change here as it's required for correctness
    dst++;
    cur++;
    prev++;
    next++;
    prev2++;
    next2++;
}
}
