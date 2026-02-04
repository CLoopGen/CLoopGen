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
    // Variant 2: Use consecutive memory access by transposing the inner computation
    // Precompute and store A's column t as a temporary vector to enable sequential reads
    double temp[2000];
    for (t = 0; t < n; ++t) {
        // Load column t of A into temp[] with unit stride (consecutive access)
        for (r = 0; r < n; ++r) {
            temp[r] = A[r][t];
        }
        // Now update B using consecutive access to temp[]
        for (r = 0; r < n; ++r) {
            for (s = 0; s < n; ++s) {
                (*B)[r][s] += temp[r] * temp[s];
            }
        }
    }
}
