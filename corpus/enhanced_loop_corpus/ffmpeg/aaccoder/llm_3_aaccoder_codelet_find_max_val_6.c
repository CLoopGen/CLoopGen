#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int group_len;
extern int swb_size;
extern  float *scaled;
extern float maxval;
extern int w2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access with Linear Indexing
    // Flatten the two-dimensional access into a single loop with consecutive
    // memory traversal to improve cache locality and enable better vectorization.
    int total_elements = group_len * swb_size;
    for (int idx = 0; idx < total_elements; idx++) {
        float val = scaled[idx]; // Now accessing memory consecutively
        maxval = (maxval > val) ? maxval : val;
    }
}
