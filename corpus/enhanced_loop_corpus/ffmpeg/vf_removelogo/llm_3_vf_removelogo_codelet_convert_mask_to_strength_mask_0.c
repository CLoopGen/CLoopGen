#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int linesize;
extern int w;
extern int h;
extern int min_val;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Access (process array from end to beginning)
    int idx;
    int total_elements = h * linesize; // Assume linesize >= w, process full line padding if any
    for (idx = total_elements - 1; idx >= 0; idx--) {
        if ((idx % linesize) < w) { // Only process valid width columns
            data[idx] = data[idx] > min_val;
        }
    }
}
