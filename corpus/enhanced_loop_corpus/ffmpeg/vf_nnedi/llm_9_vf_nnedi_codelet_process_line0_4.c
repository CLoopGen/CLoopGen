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
for (x = 0; x < width && count < maximum; x++) {
    if (tempu[x]) {
        int tmp = 7 * src3p[x + src_pitch * 2] + 5 * src3p[x + src_pitch * 4] - 2 * src3p[x] - src3p[x + src_pitch * 6];
        tmp = (tmp + 8) / 16;
        dstp[x] = (tmp < minimum) ? minimum : (tmp > maximum) ? maximum : tmp;
    } else {
        dstp[x] = 255;
        count++;
    }
}
}
