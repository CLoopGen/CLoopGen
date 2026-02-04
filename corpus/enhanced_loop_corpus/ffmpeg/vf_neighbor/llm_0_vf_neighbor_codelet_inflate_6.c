#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *p1;
extern int width;
extern int threshold;
extern  uint8_t *coordinates[];
extern int x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int x_inner;
    for (x = 0; x < width; x++) {
        int sum = 0;
        int limit = (p1[x] + threshold) > 255 ? 255 : p1[x] + threshold;
        for (x_inner = 0; x_inner < 8; x_inner++) {
            sum += *(coordinates[x_inner] + x);
        }
        dst[x] = (sum / 8) > p1[x] ? (sum / 8) : p1[x];
        if (dst[x] > limit) {
            dst[x] = limit;
        }
    }
}
