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
if (w - 3 > offset) {
    for (x = offset; x < w - 3; ) {
        int c = cur[mrefs];
        int d = (prev2[0] + next2[0]) >> 1;
        int e = cur[prefs];
        int temporal_diff0 = ((prev2[0] - next2[0]) >= 0 ? (prev2[0] - next2[0]) : (-(prev2[0] - next2[0])));
        int temporal_diff1 = (((prev[mrefs] - c) >= 0 ? (prev[mrefs] - c) : (-(prev[mrefs] - c))) + ((prev[prefs] - e) >= 0 ? (prev[prefs] - e) : (-(prev[prefs] - e)))) >> 1;
        int temporal_diff2 = (((next[mrefs] - c) >= 0 ? (next[mrefs] - c) : (-(next[mrefs] - c))) + ((next[prefs] - e) >= 0 ? (next[prefs] - e) : (-(next[prefs] - e)))) >> 1;
        int diff = ((((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) > (temporal_diff2) ? (((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) : (temporal_diff2));
        int spatial_pred = (c + e) >> 1;
        if (1) {
            int spatial_score = ((cur[mrefs - 1] - cur[prefs - 1]) >= 0 ? (cur[mrefs - 1] - cur[prefs - 1]) : (-(cur[mrefs - 1] - cur[prefs - 1]))) + ((c - e) >= 0 ? (c - e) : (-(c - e))) + ((cur[mrefs + 1] - cur[prefs + 1]) >= 0 ? (cur[mrefs + 1] - cur[prefs + 1]) : (-(cur[mrefs + 1] - cur[prefs + 1]))) - 1;
            {
                int score = ((cur[mrefs - 1 + (-1)] - cur[prefs - 1 - (-1)]) >= 0 ? (cur[mrefs - 1 + (-1)] - cur[prefs - 1 - (-1)]) : (-(cur[mrefs - 1 + (-1)] - cur[prefs - 1 - (-1)]))) + ((cur[mrefs + (-1)] - cur[prefs - (-1)]) >= 0 ? (cur[mrefs + (-1)] - cur[prefs - (-1)]) : (-(cur[mrefs + (-1)] - cur[prefs - (-1)]))) + ((cur[mrefs + 1 + (-1)] - cur[prefs + 1 - (-1)]) >= 0 ? (cur[mrefs + 1 + (-1)] - cur[prefs + 1 - (-1)]) : (-(cur[mrefs + 1 + (-1)] - cur[prefs + 1 - (-1)])));
                if (score < spatial_score) {
                    spatial_score = score;
                    spatial_pred = (cur[mrefs + (-1)] + cur[prefs - (-1)]) >> 1;
                    {
                        int score = ((cur[mrefs - 1 + (-2)] - cur[prefs - 1 - (-2)]) >= 0 ? (cur[mrefs - 1 + (-2)] - cur[prefs - 1 - (-2)]) : (-(cur[mrefs - 1 + (-2)] - cur[prefs - 1 - (-2)]))) + ((cur[mrefs + (-2)] - cur[prefs - (-2)]) >= 0 ? (cur[mrefs + (-2)] - cur[prefs - (-2)]) : (-(cur[mrefs + (-2)] - cur[prefs - (-2)]))) + ((cur[mrefs + 1 + (-2)] - cur[prefs + 1 - (-2)]) >= 0 ? (cur[mrefs + 1 + (-2)] - cur[prefs + 1 - (-2)]) : (-(cur[mrefs + 1 + (-2)] - cur[prefs + 1 - (-2)])));
                        if (score < spatial_score) {
                            spatial_score = score;
                            spatial_pred = (cur[mrefs + (-2)] + cur[prefs - (-2)]) >> 1;
                        }
                    }
                }
            }
            {
                int score = ((cur[mrefs - 1 + (1)] - cur[prefs - 1 - (1)]) >= 0 ? (cur[mrefs - 1 + (1)] - cur[prefs - 1 - (1)]) : (-(cur[mrefs - 1 + (1)] - cur[prefs - 1 - (1)]))) + ((cur[mrefs + (1)] - cur[prefs - (1)]) >= 0 ? (cur[mrefs + (1)] - cur[prefs - (1)]) : (-(cur[mrefs + (1)] - cur[prefs - (1)]))) + ((cur[mrefs + 1 + (1)] - cur[prefs + 1 - (1)]) >= 0 ? (cur[mrefs + 1 + (1)] - cur[prefs + 1 - (1)]) : (-(cur[mrefs + 1 + (1)] - cur[prefs + 1 - (1)])));
                if (score < spatial_score) {
                    spatial_score = score;
                    spatial_pred = (cur[mrefs + (1)] + cur[prefs - (1)]) >> 1;
                    {
                        int score = ((cur[mrefs - 1 + (2)] - cur[prefs - 1 - (2)]) >= 0 ? (cur[mrefs - 1 + (2)] - cur[prefs - 1 - (2)]) : (-(cur[mrefs - 1 + (2)] - cur[prefs - 1 - (2)]))) + ((cur[mrefs + (2)] - cur[prefs - (2)]) >= 0 ? (cur[mrefs + (2)] - cur[prefs - (2)]) : (-(cur[mrefs + (2)] - cur[prefs - (2)]))) + ((cur[mrefs + 1 + (2)] - cur[prefs + 1 - (2)]) >= 0 ? (cur[mrefs + 1 + (2)] - cur[prefs + 1 - (2)]) : (-(cur[mrefs + 1 + (2)] - cur[prefs + 1 - (2)])));
                        if (score < spatial_score) {
                            spatial_score = score;
                            spatial_pred = (cur[mrefs + (2)] + cur[prefs - (2)]) >> 1;
                        }
                    }
                }
            }
        }
        if (!(mode & 2)) {
            int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
            int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
            int max = ((((d - e) > (d - c) ? (d - e) : (d - c))) > (((b - c) > (f - e) ? (f - e) : (b - c))) ? (((d - e) > (d - c) ? (d - e) : (d - c))) : (((b - c) > (f - e) ? (f - e) : (b - c))));
            int min = ((((d - e) > (d - c) ? (d - c) : (d - e))) > (((b - c) > (f - e) ? (b - c) : (f - e))) ? (((b - c) > (f - e) ? (b - c) : (f - e))) : (((d - e) > (d - c) ? (d - c) : (d - e))));
            diff = ((((diff) > (min) ? (diff) : (min))) > (-max) ? (((diff) > (min) ? (diff) : (min))) : (-max));
        }
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
        x++;
        if (x >= w - 3) break;
        for (int inner = 0; inner < 1; inner++) {
            int c_inner = cur[mrefs];
            int d_inner = (prev2[0] + next2[0]) >> 1;
            int e_inner = cur[prefs];
            int temporal_diff0_inner = ((prev2[0] - next2[0]) >= 0 ? (prev2[0] - next2[0]) : (-(prev2[0] - next2[0])));
            int temporal_diff1_inner = (((prev[mrefs] - c_inner) >= 0 ? (prev[mrefs] - c_inner) : (-(prev[mrefs] - c_inner))) + ((prev[prefs] - e_inner) >= 0 ? (prev[prefs] - e_inner) : (-(prev[prefs] - e_inner)))) >> 1;
            int temporal_diff2_inner = (((next[mrefs] - c_inner) >= 0 ? (next[mrefs] - c_inner) : (-(next[mrefs] - c_inner))) + ((next[prefs] - e_inner) >= 0 ? (next[prefs] - e_inner) : (-(next[prefs] - e_inner)))) >> 1;
            int diff_inner = ((((temporal_diff0_inner >> 1) > (temporal_diff1_inner) ? (temporal_diff0_inner >> 1) : (temporal_diff1_inner))) > (temporal_diff2_inner) ? (((temporal_diff0_inner >> 1) > (temporal_diff1_inner) ? (temporal_diff0_inner >> 1) : (temporal_diff1_inner))) : (temporal_diff2_inner));
            int spatial_pred_inner = (c_inner + e_inner) >> 1;
            if (1) {
                int spatial_score_inner = ((cur[mrefs - 1] - cur[prefs - 1]) >= 0 ? (cur[mrefs - 1] - cur[prefs - 1]) : (-(cur[mrefs - 1] - cur[prefs - 1]))) + ((c_inner - e_inner) >= 0 ? (c_inner - e_inner) : (-(c_inner - e_inner))) + ((cur[mrefs + 1] - cur[prefs + 1]) >= 0 ? (cur[mrefs + 1] - cur[prefs + 1]) : (-(cur[mrefs + 1] - cur[prefs + 1]))) - 1;
                {
                    int score_inner = ((cur[mrefs - 1 + (-1)] - cur[prefs - 1 - (-1)]) >= 0 ? (cur[mrefs - 1 + (-1)] - cur[prefs - 1 - (-1)]) : (-(cur[mrefs - 1 + (-1)] - cur[prefs - 1 - (-1)]))) + ((cur[mrefs + (-1)] - cur[prefs - (-1)]) >= 0 ? (cur[mrefs + (-1)] - cur[prefs - (-1)]) : (-(cur[mrefs + (-1)] - cur[prefs - (-1)]))) + ((cur[mrefs + 1 + (-1)] - cur[prefs + 1 - (-1)]) >= 0 ? (cur[mrefs + 1 + (-1)] - cur[prefs + 1 - (-1)]) : (-(cur[mrefs + 1 + (-1)] - cur[prefs + 1 - (-1)])));
                    if (score_inner < spatial_score_inner) {
                        spatial_score_inner = score_inner;
                        spatial_pred_inner = (cur[mrefs + (-1)] + cur[prefs - (-1)]) >> 1;
                    }
                }
                {
                    int score_inner = ((cur[mrefs - 1 + (1)] - cur[prefs - 1 - (1)]) >= 0 ? (cur[mrefs - 1 + (1)] - cur[prefs - 1 - (1)]) : (-(cur[mrefs - 1 + (1)] - cur[prefs - 1 - (1)]))) + ((cur[mrefs + (1)] - cur[prefs - (1)]) >= 0 ? (cur[mrefs + (1)] - cur[prefs - (1)]) : (-(cur[mrefs + (1)] - cur[prefs - (1)]))) + ((cur[mrefs + 1 + (1)] - cur[prefs + 1 - (1)]) >= 0 ? (cur[mrefs + 1 + (1)] - cur[prefs + 1 - (1)]) : (-(cur[mrefs + 1 + (1)] - cur[prefs + 1 - (1)])));
                    if (score_inner < spatial_score_inner) {
                        spatial_score_inner = score_inner;
                        spatial_pred_inner = (cur[mrefs + (1)] + cur[prefs - (1)]) >> 1;
                    }
                }
            }
            if (!(mode & 2)) {
                int b_inner = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
                int f_inner = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
                int max_inner = ((((d_inner - e_inner) > (d_inner - c_inner) ? (d_inner - e_inner) : (d_inner - c_inner))) > (((b_inner - c_inner) > (f_inner - e_inner) ? (f_inner - e_inner) : (b_inner - c_inner))) ? (((d_inner - e_inner) > (d_inner - c_inner) ? (d_inner - e_inner) : (d_inner - c_inner))) : (((b_inner - c_inner) > (f_inner - e_inner) ? (f_inner - e_inner) : (b_inner - c_inner))));
                int min_inner = ((((d_inner - e_inner) > (d_inner - c_inner) ? (d_inner - c_inner) : (d_inner - e_inner))) > (((b_inner - c_inner) > (f_inner - e_inner) ? (b_inner - c_inner) : (f_inner - e_inner))) ? (((b_inner - c_inner) > (f_inner - e_inner) ? (b_inner - c_inner) : (f_inner - e_inner))) : (((d_inner - e_inner) > (d_inner - c_inner) ? (d_inner - c_inner) : (d_inner - e_inner))));
                diff_inner = ((((diff_inner) > (min_inner) ? (diff_inner) : (min_inner))) > (-max_inner) ? (((diff_inner) > (min_inner) ? (diff_inner) : (min_inner))) : (-max_inner));
            }
            if (spatial_pred_inner > d_inner + diff_inner)
                spatial_pred_inner = d_inner + diff_inner;
            else if (spatial_pred_inner < d_inner - diff_inner)
                spatial_pred_inner = d_inner - diff_inner;
            dst[0] = spatial_pred_inner;
            dst++;
            cur++;
            prev++;
            next++;
            prev2++;
            next2++;
            x++;
        }
    }
}
}
