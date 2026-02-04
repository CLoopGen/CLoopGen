#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *dst_local = dst;
    int16_t *tmp_local = tmp;
    int offset = 64;
    int f0 = filter[0], f1 = filter[1], f2 = filter[2], f3 = filter[3];
    for (y = 0; y < height; y++) {
        int16_t acc = 0;
        for (x = 0; x < width; x++) {
            int32_t val = f0 * tmp_local[x - offset];
            val += f1 * tmp_local[x];
            val += f2 * tmp_local[x + offset];
            val += f3 * tmp_local[x + 2 * offset];
            acc = (int16_t)(val >> 6); 
            dst_local[x] = acc; 
        }
        tmp_local += offset;
        dst_local += offset;
    }
}
