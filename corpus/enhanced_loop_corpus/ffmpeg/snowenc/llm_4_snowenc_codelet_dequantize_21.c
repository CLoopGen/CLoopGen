#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *src;
extern int stride;
extern  int w;
extern  int h;
extern  int qmul;
extern  int qadd;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++) {
        int i = src[x + y * stride];
        int sign = (i >> 31); // Extract sign bit (assumes 32-bit int, negative -> all 1s)
        int abs_i = (i ^ sign) - sign; // Absolute value using bitwise trick
        int result = (abs_i * qmul + qadd) >> (11); // Common computation
        result = (result ^ sign) - sign; // Apply original sign to result
        src[x + y * stride] = result;
    }
}
}
