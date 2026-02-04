#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int k;
extern FLOAT8 *wp;
extern FLOAT8 *wr;
extern FLOAT8 w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
FLOAT8 local_sum = 0.0;
for (k = 0; k < 7; k++) {
    FLOAT8 val = *wp++;
    *wr++ = (val + val) / (w + w); // Two additions, two divisions worth of operations
    local_sum += val * w; // Extra floating-point operation to increase compute intensity
}
}
