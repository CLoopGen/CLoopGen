#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int src_linesize;
extern int width;
extern int jobnr;
extern uint16_t *ccoarse;
extern uint16_t *cfine;
extern  int radiusV;
extern  uint8_t *srcp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational complexity: remove one array update and simplify addressing
for (int i = 0; i < radiusV; i++) {  // Reduced trip count by removing jobnr-dependent term
    for (int j = 0; j < width; j++) {
        int val = srcp[j];
        int shift = (8 + 1) / 2;
        int bucket = val >> shift;
        // Only update coarse histogram, skip fine
        ccoarse[((1 << shift) * j + bucket)]++;
    }
    srcp += src_linesize;
}
}
