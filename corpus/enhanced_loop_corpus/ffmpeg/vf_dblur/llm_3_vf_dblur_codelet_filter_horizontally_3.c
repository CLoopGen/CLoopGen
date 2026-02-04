#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern  float b0;
extern  float b1;
extern  float q;
extern  float c;
extern float *dst;
extern float g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int y = height - 2; y >= 0; y--) {
    int *row_offsets = (int*)malloc(width * sizeof(int));
    for (int x = 0; x < width; x++) {
        row_offsets[x] = y * width + x;
    }
    g = q * dst[row_offsets[0]] + c * dst[row_offsets[0]];
    for (int x = 0; x < width; x++) {
        int curr = row_offsets[x];
        int next = curr + width;
        dst[curr] = b0 * dst[curr] + b1 * dst[next] + g;
        g = q * dst[curr] + c * dst[next];
    }
    free(row_offsets);
}
}
