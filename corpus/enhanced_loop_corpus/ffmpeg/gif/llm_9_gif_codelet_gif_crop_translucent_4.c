#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int *y_start;
extern int trans;
extern  int w;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
is_trans = 1; // Assume true initially
#pragma unroll 4
for (int i = 0; i < w; i += 2) {
    int idx1 = linesize * (*y_start) + i;
    int idx2 = idx1 + 1;
    int val1 = (i < w) ? buf[idx1] : trans;
    int val2 = (i + 1 < w) ? buf[idx2] : trans;
    if (val1 != trans || val2 != trans) {
        is_trans = 0;
        break;
    }
}
// Handle odd-sized w
if (w % 2 == 1) {
    if (buf[linesize * (*y_start) + w - 1] != trans) {
        is_trans = 0;
    }
}
}
