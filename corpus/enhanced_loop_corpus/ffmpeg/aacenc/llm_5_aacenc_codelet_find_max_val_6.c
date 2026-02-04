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
maxval = scaled[0]; // Initialize maxval to first element to ensure valid comparison
for (w2 = 0; w2 < group_len; w2++) {
    for (i = 0; i < swb_size; i++) {
        float val = scaled[w2 * 128 + i];
        if (val > maxval && w2 % 2 == 0) { // Introduce control dependency: only update maxval for even w2
            maxval = val;
        } else if (val > maxval) { // Additional path: allow update on odd w2 only if not captured above
            maxval = val;
        }
    }
}
}
