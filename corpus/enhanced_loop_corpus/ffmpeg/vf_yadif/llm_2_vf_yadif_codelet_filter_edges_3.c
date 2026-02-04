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
    int c = cur[0];
    int d = (prev2[-x] + next2[x]) >> 1;
    int e = cur[1];
    int temporal_diff0 = ((prev2[-x] - next2[x]) >= 0 ? (prev2[-x] - next2[x]) : (-(prev2[-x] - next2[x])));
    int temporal_diff1 = (((prev[0] - c) >= 0 ? (prev[0] - c) : (-(prev[0] - c))) + ((prev[1] - e) >= 0 ? (prev[1] - e) : (-(prev[1] - e)))) >> 1;
    int temporal_diff2 = (((next[0] - c) >= 0 ? (next[0] - c) : (-(next[0] - c))) + ((next[1] - e) >= 0 ? (next[1] - e) : (-(next[1] - e)))) >> 1;
    int diff = ((((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) > (temporal_diff2) ? (((temporal_diff0 >> 1) > (temporal_diff1) ? (temporal_diff0 >> 1) : (temporal_diff1))) : (temporal_diff2));
    int spatial_pred = (c + e) >> 1;
    if (0) {
        int spatial_score = ((cur[-1] - cur[0]) >= 0 ? (cur[-1] - cur[0]) : (-(cur[-1] - cur[0]))) + ((c - e) >= 0 ? (c - e) : (-(c - e))) + ((cur[1] - cur[2]) >= 0 ? (cur[1] - cur[2]) : (-(cur[1] - cur[2]))) - 1;
        {
            int score = ((cur[-2] - cur[-1]) >= 0 ? (cur[-2] - cur[-1]) : (-(cur[-2] - cur[-1]))) + ((cur[-1] - cur[0]) >= 0 ? (cur[-1] - cur[0]) : (-(cur[-1] - cur[0]))) + ((cur[0] - cur[1]) >= 0 ? (cur[0] - cur[1]) : (-(cur[0] - cur[1])));
            if (score < spatial_score) {
                spatial_score = score;
                spatial_pred = (cur[-1] + cur[0]) >> 1;
                {
                    int score = ((cur[-3] - cur[-2]) >= 0 ? (cur[-3] - cur[-2]) : (-(cur[-3] - cur[-2]))) + ((cur[-2] - cur[-1]) >= 0 ? (cur[-2] - cur[-1]) : (-(cur[-2] - cur[-1]))) + ((cur[-1] - cur[0]) >= 0 ? (cur[-1] - cur[0]) : (-(cur[-1] - cur[0])));
                    if (score < spatial_score) {
                        spatial_score = score;
                        spatial_pred = (cur[-2] + cur[-1]) >> 1;
                    }
                }
            }
        }
        {
            int score = ((cur[0] - cur[1]) >= 0 ? (cur[0] - cur[1]) : (-(cur[0] - cur[1]))) + ((cur[1] - cur[2]) >= 0 ? (cur[1] - cur[2]) : (-(cur[1] - cur[2]))) + ((cur[2] - cur[3]) >= 0 ? (cur[2] - cur[3]) : (-(cur[2] - cur[3])));
            if (score < spatial_score) {
                spatial_score = score;
                spatial_pred = (cur[1] + cur[2]) >> 1;
                {
                    int score = ((cur[1] - cur[2]) >= 0 ? (cur[1] - cur[2]) : (-(cur[1] - cur[2]))) + ((cur[2] - cur[3]) >= 0 ? (cur[2] - cur[3]) : (-(cur[2] - cur[3]))) + ((cur[3] - cur[4]) >= 0 ? (cur[3] - cur[4]) : (-(cur[3] - cur[4])));
                    if (score < spatial_score) {
                        spatial_score = score;
                        spatial_pred = (cur[2] + cur[3]) >> 1;
                    }
                }
            }
        }
    }
    if (!(mode & 2)) {
        int b = (prev2[-2*x] + next2[2*x]) >> 1;
        int f = (prev2[2] + next2[2]) >> 1;
        int max = ((((d - e) > (d - c) ? (d - e) : (d - c))) > (((b - c) > (f - e) ? (f - e) : (b - c))) ? (((d - e) > (d - c) ? (d - e) : (d - c))) : (((b - c) > (f - e) ? (f - e) : (b - c))));
        int min = ((((d - e) > (d - c) ? (d - c) : (d - e))) > (((b - c) > (f - e) ? (b - c) : (f - e))) ? (((b - c) > (f - e) ? (b - c) : (f - e))) : (((d - e) > (d - c) ? (d - c) : (d - e))));
        diff = ((((diff) > (min) ? (diff) : (min))) > (-max) ? (((diff) > (min) ? (diff) : (min))) : (-max));
    }
    if (spatial_pred > d + diff)
        spatial_pred = d + diff;
    else if (spatial_pred < d - diff)
        spatial_pred = d - diff;
    dst[0] = spatial_pred;
    dst += 1;
    cur += 1;
    prev += 1;
    next += 1;
    prev2 += 1;
    next2 += 1;
}
}
