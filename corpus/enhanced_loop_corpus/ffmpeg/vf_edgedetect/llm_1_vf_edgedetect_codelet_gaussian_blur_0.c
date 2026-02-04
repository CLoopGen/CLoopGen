#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 2; j < h - 2; j++) {
    dst[0] = src[0];
    if (w > 1)
        dst[1] = src[1];
    for (i = 2; i < w - 2; i++) {
        int sum = 0;
        for (int dy = -2; dy <= 2; dy++) {
            int weight_y = (dy == -2 || dy == 2) ? 2 : (dy == -1 || dy == 1) ? 4 : 5;
            for (int dx = -2; dx <= 2; dx++) {
                int weight_x = (dx == -2 || dx == 2) ? 2 : (dx == -1 || dx == 1) ? 4 : 5;
                int weight = weight_y * weight_x;
                if (dy == 0 && dx == 0) weight = 15;
                else if ((dy == -1 || dy == 1) && (dx == 0)) weight = 12;
                else if ((dy == 0) && (dx == -1 || dx == 1)) weight = 12;
                else if ((dy == -2 || dy == 2) && (dx == 0)) weight = 5;
                else if ((dy == 0) && (dx == -2 || dx == 2)) weight = 5;
                else if ((abs(dy) == 1) && (abs(dx) == 1)) weight = 9;
                else if ((abs(dy) == 2) && (abs(dx) == 1)) weight = 4;
                else if ((abs(dy) == 1) && (abs(dx) == 2)) weight = 4;
                else if ((abs(dy) == 2) && (abs(dx) == 2)) weight = 2;
                sum += src[dy * src_linesize + i + dx] * weight;
            }
        }
        dst[i] = sum / 159;
    }
    if (w > 2)
        dst[i] = src[i];
    if (w > 3)
        dst[i + 1] = src[i + 1];
    dst += dst_linesize;
    src += src_linesize;
}
}
