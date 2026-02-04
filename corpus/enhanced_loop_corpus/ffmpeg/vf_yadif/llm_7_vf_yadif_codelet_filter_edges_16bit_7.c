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
for (x = offset; x < w; x += 2) {
    int c0 = cur[0];
    int d0 = (prev2[0] + next2[0]) >> 1;
    int e0 = cur[prefs];
    int temporal_diff0_0 = ((prev2[0] - next2[0]) >= 0 ? (prev2[0] - next2[0]) : (-(prev2[0] - next2[0])));
    int temporal_diff1_0 = (((prev[0] - c0) >= 0 ? (prev[0] - c0) : (-(prev[0] - c0))) + ((prev[prefs] - e0) >= 0 ? (prev[prefs] - e0) : (-(prev[prefs] - e0)))) >> 1;
    int temporal_diff2_0 = (((next[0] - c0) >= 0 ? (next[0] - c0) : (-(next[0] - c0))) + ((next[prefs] - e0) >= 0 ? (next[prefs] - e0) : (-(next[prefs] - e0)))) >> 1;
    int diff0 = ((((temporal_diff0_0 >> 1) > (temporal_diff1_0) ? (temporal_diff0_0 >> 1) : (temporal_diff1_0))) > (temporal_diff2_0) ? (((temporal_diff0_0 >> 1) > (temporal_diff1_0) ? (temporal_diff0_0 >> 1) : (temporal_diff1_0))) : (temporal_diff2_0));
    int spatial_pred0 = (c0 + e0) >> 1;

    int c1 = cur[1];
    int d1 = (prev2[1] + next2[1]) >> 1;
    int e1 = cur[prefs + 1];
    int temporal_diff0_1 = ((prev2[1] - next2[1]) >= 0 ? (prev2[1] - next2[1]) : (-(prev2[1] - next2[1])));
    int temporal_diff1_1 = (((prev[1] - c1) >= 0 ? (prev[1] - c1) : (-(prev[1] - c1))) + ((prev[prefs + 1] - e1) >= 0 ? (prev[prefs + 1] - e1) : (-(prev[prefs + 1] - e1)))) >> 1;
    int temporal_diff2_1 = (((next[1] - c1) >= 0 ? (next[1] - c1) : (-(next[1] - c1))) + ((next[prefs + 1] - e1) >= 0 ? (next[prefs + 1] - e1) : (-(next[prefs + 1] - e1)))) >> 1;
    int diff1 = ((((temporal_diff0_1 >> 1) > (temporal_diff1_1) ? (temporal_diff0_1 >> 1) : (temporal_diff1_1))) > (temporal_diff2_1) ? (((temporal_diff0_1 >> 1) > (temporal_diff1_1) ? (temporal_diff0_1 >> 1) : (temporal_diff1_1))) : (temporal_diff2_1));
    int spatial_pred1 = (c1 + e1) >> 1;

    if (!(mode & 2)) {
        int b0 = (prev2[2 * 0] + next2[2 * 0]) >> 1;
        int f0 = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
        int max0 = ((((d0 - e0) > (d0 - c0) ? (d0 - e0) : (d0 - c0))) > (((b0 - c0) > (f0 - e0) ? (f0 - e0) : (b0 - c0))) ? (((d0 - e0) > (d0 - c0) ? (d0 - e0) : (d0 - c0))) : (((b0 - c0) > (f0 - e0) ? (f0 - e0) : (b0 - c0))));
        int min0 = ((((d0 - e0) > (d0 - c0) ? (d0 - c0) : (d0 - e0))) > (((b0 - c0) > (f0 - e0) ? (b0 - c0) : (f0 - e0))) ? (((b0 - c0) > (f0 - e0) ? (b0 - c0) : (f0 - e0))) : (((d0 - e0) > (d0 - c0) ? (d0 - c0) : (d0 - e0))));
        diff0 = ((((diff0) > (min0) ? (diff0) : (min0))) > (-max0) ? (((diff0) > (min0) ? (diff0) : (min0))) : (-max0));

        int b1 = (prev2[2 * 1] + next2[2 * 1]) >> 1;
        int f1 = (prev2[2 * (prefs + 1)] + next2[2 * (prefs + 1)]) >> 1;
        int max1 = ((((d1 - e1) > (d1 - c1) ? (d1 - e1) : (d1 - c1))) > (((b1 - c1) > (f1 - e1) ? (f1 - e1) : (b1 - c1))) ? (((d1 - e1) > (d1 - c1) ? (d1 - e1) : (d1 - c1))) : (((b1 - c1) > (f1 - e1) ? (f1 - e1) : (b1 - c1))));
        int min1 = ((((d1 - e1) > (d1 - c1) ? (d1 - c1) : (d1 - e1))) > (((b1 - c1) > (f1 - e1) ? (b1 - c1) : (f1 - e1))) ? (((b1 - c1) > (f1 - e1) ? (b1 - c1) : (f1 - e1))) : (((d1 - e1) > (d1 - c1) ? (d1 - c1) : (d1 - e1))));
        diff1 = ((((diff1) > (min1) ? (diff1) : (min1))) > (-max1) ? (((diff1) > (min1) ? (diff1) : (min1))) : (-max1));
    }

    if (spatial_pred0 > d0 + diff0)
        spatial_pred0 = d0 + diff0;
    else if (spatial_pred0 < d0 - diff0)
        spatial_pred0 = d0 - diff0;

    if (spatial_pred1 > d1 + diff1)
        spatial_pred1 = d1 + diff1;
    else if (spatial_pred1 < d1 - diff1)
        spatial_pred1 = d1 - diff1;

    dst[0] = spatial_pred0;
    dst[1] = spatial_pred1;

    dst += 2;
    cur += 2;
    prev += 2;
    next += 2;
    prev2 += 2;
    next2 += 2;
}
}
