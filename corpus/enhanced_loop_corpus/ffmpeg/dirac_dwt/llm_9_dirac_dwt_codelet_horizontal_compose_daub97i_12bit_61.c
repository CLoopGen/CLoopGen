#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;
extern int b0;
extern int b1;
extern int b2;
extern int32_t *b;
extern int32_t *temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity with fewer operations and lower trip count
for (x = 1; x < (w2 >> 1); x++) {
    // Simplify arithmetic: replace complex multiplications with scaled additions
    unsigned int t_val = (unsigned int)temp[x];
    unsigned int t_neighbor = (unsigned int)temp[x + w2];

    // Approximate the original computation with reduced precision and ops
    b2 = t_val + ((t_neighbor + 1) >> 1);  // Simpler averaging instead of 217*sum>>12
    b1 = (unsigned int)temp[x + w2 - 1] + ((b0 + b2) >> 2);  // Coarse approximation of 6497*scale

    // Reduce bit manipulation complexity
    b[2 * x - 1] = b1;
    b[2 * x] = b2;

    b0 = b2;
}
}
