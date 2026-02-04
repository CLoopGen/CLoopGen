#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride pattern (stride of 2) and handling remainder
    for (r = 0; r < n; r += 2)
        for (s = 0; s < n; s += 2) {
            (*B)[r][s] = 0;
            if (r + 1 < n) (*B)[r + 1][s] = 0;
            if (s + 1 < n) (*B)[r][s + 1] = 0;
            if (r + 1 < n && s + 1 < n) (*B)[r + 1][s + 1] = 0;
        }
}
