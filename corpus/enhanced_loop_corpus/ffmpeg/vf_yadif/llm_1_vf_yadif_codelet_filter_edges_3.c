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
for (x = offset; x < w; x += 2) {
    for (int unroll_factor = 0; unroll_factor < 2 && (x + unroll_factor) < w; unroll_factor++) {
        int idx = x + unroll_factor;
        uint8_t *cur_ptr = cur + idx;
        uint8_t *prev_ptr = prev + idx;
        uint8_t *next_ptr = next + idx;
        uint8_t *prev2_ptr = prev2 + idx;
        uint8_t *next2_ptr = next2 + idx;
        uint8_t *dst_ptr = dst + idx;

        int c = cur_ptr[mrefs];
        int d = (prev2_ptr[0] + next2_ptr[0]) >> 1;
        int e = cur_ptr[prefs];
        int temporal_diff0 = ((prev2_ptr[0] - next2_ptr[0]) >= 0 ? (prev2_ptr[0] - next2_ptr[0]) : (-(prev2_ptr[0] - next2_ptr[0])));
        int temporal_diff1 = (((prev_ptr[mrefs] - c) >= 0 ? (prev_ptr[mrefs] - c) : (-(prev_ptr[mrefs] - c))) + ((prev_ptr[prefs] - e) >= 0 ? (prev_ptr[prefs] - e) : (-(prev_ptr[prefs] - e)))) >> 1;
        int temporal_diff2 = (((next_ptr[mrefs] - c) >= 0 ? (next_ptr[mrefs] - c) : (-(next_ptr[mrefs] - c))) + ((next_ptr[prefs] - e) >= 0 ? (next_ptr[prefs] - e) : (-(next_ptr[prefs] - e)))) >> 1;
        int diff = ((((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) > (temporal_diff2) ? (((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) : (temporal_diff2));
        int spatial_pred = (c + e) >> 1;

        if (0) {
            int spatial_score = ((cur_ptr[mrefs - 1] - cur_ptr[prefs - 1]) >= 0 ? (cur_ptr[mrefs - 1] - cur_ptr[prefs - 1]) : (-(cur_ptr[mrefs - 1] - cur_ptr[prefs - 1]))) + ((c - e) >= 0 ? (c - e) : (-(c - e))) + ((cur_ptr[mrefs + 1] - cur_ptr[prefs + 1]) >= 0 ? (cur_ptr[mrefs + 1] - cur_ptr[prefs + 1]) : (-(cur_ptr[mrefs + 1] - cur_ptr[prefs + 1]))) - 1;
            {
                int score = ((cur_ptr[mrefs - 1 + (-1)] - cur_ptr[prefs - 1 - (-1)]) >= 0 ? (cur_ptr[mrefs - 1 + (-1)] - cur_ptr[prefs - 1 - (-1)]) : (-(cur_ptr[mrefs - 1 + (-1)] - cur_ptr[prefs - 1 - (-1)]))) + ((cur_ptr[mrefs + (-1)] - cur_ptr[prefs - (-1)]) >= 0 ? (cur_ptr[mrefs + (-1)] - cur_ptr[prefs - (-1)]) : (-(cur_ptr[mrefs + (-1)] - cur_ptr[prefs - (-1)]))) + ((cur_ptr[mrefs + 1 + (-1)] - cur_ptr[prefs + 1 - (-1)]) >= 0 ? (cur_ptr[mrefs + 1 + (-1)] - cur_ptr[prefs + 1 - (-1)]) : (-(cur_ptr[mrefs + 1 + (-1)] - cur_ptr[prefs + 1 - (-1)])));
                if (score < spatial_score) {
                    spatial_score = score;
                    spatial_pred = (cur_ptr[mrefs + (-1)] + cur_ptr[prefs - (-1)]) >> 1;
                    {
                        int score = ((cur_ptr[mrefs - 1 + (-2)] - cur_ptr[prefs - 1 - (-2)]) >= 0 ? (cur_ptr[mrefs - 1 + (-2)] - cur_ptr[prefs - 1 - (-2)]) : (-(cur_ptr[mrefs - 1 + (-2)] - cur_ptr[prefs - 1 - (-2)]))) + ((cur_ptr[mrefs + (-2)] - cur_ptr[prefs - (-2)]) >= 0 ? (cur_ptr[mrefs + (-2)] - cur_ptr[prefs - (-2)]) : (-(cur_ptr[mrefs + (-2)] - cur_ptr[prefs - (-2)]))) + ((cur_ptr[mrefs + 1 + (-2)] - cur_ptr[prefs + 1 - (-2)]) >= 0 ? (cur_ptr[mrefs + 1 + (-2)] - cur_ptr[prefs + 1 - (-2)]) : (-(cur_ptr[mrefs + 1 + (-2)] - cur_ptr[prefs + 1 - (-2)])));
                        if (score < spatial_score) {
                            spatial_score = score;
                            spatial_pred = (cur_ptr[mrefs + (-2)] + cur_ptr[prefs - (-2)]) >> 1;
                        }
                    }
                }
            }
            {
                int score = ((cur_ptr[mrefs - 1 + (1)] - cur_ptr[prefs - 1 - (1)]) >= 0 ? (cur_ptr[mrefs - 1 + (1)] - cur_ptr[prefs - 1 - (1)]) : (-(cur_ptr[mrefs - 1 + (1)] - cur_ptr[prefs - 1 - (1)]))) + ((cur_ptr[mrefs + (1)] - cur_ptr[prefs - (1)]) >= 0 ? (cur_ptr[mrefs + (1)] - cur_ptr[prefs - (1)]) : (-(cur_ptr[mrefs + (1)] - cur_ptr[prefs - (1)]))) + ((cur_ptr[mrefs + 1 + (1)] - cur_ptr[prefs + 1 - (1)]) >= 0 ? (cur_ptr[mrefs + 1 + (1)] - cur_ptr[prefs + 1 - (1)]) : (-(cur_ptr[mrefs + 1 + (1)] - cur_ptr[prefs + 1 - (1)])));
                if (score < spatial_score) {
                    spatial_score = score;
                    spatial_pred = (cur_ptr[mrefs + (1)] + cur_ptr[prefs - (1)]) >> 1;
                    {
                        int score = ((cur_ptr[mrefs - 1 + (2)] - cur_ptr[prefs - 1 - (2)]) >= 0 ? (cur_ptr[mrefs - 1 + (2)] - cur_ptr[prefs - 1 - (2)]) : (-(cur_ptr[mrefs - 1 + (2)] - cur_ptr[prefs - 1 - (2)]))) + ((cur_ptr[mrefs + (2)] - cur_ptr[prefs - (2)]) >= 0 ? (cur_ptr[mrefs + (2)] - cur_ptr[prefs - (2)]) : (-(cur_ptr[mrefs + (2)] - cur_ptr[prefs - (2)]))) + ((cur_ptr[mrefs + 1 + (2)] - cur_ptr[prefs + 1 - (2)]) >= 0 ? (cur_ptr[mrefs + 1 + (2)] - cur_ptr[prefs + 1 - (2)]) : (-(cur_ptr[mrefs + 1 + (2)] - cur_ptr[prefs + 1 - (2)])));
                        if (score < spatial_score) {
                            spatial_score = score;
                            spatial_pred = (cur_ptr[mrefs + (2)] + cur_ptr[prefs - (2)]) >> 1;
                        }
                    }
                }
            }
        }
        if (!(mode & 2)) {
            int b = (prev2_ptr[2 * mrefs] + next2_ptr[2 * mrefs]) >> 1;
            int f = (prev2_ptr[2 * prefs] + next2_ptr[2 * prefs]) >> 1;
            int max = ((((d - e) > (d - c) ? (d - e) : (d - c))) > (((b - c) > (f - e) ? (f - e) : (b - c))) ? (((d - e) > (d - c) ? (d - e) : (d - c))) : (((b - c) > (f - e) ? (f - e) : (b - c))));
            int min = ((((d - e) > (d - c) ? (d - c) : (d - e))) > (((b - c) > (f - e) ? (b - c) : (f - e))) ? (((b - c) > (f - e) ? (b - c) : (f - e))) : (((d - e) > (d - c) ? (d - c) : (d - e))));
            diff = ((((diff) > (min) ? (diff) : (min))) > (-max) ? (((diff) > (min) ? (diff) : (min))) : (-max));
        }
        if (spatial_pred > d + diff)
            spatial_pred = d + diff;
        else if (spatial_pred < d - diff)
            spatial_pred = d - diff;
        dst_ptr[0] = spatial_pred;
    }
}
}
