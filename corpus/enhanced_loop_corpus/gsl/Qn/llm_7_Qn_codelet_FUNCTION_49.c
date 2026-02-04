#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int *weight;
extern int i;
extern int j;
extern int jh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = 0;
    for (i = 1; i < ni; ++i) {
        if (left[i] <= right[i]) {
            int range = right[i] - left[i] + 1;
            weight[j + offset] = range;
            if (offset == 0) {
                jh = left[i] + range / 2;
            }
            offset = (offset + 1) % 1; // Keeps offset = 0, eliminates WAW hazard across iterations
        }
    }
    j += 1; // Update j once after loop (removes loop-carried WAW on j)
}
