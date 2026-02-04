#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *image;
extern int height;
extern int width;
extern int top;
extern int left;
extern int height_new;
extern int width_new;
extern int i;
extern int j;
extern float *result;
extern float temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < height_new; i++) {
        int dst_base = i * width_new;
        int src_base = (height - 1 - (i + top)) * width + left;
        for (j = 0; j < width_new; j++) {
            char pixel = image[src_base + j];
            float val = (float)pixel;
            if (val < 0) {
                result[dst_base + j] = val + 256;
            } else {
                result[dst_base + j] = val;
            }
        }
    }
}
