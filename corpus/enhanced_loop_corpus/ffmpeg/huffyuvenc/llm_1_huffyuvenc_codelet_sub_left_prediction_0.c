#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int left;
extern int i;
extern int min_width;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (min_width > 0) {
        i = 0;
        for (int step = 1; step <= min_width; step *= 2) {
            if (i < min_width) {
                const int temp = src[i];
                dst[i] = temp - left;
                left = temp;
                i++;
            }
        }
    }
}
