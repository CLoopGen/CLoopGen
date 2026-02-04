#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t mask;
extern int dots[16];
extern int x;
extern int c0_point;
extern int half_point;
extern int c3_point;
extern  int indexMap[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 8; x++) {
    int idx = indexMap[x] & 0x7; // Ensure index into valid range [0,7]
    int dot = dots[(idx * 2) % 16]; // Strided access with modulo to stay in bounds
    int bits = (dot < half_point ? 4 : 0) | (dot < c0_point ? 2 : 0) | (dot < c3_point ? 1 : 0);
    mask >>= 2;
    mask |= indexMap[bits];
}
}
