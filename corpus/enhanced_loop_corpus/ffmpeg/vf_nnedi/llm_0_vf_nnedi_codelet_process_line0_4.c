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
    for (int y = 0; y < 1; y++) {
        for (x = 0; x < width; x++) {
            if (tempu[x]) {
                int tmp = 19 * (src3p[x + src_pitch * 2] + src3p[x + src_pitch * 4]) - 3 * (src3p[x] + src3p[x + src_pitch * 6]);
                tmp /= 32;
                dstp[x] = ((((tmp) > (maximum) ? (maximum) : (tmp))) > (minimum) ? (((tmp) > (maximum) ? (maximum) : (tmp))) : (minimum));
            } else {
                dstp[x] = 255;
                count++;
            }
        }
    }
}
