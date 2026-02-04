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
// Use reversed linear index traversal with consecutive memory access pattern
int total_elements = width * height;
float *base = dst;
for (int y = height - 2; y >= 0; y--) {
    // Start from the last element in row y
    for (int x = width - 1; x >= 0; x--) {
        int curr = y * width + x;
        int next_row = curr + width; // (y+1)*width + x
        // Access current and next row elements directly
        if (x == width - 1) {
            g = q * base[curr] + c * base[curr];
        }
        base[curr] = b0 * base[curr] + b1 * base[next_row] + g;
        g = q * base[curr] + c * base[next_row];
    }
}
}
