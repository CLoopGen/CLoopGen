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
    for (int inner = 0; inner < 1; inner++) { // Artificial nesting to increase depth without changing logic
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
            for (int offset = -2; offset <= 2; offset++) {
                if (offset == 0) continue;
                int score = ((cur[mrefs - 1 + offset] - cur[prefs - 1 - offset]) >= 0 ? (cur[mrefs - 1 + offset] - cur[prefs - 1 - offset]) : (-(cur[mrefs - 1 + offset] - cur[prefs - 1 - offset]))) +
                            ((cur[mrefs + offset] - cur[prefs - offset]) >= 0 ? (cur[mrefs + offset] - cur[prefs - offset]) : (-(cur[mrefs + offset] - cur[prefs - offset]))) +
                            ((cur[mrefs + 1 + offset] - cur[prefs + 1 - offset]) >= 0 ? (cur[mrefs + 1 + offset] - cur[prefs + 1 - offset]) : (-(cur[mrefs + 1 + offset] - cur[prefs + 1 - offset])));
                if (score < spatial_score) {
                    spatial_score = score;
                    spatial_pred = (cur[mrefs + offset] + cur[prefs - offset]) >> 1;
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
    }
    dst++;
    cur++;
    prev++;
    next++;
    prev2++;
    next2++;
}

}
