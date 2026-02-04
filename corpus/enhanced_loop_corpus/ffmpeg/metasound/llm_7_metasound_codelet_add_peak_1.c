#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float period;
extern int width;
extern  float *shape;
extern float ppc_gain;
extern float *speech;
extern int len;
extern int i;
extern int j;
extern int center;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_ppc = ppc_gain; // Break WAW on global ppc_gain by using local copy
    for (i = 1; i < (((len) >= 0 ? (len) + ((width) >> 1) : (len) - ((width) >> 1)) / (width)); i++) {
        center = (int)(i * period + 0.5);
        float *local_shape = &shape[(i-1) * width]; // Reindex shape to eliminate pointer arithmetic side effect
        for (j = 0; j < width; j++) { // Normalize inner loop bounds and indexing
            int read_idx = j;
            int write_idx = center - width/2 + j;
            speech[write_idx] = speech[write_idx] + local_ppc * local_shape[read_idx]; // Eliminate *shape++ (no WAR due to ++)
        }
    }
}
