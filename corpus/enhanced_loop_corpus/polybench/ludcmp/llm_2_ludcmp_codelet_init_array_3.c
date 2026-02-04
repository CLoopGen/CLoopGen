#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern int t;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to stride by 2 (strided access) with cleanup for odd n
    for (t = 0; t < n; t += 2) {
        for (r = 0; r < n; ++r) {
            for (s = 0; s < n; ++s) {
                // Access t and t+1 to encourage strided memory access
                if (t + 1 < n) {
                    (*B)[r][s] += A[r][t] * A[s][t] + A[r][t+1] * A[s][t+1];
                } else {
                    // Handle odd n: last iteration when t == n-1
                    (*B)[r][s] += A[r][t] * A[s][t];
                }
            }
        }
    }
}
