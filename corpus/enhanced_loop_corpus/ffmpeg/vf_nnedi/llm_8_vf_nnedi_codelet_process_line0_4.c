#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *tempu;
extern int width;
extern  int src_pitch;
extern uint8_t *dstp;
extern  uint8_t *src3p;
extern int minimum;
extern int maximum;
extern int count;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < width; x += 2) {
    if (tempu[x]) {
        int tmp1 = 19 * (src3p[x + src_pitch * 2] + src3p[x + src_pitch * 4]) - 3 * (src3p[x] + src3p[x + src_pitch * 6]);
        int tmp2 = 19 * (src3p[x + src_pitch * 2 + 1] + src3p[x + src_pitch * 4 + 1]) - 3 * (src3p[x + 1] + src3p[x + src_pitch * 6 + 1]);
        tmp1 /= 32;
        tmp2 /= 32;
        dstp[x] = ((((tmp1) > (maximum) ? (maximum) : (tmp1))) > (minimum) ? (((tmp1) > (maximum) ? (maximum) : (tmp1))) : (minimum));
        if (x + 1 < width) {
            dstp[x + 1] = ((((tmp2) > (maximum) ? (maximum) : (tmp2))) > (minimum) ? (((tmp2) > (maximum) ? (maximum) : (tmp2))) : (minimum));
        }
    } else {
        dstp[x] = 255;
        count++;
        if (x + 1 < width && !tempu[x + 1]) {
            dstp[x + 1] = 255;
            count++;
        }
    }
}
}
