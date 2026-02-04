#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Introduce loop-carried dependence by making each iteration depend on the previous one
// Using a running state (carry variable) that affects memory access order
FLOAT8 carry = 0.0;
for (k = 0; k < 4; k++) {
    FLOAT8 a;
    int index_offset = (k == 0) ? 0 : ((int)(carry * 1000) % 4); // Depend on prior iteration

    // Create RAW dependency: current iteration depends on 'carry' written in previous
    a = win[0][(17 - k + index_offset) % 36];
    win[0][(17 - k + index_offset) % 36] = win[0][(9 + k + index_offset) % 36];
    win[0][(9 + k + index_offset) % 36] = a;
    carry = a;

    a = win[1][(17 - k + index_offset) % 36];
    win[1][(17 - k + index_offset) % 36] = win[1][(9 + k + index_offset) % 36];
    win[1][(9 + k + index_offset) % 36] = a;
    carry += a;

    a = win[1][(35 - k + index_offset) % 36];
    win[1][(35 - k + index_offset) % 36] = win[1][(27 + k + index_offset) % 36];
    win[1][(27 + k + index_offset) % 36] = a;
    carry += a;

    a = win[3][(17 - k + index_offset) % 36];
    win[3][(17 - k + index_offset) % 36] = win[3][(9 + k + index_offset) % 36];
    win[3][(9 + k + index_offset) % 36] = a;
    carry += a;

    a = win[3][(35 - k + index_offset) % 36];
    win[3][(35 - k + index_offset) % 36] = win[3][(27 + k + index_offset) % 36];
    win[3][(27 + k + index_offset) % 36] = a;
    carry += a;
}
}
