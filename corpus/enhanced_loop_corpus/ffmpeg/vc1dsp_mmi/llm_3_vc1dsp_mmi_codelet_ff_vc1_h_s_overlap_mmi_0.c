#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *left;
extern int16_t *right;
extern int left_stride;
extern int right_stride;
extern int flags;
extern int i;
extern int a;
extern int b;
extern int c;
extern int d;
extern int d1;
extern int d2;
extern int rnd1;
extern int rnd2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use consecutive memory layout assumption with local caching for spatial reuse
int16_t lbuf[16]; // Local buffer to capture accessed left elements
int16_t rbuf[16]; // Local buffer to capture accessed right elements

for (i = 0; i < 8; i++) {
    int li = 6 + i * left_stride;
    int ri = 0 + i * right_stride;
    
    // Prefetch values into local arrays (simulating blocked/tiled access)
    lbuf[i*2+0] = left[li];
    lbuf[i*2+1] = left[li + 1];
    rbuf[i*2+0] = right[ri];
    rbuf[i*2+1] = right[ri + 1];
}

// Now process the buffered data consecutively in a second pass
for (i = 0; i < 8; i++) {
    a = lbuf[i*2+0];
    b = lbuf[i*2+1];
    c = rbuf[i*2+0];
    d = rbuf[i*2+1];
    d1 = a - d;
    d2 = a - d + b - c;
    lbuf[i*2+0] = ((a << 3) - d1 + rnd1) >> 3;
    lbuf[i*2+1] = ((b << 3) - d2 + rnd2) >> 3;
    rbuf[i*2+0] = ((c << 3) + d2 + rnd1) >> 3;
    rbuf[i*2+1] = ((d << 3) + d1 + rnd2) >> 3;
    
    // Write back updated values using original strides
    left[6 + i * left_stride] = lbuf[i*2+0];
    left[7 + i * left_stride] = lbuf[i*2+1];
    right[0 + i * right_stride] = rbuf[i*2+0];
    right[1 + i * right_stride] = rbuf[i*2+1];

    if (flags & 1) {
        rnd2 = 7 - rnd2;
        rnd1 = 7 - rnd1;
    }
}
}
