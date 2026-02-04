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
const int stride = 4;
for (x = offset; x < w - 3; x += stride) {
    uint8_t *cur_offsets[] = {cur, cur + 1, cur + 2, cur + 3};
    uint8_t *prev_offsets[] = {prev, prev + 1, prev + 2, prev + 3};
    uint8_t *next_offsets[] = {next, next + 1, next + 2, next + 3};
    uint8_t *prev2_offsets[] = {prev2, prev2 + 1, prev2 + 2, prev2 + 3};
    uint8_t *next2_offsets[] = {next2, next2 + 1, next2 + 2, next2 + 3};

    for (int i = 0; i < stride && (x + i) < w - 3; i++) {
        int c = cur_offsets[i][mrefs];
        int d = (prev2_offsets[i][0] + next2_offsets[i][0]) >> 1;
        int e = cur_offsets[i][prefs];
        int temporal_diff0 = ((prev2_offsets[i][0] - next2_offsets[i][0]) >= 0 ? (prev2_offsets[i][0] - next2_offsets[i][0]) : (-(prev2_offsets[i][0] - next2_offsets[i][0])));
        int temporal_diff1 = (((prev_offsets[i][mrefs] - c) >= 0 ? (prev_offsets[i][mrefs] - c) : (-(prev_offsets[i][mrefs] - c))) + 
                              ((prev_offsets[i][prefs] - e) >= 0 ? (prev_offsets[i][prefs] - e) : (-(prev_offsets[i][prefs] - e)))) >> 1;
        int temporal_diff2 = (((next_offsets[i][mrefs] - c) >= 0 ? (next_offsets[i][mrefs] - c) : (-(next_offsets[i][mrefs] - c))) + 
                              ((next_offsets[i][prefs] - e) >= 0 ? (next_offsets[i][prefs] - e) : (-(next_offsets[i][prefs] - e)))) >> 1;
        int diff = ((((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) > (temporal_diff2) ? (((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) : (temporal_diff2));
        int spatial_pred = (c + e) >> 1;

        if (1) {
            int spatial_score = ((cur_offsets[i][mrefs - 1] - cur_offsets[i][prefs - 1]) >= 0 ? (cur_offsets[i][mrefs - 1] - cur_offsets[i][prefs - 1]) : (-(cur_offsets[i][mrefs - 1] - cur_offsets[i][prefs - 1]))) +
                               ((c - e) >= 0 ? (c - e) : (-(c - e))) +
                               ((cur_offsets[i][mrefs + 1] - cur_offsets[i][prefs + 1]) >= 0 ? (cur_offsets[i][mrefs + 1] - cur_offsets[i][prefs + 1]) : (-(cur_offsets[i][mrefs + 1] - cur_offsets[i][prefs + 1]))) - 1;

            for (int off = -2; off <= 2; off++) {
                if (off == 0) continue;
                int score = ((cur_offsets[i][mrefs - 1 + off] - cur_offsets[i][prefs - 1 - off]) >= 0 ? (cur_offsets[i][mrefs - 1 + off] - cur_offsets[i][prefs - 1 - off]) : (-(cur_offsets[i][mrefs - 1 + off] - cur_offsets[i][prefs - 1 - off]))) +
                           ((cur_offsets[i][mrefs + off] - cur_offsets[i][prefs - off]) >= 0 ? (cur_offsets[i][mrefs + off] - cur_offsets[i][prefs - off]) : (-(cur_offsets[i][mrefs + off] - cur_offsets[i][prefs - off]))) +
                           ((cur_offsets[i][mrefs + 1 + off] - cur_offsets[i][prefs + 1 - off]) >= 0 ? (cur_offsets[i][mrefs + 1 + off] - cur_offsets[i][prefs + 1 - off]) : (-(cur_offsets[i][mrefs + 1 + off] - cur_offsets[i][prefs + 1 - off])));
                if (score < spatial_score) {
                    spatial_score = score;
                    spatial_pred = (cur_offsets[i][mrefs + off] + cur_offsets[i][prefs - off]) >> 1;
                }
            }
        }

        if (!(mode & 2)) {
            int b = (prev2_offsets[i][2 * mrefs] + next2_offsets[i][2 * mrefs]) >> 1;
            int f = (prev2_offsets[i][2 * prefs] + next2_offsets[i][2 * prefs]) >> 1;
            int max = ((((d - e) > (d - c) ? (d - e) : (d - c))) > (((b - c) > (f - e) ? (f - e) : (b - c))) ? (((d - e) > (d - c) ? (d - e) : (d - c))) : (((b - c) > (f - e) ? (f - e) : (b - c))));
            int min = ((((d - e) > (d - c) ? (d - c) : (d - e))) > (((b - c) > (f - e) ? (b - c) : (f - e))) ? (((b - c) > (f - e) ? (b - c) : (f - e))) : (((d - e) > (d - c) ? (d - c) : (d - e))));
            diff = ((((diff) > (min) ? (diff) : (min))) > (-max) ? (((diff) > (min) ? (diff) : (min))) : (-max));
        }

        if (spatial_pred > d + diff)
            spatial_pred = d + diff;
        else if (spatial_pred < d - diff)
            spatial_pred = d - diff;

        dst[i] = spatial_pred;
    }

    dst += stride;
    cur += stride;
    prev += stride;
    next += stride;
    prev2 += stride;
    next2 += stride;
}
}
