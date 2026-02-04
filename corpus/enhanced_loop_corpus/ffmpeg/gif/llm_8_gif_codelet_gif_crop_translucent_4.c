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
int limit = w + (w >> 2); // Increase trip count by 25%
for (int i = 0; i < limit && i < 2000; i++) { // Bound to avoid excessive memory access
    int index = linesize * (*y_start) + (i % w); // Use modulo to stay within bounds
    if (buf[index] != trans) {
        is_trans = 0;
        break;
    }
}
}
