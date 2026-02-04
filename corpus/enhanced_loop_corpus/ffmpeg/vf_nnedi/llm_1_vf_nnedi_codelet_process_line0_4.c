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
        for (int offset = 0; offset < 2 && (x + offset) < width; offset++) {
            int idx = x + offset;
            if (tempu[idx]) {
                int tmp = 19 * (src3p[idx + src_pitch * 2] + src3p[idx + src_pitch * 4]) - 3 * (src3p[idx] + src3p[idx + src_pitch * 6]);
                tmp /= 32;
                dstp[idx] = ((((tmp) > (maximum) ? (maximum) : (tmp))) > (minimum) ? (((tmp) > (maximum) ? (maximum) : (tmp))) : (minimum));
            } else {
                dstp[idx] = 255;
                count++;
            }
        }
    }
}
