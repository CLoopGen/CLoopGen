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
for (x = 0; x < ((6) > (w) ? (w) : (6)); x += 2) {
    for (int offset = 0; offset < 2; ++offset) {
        if (x + offset >= w) break;

        int c = cur[mrefs];
        int d = (prev2[0] + next2[0]) >> 1;
        int e = cur[prefs];
        int tdiff0 = abs(prev2[0] - next2[0]);
        int tdiff1 = (abs(prev[mrefs] - c) + abs(prev[prefs] - e)) >> 1;
        int tdiff2 = (abs(next[mrefs] - c) + abs(next[prefs] - e)) >> 1;
        int diff = tdiff0 >> 1;
        if (tdiff1 > diff) diff = tdiff1;
        if (tdiff2 > diff) diff = tdiff2;

        int spatial_pred = (c + e) >> 1;

        if (!(mode & 2)) {
            int b = (prev2[2 * mrefs] + next2[2 * mrefs]) >> 1;
            int f = (prev2[2 * prefs] + next2[2 * prefs]) >> 1;
            int max = (d - e) > (d - c) ? (d - e) : (d - c);
            if ((b - c) > (f - e)) max = (max > (b - c)) ? max : (b - c);
            else max = (max > (f - e)) ? max : (f - e);

            int min = (d - e) < (d - c) ? (d - e) : (d - c);
            int min2 = (b - c) < (f - e) ? (b - c) : (f - e);
            min = (min < min2) ? min : min2;

            diff = (diff > min) ? diff : min;
            diff = (diff > -max) ? diff : -max;
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
    }
}
}
